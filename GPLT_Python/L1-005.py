N = int(input())
a = []
b = []
c = []
for i in range(N):
    temp = input().split()
    a.append(temp[0])
    b.append(int(temp[1]))
    c.append(temp[2])
M = int(input())
d = input().split()
for i in d:
    k = b.index(int(i))
    print(a[k], end=' ')
    print(c[k])
