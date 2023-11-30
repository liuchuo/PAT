n = int(input())
array = list(map(int, input().split()))

from collections import Counter
c = Counter(array)

keys = list(c.keys())
keys.sort()

[print(str(i)+':'+str(c[i])) for i in keys]
