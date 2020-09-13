n, m = list(map(int, input().split()))

graph = [[101 for j in range(n)] for i in range(n)]

for i in range(m):
    tmp = list(map(int, input().split()))
    graph[tmp[0] -1 ][tmp[1] - 1] = tmp[2]
    graph[tmp[1] - 1][tmp[0] - 1] = tmp[2]

k = int(input())

ans = []

possible = []

for j in range(k):
    tmp =  list(map(int, input().split()))
    path = tmp[1:]
    city_set = [i+ 1 for i in range(n)]
    TotalDist = 0
    his = []
    is_simple = True
    is_Ts_cycle = True
    for i in range(len(path) - 1):
        if TotalDist != 'NA' and graph[path[i] - 1][path[i + 1] -1 ] <= 100:
            TotalDist += graph[path[i] - 1][path[i + 1] -1 ]
        else:
            TotalDist = 'NA'

        if path[i] in his:
            is_simple = False
        else:
            his.append(path[i])

    if path[0] != path[-1]:
        is_Ts_cycle = False
    his.append(path[0])

    if set(his) != set(city_set):
        is_Ts_cycle = False

    res = 'Path ' + str(j + 1) + ': ' + str(TotalDist) + ' '
    if is_Ts_cycle and TotalDist != 'NA':
        possible.append([j+1, TotalDist])
        if is_simple:
            res += '(TS simple cycle)'
        else:
            res += '(TS cycle)'
    else:
        res += '(Not a TS cycle)'

    ans.append(res)

[print(i) for i in ans]
possible.sort(key=lambda x:x[1])
print('Shortest Dist(' + str(possible[0][0]) +') = ' + str(possible[0][1]) )

