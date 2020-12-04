n = int(input())
oper = []
for i in range(2 * n):
    oper.append(input().split())
#preli = [(i + 1) for i in range(n)]
inli = []
tmp = []
preli = []
for i in oper:
    if i[0] == 'Push':
        preli.append(int(i[1]))
        tmp.append(int(i[1]))
    if i[0] == 'Pop':
        inli.append(tmp.pop())

def cycle(preli, inli):
    if not preli:
        return []
    if len(preli) == 1:
        return preli
    key = inli.index(preli[0])
    return cycle(preli[1:key+1], inli[:key]) + cycle(preli[key+1:], inli[key+1:]) + [preli[0]]

ans = cycle(preli, inli)
c = list(map(str, ans))
print(' '.join(c))
