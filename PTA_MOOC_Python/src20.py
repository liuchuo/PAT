n, m, s, d = list(map(int, input().split()))
edge = []
for i in range(m):edge.append(list(map(int, input().split())))
global TOP
TOP = n*500+1
G, G_ = [[TOP for j in range(n)]for i in range(n)],[[n*500+1 for j in range(n)]for i in range(n)]

for e in edge:
    G[e[0]][e[1]], G[e[1]][e[0]] = e[2], e[2]
    G_[e[0]][e[1]], G_[e[1]][e[0]] = e[3], e[3]

def Dsk(s,d,G):
    dis = [i for i in G[s]]
    cost = [j for j in G_[s]]
    path = [s]
    while not len(path) == n:
        index = dis.index(min([i for i in dis if not i in path]))
        path.append(index)
        for i in range(len(dis)):
            if i != s and not i in path:
                if G[index][s] + G[index][i] < dis[i]:
                    dis[i] = G[index][s] + G[index][i]
                    cost[i] = G_[index][s] + G_[index][i]
                elif G[index][s] + G[index][i] == dis[i] and cost[i] > G_[index][s] + G_[index][i]:
                    cost[i] = G_[index][s] + G_[index][i]

    return dis[d],cost[d]

shortcut,c = Dsk(s,d,G)
print(shortcut, c)