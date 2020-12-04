n = int(input())

monsry = {}

for i in range(n):
    tmp = input().split()
    if tmp[0] in monsry.keys():
        monsry[tmp[0]][0] += 1
    else:
        monsry[tmp[0]] = [1,tmp[0]]
    if tmp[1] in monsry.keys():
        monsry[tmp[1]][0] += 1
    else:
        monsry[tmp[1]] = [1, tmp[1]]

top = max(monsry.values(), key = lambda x:x[0])

c = list(map(int, [p[1] for p in monsry.values() if p[0] == top[0]]))
res = str(min(c)) + ' ' + str(top[0])

if len(c) > 1:
    print(res + ' ' + str(len(c)))
else:
    print(res)