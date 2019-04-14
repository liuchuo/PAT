N = int(input())

flag = [1]*(N+2)
flag[0] = flag[1] = 0
result = []

for i in range(2,N+1):
    if flag[i]:
        result.append(i)
        p = 2
        while i*p <= N:
            flag[i*p] = 0
            p += 1

c = 0
for i in range(len(result)-1):
    if (result[i+1] - result[i]) == 2:
        c += 1

print(c)