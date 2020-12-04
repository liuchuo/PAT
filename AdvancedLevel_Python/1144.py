n = input()

arr = list(map(int, input().split()))
k = 1
while 1:
    if not k in arr:
        print(k)
        exit(0)
    else:
        k += 1

