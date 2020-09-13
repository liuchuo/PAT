n = input()

import math

def is_prime(x):
    if x < 3: return x > 1

    for i in range(2, int(math.sqrt(x)) + 1):
        if x % i == 0:
            return False
    else:
        return True

all_prime = True
for i in range(len(n)):
    tmp = n[i:]
    if is_prime(int(tmp)):
        print(tmp + ' ' + 'Yes')
    else:
        print(tmp + ' ' + 'No')
        all_prime = False

if all_prime:
    print('All Prime!')


