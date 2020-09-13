def read():
    return list(map(int, input().split()))
global n
n, k = read()
global Top
Top = 633533444

G = [[Top for j in range(n)] for i in range(n)]
data = {}
atab = {}
table = []
for i in range(k):
    input_ = read()
    table.append(input_)
    if not input_[0]-1 in data.keys():
        data[input_[0]-1] = [[input_[1]-1, input_[2]]]
    else:
        data[input_[0]-1].append([input_[1]-1, input_[2]])

    if not input_[1]-1 in atab.keys():
        atab[input_[1]-1] = [[input_[0]-1, input_[2]]]
    else:
        atab[input_[1]-1].append([input_[0]-1, input_[2]])

    G[input_[0]-1][input_[1]-1] = input_[2]

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
    if not layer_rn: print(0);exit(0)
    tmp = []
    if layer_pre:
        for son in layer_rn:
            val_son = {}
            for node in layer_pre:
                if G[node][son] != Top:
                    val_son[str(node+1) + '->' + str(son+1)] = G[node][son] + time_schedule[node]
            time_schedule[son] = max(val_son.values())
    else:
        for son in layer_rn:
            time_schedule[son] = 0
    his += layer_rn
    for i in layer_rn:
        if i in data.keys(): del data[i]
    layer_pre = layer_rn

min_time = max(time_schedule.values())

ddl_schedule = {}

def get_degree_T(node_list, atab):
    degree = []
    for node in node_list:
        tmp = 0
        for edges in atab.values():
            for edge in edges:
                if edge[0] == node:
                    tmp -= 1
        degree.append(tmp)
    return degree

his_T = []
layer_post = []

while len(his_T) < n:
    degree = get_degree_T(node_list, atab)
    layer_rn = [i for i in range(len(degree)) if degree[i] == 0 and (not i in his_T)]
    if not layer_rn: print(0);exit(0)
    tmp = []
    if layer_post:
        for son in layer_rn:
            val_son = {}
            for node in layer_post:
                if G[son][node] != Top:
                    val_son[str(node+1) + '->' + str(son+1)] = ddl_schedule[node] - G[son][node]
            ddl_schedule[son] = min(val_son.values())
    else:
        for son in layer_rn:
            ddl_schedule[son] = min_time
    his_T += layer_rn
    for i in layer_rn:
        if i in atab.keys(): del atab[i]
    layer_post = layer_rn

output = []

for edge in table[::-1]:
    if time_schedule[edge[0]-1] + G[edge[0]-1][edge[1]-1] == ddl_schedule[edge[1]-1]:
        output.append(str(edge[0])+'->'+str(edge[1]))

output.sort(key=lambda x:int(x.split('-')[0]))
#print(output)
print(min_time)

[print(o) for o in output]
