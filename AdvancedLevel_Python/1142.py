Nv, Ne = list(map(int, input().split()))

graph = [[] for i in range(Nv)]

for i in range(Ne):
    tmp = list(map(int, input().split()))
    graph[tmp[1] - 1].append(tmp[0])
    graph[tmp[0] - 1].append(tmp[1])

M = int(input())

ans = []


def judge(tmp, graph):
    for i in range(len(tmp)):
        for j in range(i + 1, len(tmp)):
            if not tmp[j] in graph[tmp[i] - 1]:
                return 'Not a Clique'

    from functools import reduce
    if reduce(lambda x,y: x & y,[set(graph[point - 1]) for point in tmp]) - set(tmp):
        return 'Not Maximal'
    else:
        return 'Yes'

ans = []
for _ in range(M):
    tmp = list(map(int, input().split()))[1:]
    ans.append(judge(tmp, graph))

[print(_) for _ in ans]



