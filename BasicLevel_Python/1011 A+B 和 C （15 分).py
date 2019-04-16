N = int(input())

for i in range(N):
    a, b, c = tuple(map(int,input().split()))

    if a+b > c:
        print("Case #{}: true".format(int(i+1)))
    else:
        print("Case #{}: false".format(int(i+1)))