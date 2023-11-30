n = input().split()
data = []
ans = []
while len(n) != 1:
    case = []
    for i in range(int(n[1])+1):
        case.append(list(map(int, input().split())))
    data.append(case)
    n = input().split()

def judge(std, test):
    if not std and not test:return True
    if std[0] != test[0]:return False
    return judge([i for i in std[1:] if i < std[0]], [i for i in test[1:] if i < test[0]])\
           and judge([i for i in std[1:] if i > std[0]] , [i for i in test[1:] if i > std[0]])

for case in data:
    for i in range(len(case)):
        if not i == 0:
            if judge(case[0], case[i]):
                ans.append('Yes')
            else:
                ans.append('No')
for result in ans:
    print(result)