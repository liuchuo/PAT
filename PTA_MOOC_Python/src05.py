[depth, n, k] = list(map(int, input().split()))

data = []

for i in range(k):
    data.append(list(map(int, input().split())))

def interop(nums, tmp):
    tmp.append(nums.pop())

for i in data:
    tmp = []
    nums = [o+1 for o in range(n)][::-1]
    process = True
    for e in i:
        while nums or tmp:
            #print(nums, tmp, e)
            if not tmp:interop(nums, tmp)
            if tmp[-1] == e:
                tmp.pop()
                break
            else:
                if not nums:
                    print('NO')
                    process = False
                    break
                elif len(tmp) >= depth:
                    print('NO')
                    process = False
                    break
                else:
                    interop(nums, tmp)
        if not process:break
    if process:print('YES')

