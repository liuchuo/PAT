def read():
    return list(map(int, input().split()))

global d
n, d = read()
G = []
for i in range(int(n)):
    G.append(read())

from math import sqrt

def get_distance(a, b): return sqrt((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2)

def is_safe(vector):
    if vector[0] + d >= 50 or vector[0] - d <= -50 or vector[1] + d >= 50 or vector[1] - d <= -50:
        return True
    else: return False

def BFS(layer, his, path, G):
    if not layer: return
    his += layer
    layer_ = []
    path_ = {}
    for node in layer:
        for p in range(len(G)):
            if not p in his:
                if get_distance(G[node], G[p]) <= d:
                    layer_.append(p)
                    if not str(p) in path_.keys():
                        path_[str(p)] = path[str(node)] + [p]
                    else:
                        pre = G[path_[str(p)][0]]
                        post = G[node]
                        if get_distance([0,0], post) < get_distance([0,0], pre):
                            path_[str(p)] = path[str(node)] + [p]
    return layer_, his, path_

def get_ans(G):
    ans = []
    for i in range(len(G)):
        if is_safe(G[i]):
            ans.append(i)
    return ans

def get_layer(G):
    layer = []
    for i in range(len(G)):
        if get_distance([0,0], G[i]) <= d + 7.5:
            layer.append(i)
    return layer

ans, layer = get_ans(G), get_layer(G)

for p in layer:
    if p in ans:print(1);exit(0)

if not ans or not layer:print(0);exit(0)

his, path = [], {str(i):[i] for i in layer}
cycle = True

while layer and cycle:
    layer, his, path = BFS(layer, his, path, G)
    result = []
    for p in layer:
        if p in ans:
            tmp = [G[i] for i in path[str(p)]]
            result.append(tmp)
            cycle = False

if not result:print(0);exit(0)

print(len(result[0]) + 1)

result.sort(key = lambda x:get_distance([0,0],x[0]))

for i in result[0]:
    print(' '.join(list(map(str, i))))