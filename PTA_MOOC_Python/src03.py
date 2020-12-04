a = input()
b = input()

def data_process(a):
    ans = []
    d = dict()
    a = a.split()
    del a[0]
    for i in range(int(len(a) / 2)):
        ans.append([a[2 * i], a[2 * i + 1]])
        d[str(a[2 * i + 1])] = a[2 * i]
    return ans, d


ans1, d1 = data_process(a)

ans2, d2 = data_process(b)


def add(d1, d2):
    x = list(set([i for i in d1.keys()] + [i for i in d2.keys()]))
    d_new = dict()

    for i in x:
        d_new[i] = 0
        if i in d1.keys():
            d_new[i] += int(d1[i])

        if i in d2.keys():
            d_new[i] += int(d2[i])

    return d_new

def mult(d1, d2):
    ans = []
    for i in d1:
        for j in d2:
            ans.append([str(int(i[1]) + int(j[1])), str(int(i[0]) * int(j[0]))])
    dictory = dict()
    for e in ans:
        try:
            dictory[e[0]] += int(e[1])
        except:
            dictory[e[0]] = int(e[1])
    return dictory

res1, res2 = mult(ans1, ans2), add(d1, d2)


keys1 = list(map(int, list(res1.keys())))
keys1.sort(reverse=True)
out1 = ''
for k in keys1:
    if res1[str(k)] == 0:
        pass
    else:
        out1 += str(res1[str(k)])
        out1 += ' '
        out1 += str(k)
        out1 += ' '
out1 = out1[:len(out1) -1]

if not out1:
    print('0 0')
else:
    print(out1)
keys2 = list(map(int, list(res2.keys())))
keys2.sort(reverse=True)
out2 = ''
for k in keys2:
    if res2[str(k)] == 0:
        pass
    else:
        out2 += str(res2[str(k)])
        out2 += ' '
        out2 += str(k)
        out2 += ' '
out2 = out2[:len(out2) -1]
if not out2:
    print('0 0')
else:
    print(out2)

