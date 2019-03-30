import math


def funx(x):
    k = 1
    for i in range(2, int(math.sqrt(x)) + 1):
        if x % i == 0:
            k = 0
    if x == 1:
        k = 0
    return k


N = int(input())
M = []
for i in range(N):
    temp = int(input())
    M.append(funx(temp))
for i in M:
    if i == 1:
        print('Yes')
    else:
        print('No')
