[n, k] = list(map(int, input().split()))

nums = list(map(int, input().split()))

index = list(map(int, input().split()))

from heapq import heappush

heap = []

for n in nums:
    heappush(heap, n)

for i in index:
    tmp  = []
    j = i
    while j >= 1:
        tmp.append(str(heap[j-1]))
        j = int(j/2)
    print(' '.join(tmp))
