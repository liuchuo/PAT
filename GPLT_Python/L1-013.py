def fun(x):
    if x == 0:
        return 1
    else:
        return x * fun(x - 1)


N = int(input())
temp = 0
for i in range(N):
    temp = temp + fun(i + 1)
print(temp)
