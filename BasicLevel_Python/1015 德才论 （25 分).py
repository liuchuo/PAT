from functools import cmp_to_key
# TODO: 样例2随机会过，样例3，4超时

N, L, H = tuple(map(int,input().split()))

dcqj = []   # 德才全尽
dsc = []    # 德胜才
dcjw_dsc = []   # 德才兼亡，德胜才
dx = [] # 达线

for i in range(N):
    l = input().split()
    de = int(l[1])
    ci = int(l[2])
    if de >= L and ci >= L:
        if de >= H and ci >= H:
            dcqj.append({'num':l[0], 'de':de, 'ci':ci})
        elif de >= H:
            dsc.append({'num':l[0], 'de':de, 'ci':ci})
        elif ci < H and de >=ci:
            dcjw_dsc.append({'num':l[0], 'de':de, 'ci':ci})
        else:
            dx.append({'num':l[0], 'de':de, 'ci':ci})

print(sum(map(len,[dcqj, dsc, dcjw_dsc, dx])))

def ccmp(x, y):
    t_x = x['de'] + x['ci']
    t_y = y['de'] + y['ci']

    if t_x == t_y:
        if x['de'] == y['de']:
            return int(x['num']) - int(y['num'])
        else:
            return y['de'] - x['de']
    else:
        return t_y - t_x

for i in [dcqj, dsc, dcjw_dsc, dx]:
    for j in sorted(i, key=cmp_to_key(ccmp)):
        print(j['num'], j['de'], j['ci'])