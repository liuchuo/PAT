[address0, length, k] = input().split()
length, k = int(length), int(k)
mass = {}

for i in range(length):
    data = input().split()
    mass[data[0]] = [data[1], data[2]]

address = mass[address0][1]
array = [[address0] + mass[address0]]

while address != '-1' :
    array.append([address] + mass[address])
    address = mass[address][1]

k_ = int(len(array) / k)
index = 0
ans = []
for i in range(k_):
    ans += [j for j in array[index:index + k][::-1]]
    index += k

ans += array[k * k_:]

for i in range(len(ans) - 1):
    ans[i][2] = ans[i+1][0]

ans[-1][2] = '-1'

for e in ans:
    print(' '.join(e))
