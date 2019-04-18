def callatz(n):
    t = set()
    while n != 1 :
        t.add(n)
        if n % 2 == 0:
            n /= 2
        else:
            n = (n*3+1)/2
    return t

input()
l = list(map(int,set(input().split())))

ts = set()
tl = []

for i in l:
    ss = callatz(i)
    if ts.issubset(ss):
        ts = ss
        tl = [i]
    elif ts.issuperset(ss):
        continue
    else:
        for j in tl:
            if callatz(j).issubset(ss):
                tl.remove(j)
        ts |= ss
        tl.append(i)

tl = sorted(tl, reverse=True)
print(' '.join(str(x) for x in tl))