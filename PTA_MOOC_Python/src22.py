def read():
    return list(map(int, input().split()))
global n
n, k = read()
G = [[63353 for j in range(n)] for i in range(n)]
data = {}

for i in range(k):
    input_ = read()
    if not input_[0] in data.keys():
        data[input_[0]] = [input_[1:]]
    else:
        data[input_[0]].append(input_[1:])
    G[input_[0]][input_[1]] = input_[2]

def get_degree(node_list, data):
    degree = []
    for node in node_list:
        tmp = 0
        for edges in data.values():
            for edge in edges:
                if edge[0] == node:
                    tmp -= 1
        degree.append(tmp)
    return degree

node_list = [i for i in range(n)]
his = []
layer_pre = []
time_schedule = {}
while len(his) < n:
    degree = get_degree(node_list, data)
    layer_rn = [i for i in range(len(degree)) if degree[i] == 0 and (not i in his)]
    if not layer_rn: print('Impossible');exit(0)
    tmp = []
    if layer_pre:
        for son in layer_rn:
            val_son = []
            for node in layer_pre:
                if G[node][son] != 63353:
                    val_son.append(G[node][son] + time_schedule[node])
            time_schedule[son] = max(val_son)
    else:
        for son in layer_rn:
            time_schedule[son] = 0
    his += layer_rn
    for i in layer_rn:
        if i in data.keys(): del data[i]
    layer_pre = layer_rn

print(max(time_schedule.values()))
