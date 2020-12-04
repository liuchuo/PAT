Merge = False
Insertion = False
def merge(seq, low, mid, high):
    left = seq[low: mid]
    right = seq[mid: high]
    k = 0
    j = 0
    result = []
    while k < len(left) and j < len(right):
        if left[k] <= right[j]:
            result.append(left[k])
            k += 1
        else:
            result.append(right[j])
            j += 1
    result += left[k:]
    result += right[j:]
    seq[low: high] = result

def Sort(arr, arr2, indict, Merge, Insertion):
    FUCKYOU = 1
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

        if FUCKYOU < len(arr2):
            low = 0
            while low < len(arr2):
                mid = low + FUCKYOU  # mid前后均为有序
                high = min(low + 2 * FUCKYOU, len(arr2))
                if mid < high:
                    merge(arr2, low, mid, high)
                low += 2 * FUCKYOU
            FUCKYOU *= 2

        #print(arr)
        #print(arr2)

        if Merge or Insertion:
            if Merge:
                print('Merge Sort')
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
                Merge = True

n = int(input())
arr = list(map(int, input().split()))
arr2 = arr.copy()
indict = list(map(int, input().split()))
seq = arr.copy()


Sort(arr, arr2, indict,Merge,Insertion)
