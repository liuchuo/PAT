def get_prime(Msize):
    number = Msize

    def is_prime(number):
        for i in range(2, number):
            if number % i == 0:
                return False
        else:
            return True

    while 1:
        if is_prime(number):
            return number
        else:
            number += 1

Msize, M, N = list(map(int, input().split()))

arr = list(map(int, input().split()))

task = list(map(int, input().split()))

hashing = {}

Msize = get_prime(Msize)

def insert_hash(e, hashing):
    k = 1
    key = e % Msize
    if not key in hashing.keys():
        hashing[key] = e
        return [k]
    elif hashing[key] == e:
        return [k]
    else:
        success = False
        for i in range(1, Msize):
            key_tmp = (key + i ** 2) % Msize
            k += 1
            if not key_tmp in hashing.keys():
                hashing[key_tmp] = e
                success = True
                break
            elif hashing[key_tmp] != e :
                pass
            else:
                return [k]
        if not success :
            k += 1
            return k, str(e) + ' cannot be inserted.'
        else:
            return [k]

for e in arr:
    insert_hash(e, hashing)
ans = 0

for e in task:
    from copy import deepcopy
    hashing_ = deepcopy(hashing)
    tmp = insert_hash(e, hashing_)
    if len(tmp) > 1:
        print(tmp[1])
    ans += tmp[0]


from math import modf

a, b = modf(ans / len(task) * 10)

if a >= 0.5:
    print((b / 10 + 0.1))
else:
    print(b / 10)

