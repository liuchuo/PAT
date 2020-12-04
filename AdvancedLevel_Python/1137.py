P, M, N = list(map(int, input().split()))

Gp = {}

for i in range(P):
    tmp = input().split()
    Gp[tmp[0]] = int(tmp[1])

Gm = {}

for i in range(M):
    tmp = input().split()
    Gm[tmp[0]] = int(tmp[1])

Gf = {}

for i in range(N):
    tmp = input().split()
    Gf[tmp[0]] = int(tmp[1])

list_of_names = {}

for name in Gp.keys():
    if Gp[name] >= 200:
        list_of_names[name] = str(Gp[name])

for name in list_of_names:
    if not name in Gm: Gm[name] = -1
    if not name in Gf: Gf[name] = -1
    if max(round((Gm[name]*2 + Gf[name]*3) / 5), Gf[name]) >= 60:
        list_of_names[name] = [list_of_names[name], Gm[name], Gf[name], max(round((Gm[name]*2 + Gf[name]*3) / 5), Gf[name])]

ans = []

for key in list_of_names.keys():
    if len(list_of_names[key]) == 4:
        ans.append([key] + list_of_names[key])

ans.sort(key=lambda x:(-x[4], x[0] ))

for student in ans:
    print(' '.join(list(map(str, student))))
