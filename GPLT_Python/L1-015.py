N = input().split()
m = int(N[0])
for i in range(round(m / 2, 0)):
    for j in range(m):
        print(N[-1], end='')
    print()
