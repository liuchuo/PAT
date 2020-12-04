def read():
    return list(map(int, input().split()))
global d
n, d = read()
G = []
for i in range(int(n)):
    G.append(read())

from math import sqrt
def get_distance(a, b):
    return sqrt((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2)

def is_safe(vector):
    if vector[0] + d >= 50 or vector[0] - d <= -50 or vector[1] + d >= 50 or vector[1] - d <= -50:
        return True
    else: return False

def BFS(layer, his, G):
    if not layer: return
    his += layer
    layer_ = []
    for node in layer:
        for p in range(len(G)):
            if not p in his:
                if get_distance(G[node], G[p]) <= d:
                    layer_.append(p)
    return layer_, his

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

ans = get_ans(G)
layer = get_layer(G)

for p in layer:
    if p in ans:
        print('Yes')
        exit(0)
if not ans or not layer:
    print('No')
    exit(0)
his = [layer[0]]
while layer:
    layer, his = BFS(layer, his, G)
    for p in layer:
        if p in ans:
            print('Yes')
            exit(0)
print('No')
