start, n, k = input().split()

data = {}

for i in range(int(n)):
    tmp = input().split()
    data[tmp[0]] = [int(tmp[1]), tmp[2]]

data_pro = []

p = start

while p != '-1':
    data_pro.append([p] + data[p])
    p = data[p][1]

ne = []
po = []
gr_k = []

for i in data_pro:
    if i[1] < 0:
        ne.append(i)
    elif i[1] > int(k):
        gr_k.append(i)
    else:
        po.append(i)

ans = ne + po + gr_k

for i in range(len(data_pro) - 1):
    tmp = str(ans[i][0]) + ' ' + str(ans[i][1]) + ' ' + str(ans[i + 1][0])
    print(tmp)

print(str(ans[-1][0]) + ' ' + str(ans[-1][1]) + ' ' + '-1')
