n, m = list(map(int, input().split()))

arr = list(map(int, input().split()))

runs = {i:[] for i in range(n)}

memory = [arr.pop(0) for i in range(m)]

guide = {v:0 for v in memory}

k = 0

while memory:
    tmp = [v for v in memory if guide[v] == k]
    if not tmp:
        k += 1
        tmp = [v for v in memory if guide[v] == k]

    now_index = memory.index(min(tmp))
    now = memory.pop(now_index)
    runs[k].append(now)

    if arr:
        new = arr.pop(0)
        if new >= now:
            guide[new] = k
        else:
            guide[new] = k + 1
        memory.append(new)

[print(' '.join(list(map(str, run)))) for run in runs.values() if run]


"""
13 3
81 94 11 96 12 99 2 2 2 17 35 28 58 41 75 15 10 9 8 7 6 5 4
"""