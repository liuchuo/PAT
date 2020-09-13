def read():
    return list(map(int, input().split()))

n, k = read()
if k < n - 1:print(-1);exit(0)
G = [[63353 for j in range(n)] for i in range(n)]
for i in range(k):
    data = read()
    G[data[0]-1][data[1]-1] = data[2]
    G[data[1]-1][data[0]-1] = data[2]

def Dsk(s,G):
    path = [s]
    ans = 0
    while not len(path) == n:
        room = [min([[G[node][i],i] for i in range(len(G[node])) if not i in path]) for node in path]
        room.sort(key = lambda x:x[0])
        path.append(room[0][1])
        ans += room[0][0]
    return ans

res = Dsk(s=0,G=G)
print(-1 if res > 63353 else res)
