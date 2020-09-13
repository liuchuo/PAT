[a,bottom,top] = list(map(int, input().split()))

sages, noble, fool, rest = [], [], [], []
result = [sages, noble, fool,rest]

for i in range(a):
    man = list(map(int, input().split()))

    if man[1] >= top and man[2] >= top:
        sages.append(man+[man[2]+man[1]])
    elif man[2] < top and man[1] >= top and man[2] >= bottom:
        noble.append(man+[man[2]+man[1]])
    elif man[1] < top and man[2] < top and man[1] >= man[2] and man[2] >= bottom:
        fool.append(man+[man[2]+man[1]])
    elif man[1] >= bottom and man[2] >= bottom:
        rest.append(man+[man[2]+man[1]])
k = 0

for i in result:k+= len(i)

print(k)

for group in result:
    group.sort(key = lambda x:(x[1] + x[2]) * 100 + x[1] - x[0] * 0.000000001, reverse=True)
    for i in range(len(group)):
       print(' '.join(str(ele) for ele in group[i][0:3]))
