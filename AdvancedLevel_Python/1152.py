n, k = list(map(int, input().split()))

num = int(input())

from math import sqrt
def is_prime(num):
    p = 2
    while p <= sqrt(num):
        if num % p == 0:
            return False
        else:
            p += 1
    return True

for i in range(len(str(num)) - k + 1):
    if is_prime(int(str(num)[i:i + k ])):
        print(str(num)[i:i + k ])
        exit(0)

print('404')
