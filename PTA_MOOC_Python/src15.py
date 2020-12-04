length, n = input().split()
data = []
for i in range(int(n)):
    data.append(list(map(int, input().split())))
G = [[] for i in range(int(length))]

for edge in data:
    G[int(edge[0])].append(int(edge[1]))
    G[int(edge[1])].append(int(edge[0]))

for d in G: d.sort()

def DFS(start, ans, G):
    if not G[start] in ans: ans.append(start)
    else: return ans
    for i in G[start]:
        if not i in ans:
            ans = DFS(i, ans, G)
    return ans

def BFS(layer, ans, G):
    if not layer: return ans
    layer_ = []
    for node in layer:
        ans.append(node)
    for node in layer:
        for i in G[node]:
            if not i in ans:
                if not i in layer_: layer_.append(i)
    ans = BFS(layer_, ans, G)
    return ans

out1, out2 = [], []

for i in range(len(G)):
    index1 = True
    index2 = True
    G[i].sort()
    for subset in out1:
        if i in subset:
            index1 = False
    if index1:
        tmp1 = DFS(i, [], G)
        out1.append(tmp1)
    for s in out2:
        if i in s:
            index2 = False
    if index2:
        tmp2 = BFS([i], [], G)
        out2.append(tmp2)

left_ = '{ '
right_ = ' }'
for i in out1:
    print(left_ + ' '.join(list(map(str, i))) + right_)
for j in out2:
    print(left_ + ' '.join(list(map(str, j))) + right_)
