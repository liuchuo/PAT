data = []
for i in range(2):
    tmp = input()
    data.append(tmp)

if not data[1]:exit(0)

array = list(map(int, data[1].split(' ')))

s, tmp = 0, 0

for i in array:
    tmp += i
    if tmp > s:
        s = tmp
    elif tmp < 0:
        tmp = 0

print(max(s,0))

