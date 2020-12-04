n = int(input())
data = input().split()
i = 0
code = dict()
while i + 1 <= len(data):
    code[data[i]] = int(data[i+1])
    i += 2
k = int(input())
test_list = []

for i in range(k):
    tmp_dict = dict()
    for j in range(n):
        tmp = input().split()
        tmp_dict[tmp[0]] = tmp[1]
    test_list.append(tmp_dict)

def get_WPL(code, test=None):
    WPL = 0
    if not test:
        ans = []
        tmp = 0
        nums = list(code.values())
        nums.sort(reverse=True)
        while nums:
            tmp = 0
            tmp += nums.pop()
            if not nums:
                break
            tmp += nums.pop()
            nums.append(tmp)
            nums.sort(reverse=True)
            ans.append(tmp)
        return sum(ans)
    for key in test.keys():
       WPL += len(test[key]) * code[key]
    return WPL

def is_conflict(case):
    tmp = list(case.values())
    tmp.sort(key=lambda x:len(x))
    #print(tmp)
    for i in range(len(tmp) - 1):
        for j in range(i+1, len(tmp)):
            #print(tmp[i], tmp[j][:len(tmp[i])])
            if tmp[i] == tmp[j][:len(tmp[i])]:

                return False
    return True

ground_truth = get_WPL(code)
for case in test_list:
    if get_WPL(code, case) != ground_truth:
        print('No')
        continue
    if not is_conflict(case):
        print('No')
        continue
    print('Yes')