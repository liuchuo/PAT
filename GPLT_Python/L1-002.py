import math

N, a = input().split()
N = int(N)
k = int(math.sqrt((N + 1) / 2))
for i in range(2 * k - 1):
    if i < k:
        for j in range(i):
            print(' ', end='')
        for m in range(2 * (k - i) - 1):
            print(a, end='')
        print('')
    else:
        for j in range(2 * k - i - 2):
            print(' ', end='')
        for m in range(2 * (i - k + 1) + 1):
            print(a, end='')
        print('')
print(N - 2 * k ** 2 + 1)