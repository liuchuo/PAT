n = int(input())

arr_o = list(map(int, input().split()))

arr_n= list(map(int, input().split()))

def next_insert_sort(i, tmp, arr_o):
    ans = deepcopy(tmp)
    for j in range(len(ans)):
        if arr_o[i] < ans[j]:
            ans.insert(j, arr_o[i])
            return ans
    ans.append(arr_o[i])
    return ans

def next_merge_sort(i, now):
    def merge(arr1, arr2):
        tmp = arr1 + arr2
        tmp.sort()
        return tmp
    import math
    step = int(math.pow(2, i-1))
    tmp = []
    for j in range(0, len(now), step * 2):
        tmp += merge(now[j:j+step], now[j+step:j+step*2])
    return tmp

tmp1 = []
from copy import deepcopy
tmp2 = deepcopy(arr_o)
is_insert = False
is_merge = False

for i in range(1, n):
    tmp1 = next_insert_sort(i-1, tmp1, arr_o)

    tmp2 = next_merge_sort(i, tmp2)

    if is_insert:
        print(' '.join(list(map(str, tmp1 + arr_o[i:]))))
        exit(0)
    if is_merge:
        print(' '.join(list(map(str, tmp2))))
        exit(0)
    if tmp1 + arr_o[i:] == arr_n:
        print('Insertion Sort')
        is_insert = True
    if tmp2 == arr_n:
        print('Merge Sort')
        is_merge = True




