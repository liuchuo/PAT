n, m = input().split()

dangerous = {}

for i in range(int(n)):
    tmp = list(map(int, input().split()))
    if not tmp[0] in dangerous.keys():
        dangerous[tmp[0]] = [tmp[1]]
    else:
        dangerous[tmp[0]].append([tmp[1]])
    if not tmp[1] in dangerous.keys():
        dangerous[tmp[1]] = [tmp[0]]
    else:
        dangerous[tmp[1]].append([tmp[0]])

ans = []

for i in range(int(m)):
    tmp = list(map(int, input().split()))[1:]
    is_safe = True
    for good in tmp:
        if good in dangerous.keys():
            for dangerous_make in dangerous[good]:
                if dangerous_make in tmp:
                    is_safe = False
                    ans.append('No')
                    break
            if not is_safe:
                break
    if is_safe: ans.append('Yes')

[print(i) for i in ans]


