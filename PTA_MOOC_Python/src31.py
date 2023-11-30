m, _ = list(map(int, input().split()))

seq = list(map(int, input().split()))

prime = 0
if m == 1: prime = 2;
else:
    import math
    while True:
        f=True
        a=2
        while a<=int(math.sqrt(m)):
            if m%a==0:
                f=False
                break
            a+=1
        if f:
            prime = m
            break
        m += 1

array = {}
res = []

for i in seq:
    key = i % prime
    if key not in array.keys():
        array[key] = i
        res.append(key)
    else:
        a = 1
        over = False
        j = 0
        while j <= prime:
            j += 1
            if (key + a) % prime not in array.keys():
                array[(key + a)%prime] = i
                res.append(int((key + a) % prime))
                over = True
                break
            if not over:
                a = (math.sqrt(a) + 1) ** 2
        if not over: res.append('-')
from functools import reduce
print(reduce(lambda x,y:str(x)+' '+str(y), res))