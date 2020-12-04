length, n = input().split()
data = []
for i in range(int(n)):
    data.append(list(map(int, input().split())))
G = [[] for i in range(int(length))]

for edge in data:
    G[int(edge[0])-1].append(int(edge[1])-1)
    G[int(edge[1])-1].append(int(edge[0])-1)

for d in G: d.sort()

def BFS(layer, ans, G, k):
    #print(layer, ans, k)
    if k > 6:return ans
    if not layer: return ans
    layer_ = []
    for node in layer:
        ans.append(node)
    for node in layer:
        for i in G[node]:
            if not i in ans:
                if not i in layer_: layer_.append(i)
    k += 1
    ans = BFS(layer_, ans, G, k)
    return ans

out = []
for i in range(len(G)):
    tmp = BFS([i], [], G, 0)
    out.append(len(tmp) / int(length))

for i in range(len(out)):
    print(str(i+1)+ ': '+'%.2f'%(out[i] * 100)+ '%')
