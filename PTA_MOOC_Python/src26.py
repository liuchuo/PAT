Heap = False
Insertion = False

def heapify(arr, n, i):
    largest = i
    l = 2 * i + 1  # left = 2*i + 1
    r = 2 * i + 2  # right = 2*i + 2

    if l < n and arr[i] < arr[l]:
        largest = l

    if r < n and arr[largest] < arr[r]:
        largest = r

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # 交换

        heapify(arr, n, largest)

def Sort(arr, arr2, indict, Heap, Insertion):
    n = len(arr2)
    for i in range(n, -1, -1):
        heapify(arr2, n, i)
    FUCK = n - 1
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

        if FUCK >= 0:
            arr2[FUCK], arr2[0] = arr2[0], arr2[FUCK]  # 交换
            heapify(arr2, FUCK, 0)
            FUCK -= 1
        #print(arr)
        #print(arr2)

        if Heap or Insertion:
            if Heap:
                print('Heap Sort')
                print(' '.join(list(map(str, arr2))))
                exit(0)
            elif Insertion:
                print('Insertion Sort')
                print(' '.join(list(map(str, arr))))
                exit(0)
        else:
            if arr == indict:
                Insertion = True
            if arr2 == indict:
                Heap = True

n = int(input())
arr = list(map(int, input().split()))
arr2 = arr.copy()
indict = list(map(int, input().split()))
seq = arr.copy()

Sort(arr, arr2, indict,Heap,Insertion)

