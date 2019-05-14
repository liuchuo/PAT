n = int(input())

d = {}
l = []

for i in range(n):
    a = input().split()
    d[int(a[2])] = a[0] + ' ' + a[1]
    l.append(int(a[2]))

print(d[max(l)])
print(d[min(l)])