length, n = list(map(int, input().split()))

edges = []

for i in range(n):
    edges.append(list(map(int, input().split())))

k = int(input())

ans = []

for i in range(k):
    tmp = list(map(int, input().split()))[1:]
    index = True
    for edge in edges:
        if (edge[0] not in tmp) and (edge[1] not in tmp):
            index = False
            break
    if index: ans.append('Yes')
    else: ans.append('No')

[print(i) for i in ans]
