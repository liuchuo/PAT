#coperate with vohyz ,Python! Forever God!
l = input()
arr = list(map(int, input().split()))

k, b = 0, 0
for i in range(len(arr)):
    if arr[i]>0:
        if arr[i] != i:
            l = 2
            tmp = arr[i]
            while arr[tmp] != i and arr[tmp] != -1:
                index = tmp
                tmp = arr[tmp]
                arr[index] = -1
                l += 1
            arr[tmp] = -1
            k += 1
            b += l
if arr[0] == 0:
    print(b+k)
else:
    print(b+k-2)
