n = int(input())

for i in range(n):
    tmp = input()
    left, right = int(tmp[:len(tmp)//2]), int(tmp[len(tmp)//2:])
    if left == 0 or right == 0:
        print('No')
    elif int(tmp) % (left * right) == 0:
        print('Yes')
    else:
        print('No')
