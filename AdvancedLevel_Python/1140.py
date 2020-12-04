d, m = input().split()

ans = d

def next(s):
    tmp = []
    for i in range(len(s)):
        if tmp and (s[i] in tmp[-1]):
            tmp[-1].append(s[i])
        else:
            tmp.append([s[i]])
    return ''.join([str(each[0]) + str(len(each)) for each in tmp])

for i in range(int(m) - 1):
    ans = next(ans)

print(ans)
