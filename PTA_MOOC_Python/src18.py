length, n = list(map(int, input().split()))
edge = []

for i in range(n):
    edge.append(list(map(int, input().split())))
top = 100 * length +1
G = [[top for i in range(length)] for i in range(length)]

for e in edge:
    G[e[0]-1][e[1]-1] = e[2]
    G[e[1] - 1][e[0] - 1] = e[2]

for i in range(length):
    for j in range(length):
        for k in range(length):
            if i != j:
                if G[i][j] > G[i][k] + G[k][j]:
                    G[i][j] = G[i][k] + G[k][j]

ans = []

for i in range(len(G)):
    tmp = [j for j in G[i] if j != top]
    if not tmp: pass
    elif len(tmp) == length - 1:
        ans.append(max(tmp))

if not ans: print(0);exit(0)
c = min(ans)
index = ans.index(c)
print(index+1, c)