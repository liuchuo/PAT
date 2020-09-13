k = int(input())

nums = list(map(int, input().split()))

max_arr = []
max_ = 0

tmp = 0
tmp_arr = []

for i in range(len(nums)):

    if tmp > 0:
        tmp += nums[i]

        tmp_arr.append(nums[i])
    else:
        tmp = nums[i]

        tmp_arr = [tmp]

    if tmp >= max_:
        max_ = tmp

    from copy import deepcopy

    max_arr.append(deepcopy(tmp_arr))

if max_ > 0:
    for arr in max_arr:
        if sum(arr) == max_:
            print(max_, arr[0], arr[-1])
            exit(0)
else:
    print(0, nums[0], nums[-1])
