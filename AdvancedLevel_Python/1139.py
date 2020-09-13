n, m = list(map(int, input().split()))

guys = {}

query = []

for i in range(m):
    tmp = input().split()

    def add(d, tmp):
        for i in range(2):
            if tmp[i] in d.keys():
                d[tmp[i]].append(tmp[abs(i-1)])
            else:
                d[tmp[i]] = [tmp[abs(i-1)]]
    add(guys, tmp)

k = int(input())
for i in range(k): query.append(input().split())


for couple in query:
    ans = []
    for lover in couple:
        if not lover in guys.keys():
            guys[lover] = []

    layer = [list(set([guy for guy in guys[lover] if (len(guy) == len(lover) and [guy] != [man for man in couple if man != lover]) ] )) for lover in couple]

    one_side = {medium:[man for man in guys[medium] if man != couple[1]] for medium in set(layer[0])}

    for e in set(layer[1]):

        for key in one_side.keys():
            if e in one_side[key]:
                ans.append([abs(int(key)), abs(int(e))])

    ans.sort(key=lambda x:(int(x[0]), int(x[1])))
    print(len(ans))
    def decorate(s):
        ans = ''
        if len(s) != 4:
            for i in range(4-len(s)):
               ans += '0'
        return ans + s

    [print(' '.join(map(decorate, list(map(str, i))))) for i in ans]


