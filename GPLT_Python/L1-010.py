N = input().split()
a = []
for i in N:
    a.append(int(i))
a = sorted(a)
for i in range(3):
    if i == 2:
        print(a[i])
    else:
        print(a[i], end='->')