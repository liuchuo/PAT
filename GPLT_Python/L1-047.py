N = int(input())
for i in range(N):
    temp = input().split()
    if 15 <= int(temp[1]) <= 20 and 50 <= int(temp[2]) <= 70:
        pass
    else:
        print(temp[0])
