def getNext(t):
    j, i = -1, 0
    next = [-1]*len(t)
    while i < len(t)-1:
        if -1 == j or t[i] == t[j]:
            i, j = i + 1, j + 1
            next[i] = j
        else:
            j = next[j]
    return next

def KMP(s,t):
    next = getNext(t)
    j, i = -1, -1
    while j != len(t) and i < len(s):
        if s[i] == t[j] or j == -1:
            i, j = i + 1, j + 1
        else:
            j = next[j]
    return s[i-j:] if j == len(t) else "Not Found"

s = input()
n = int(input())
data = []
for i in range(n):
    data.append(input())

[print(KMP(s,i)) for i in data]
