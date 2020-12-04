n, p, r = list(map(float, input().split()))

arr = list(map(int, input().split()))

root = arr.index(-1)

k = 0
start = 0
k_list = []
his = []

k_array = [-2 for i in range(int(n))]

for i in range(int(n)):
    if i not in his:
        k = 0
        next_node = i
        his.append(next_node)
        while next_node != -1:
            next_node = arr[next_node]
            if k_array[next_node] != -2:
                k += 1
                k += k_array[next_node]
                break
            else:
                k += 1
            his.append(next_node)
        k_array[i] = k
        k_list.append(k)

from math import pow

top = max(k_list)

ans = pow(1 + 0.01*r, top-1) * p

k = 0
for i in k_list:
    if i == top:
        k += 1

from math import modf

a, b = modf(ans * 100)

if a >= 0.5:
    print(str((b+1) / 100) +' ' + str(k) )
else:
    print(str(b / 100) +' ' + str(k))

