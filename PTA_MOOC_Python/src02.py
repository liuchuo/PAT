data = []
for i in range(2):
    tmp = input()
    data.append(tmp)

if not data[1]:exit(0)

array = list(map(int, data[1].split(' ')))

array = array[::-1]

ans, tmp_arr = [], []

s, tmp = 0, 0

if max(array) < 0:
    print(0, array[-1], array[0])
    exit(0)

elif max(array) == 0:
    print(0, 0, 0)
    exit(0)


for i in array:
    tmp += i
    tmp_arr.append(i)
    if tmp >= s:
        s = tmp
        ans = tmp_arr[:]
    elif tmp < 0:
        tmp = 0
        tmp_arr = []


while ans[0] == 0 or ans[-1] == 0:
    if ans[0] == 0:ans.pop(0)
    else:ans.pop()

print(s, ans[-1], ans[0])
