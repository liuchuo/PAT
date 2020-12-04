def myread():
    return list(map(int, input().split()))


n, m, k = myread()

graph = [[-1 for i in range(n)] for j in range(n)]

for i in range(m):
    tmp = myread()
    graph[tmp[0] - 1][tmp[1] - 1 ] = 1
    graph[tmp[1] - 1][tmp[0] - 1] = 1

query = myread()


def wander(graph, bad, his):

    total = []

    def walk(graph, s, bad, his):
   
        his.append(s)
        tmp = [s]
        layer = [s]
        while layer:
            next_layer = []
            for node in layer:
                for i in range(n):
                    if graph[node][i] == 1 and i not in his and i != bad and i not in layer:
                        next_layer.append(i)
                        his.append(i)
                        tmp.append(i)
            layer = next_layer

        return tmp

    for i in range(n):
        if i != bad and i not in his:
            total.append(walk(graph, i, bad, his))

    return len(total) - 1 if len(total) >= 1 else 0


for ruined_city in query:
    his = []
    print(wander(graph, ruined_city - 1, his))


