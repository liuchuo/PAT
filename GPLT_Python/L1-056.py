N = int(input())
a = []
b = []
for i in range(N):
    temp = input().split()
    a.append(temp[0])
    b.append(int(temp[-1]))
mean2 = sum(b) / 2 / N
m = abs(int(b[0]) - mean2)
k = 0
for i in range(N):
    if abs(int(b[i]) - mean2) < m:
        m = abs(int(b[i] - mean2))
        k = i
print(str(int(mean2)) + ' ' + a[k])
