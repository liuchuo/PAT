s = list(input().split())

l =[]
for k,i in enumerate(s):
    for j in range(int(i)):
        l.append(str(k))

o = []

cnt = 0
for i in l:
    if i == '0':
        cnt += 1
        continue
    elif len(o) == 0:
        o.append(i)
        while cnt > 0:
            o.append('0')
            cnt -= 1
    else:
        o.append(i)

print(''.join(o))