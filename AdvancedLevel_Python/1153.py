n, m = list(map(int, input().split()))

data = []

for i in range(n):
    tmp = input()
    cardnumber = tmp.split()[0]
    scores = tmp.split()[1]
    data.append({'cardnumber':tmp,'level':cardnumber[0], 'site':cardnumber[1:4], 'date':cardnumber[4:10], 'number':cardnumber[10:13], 'scores':scores})

for j in range(m):
    tmp = input().split()
    type = tmp[0]
    term = tmp[1]
    if type == '1':
        print('Case ' + str(j+1) +': ' + type + ' ' + term)
        ans = []
        for item in data:
            if item['level'] == term:
                ans.append(item)
        ans.sort(key=lambda x:(-int(x['scores']), x['cardnumber']))
        if ans: [print(i['cardnumber']) for i in ans]
        else: print('NA')
    elif type == '2':
        print('Case ' + str(j+1) + ': ' + type + ' ' + term)
        ans = []
        for item in data:
            if item['site'] == term:
                ans.append(item)
        from functools import reduce
        p = 0
        for x in ans:
            p += int(x['scores'])
        if ans: print(str(len(ans)) +' ' + str(p))
        else: print('NA')
    elif type == '3':
        print('Case ' + str(j+1) + ': ' + type + ' ' + term)
        ans = []
        for item in data:
            if item['date'] == term:
                ans.append(item)
        ans_2 = []
        for e in ans:
            ans_2.append(e['site'])

        from collections import Counter
        c = Counter(ans_2)
        c_ = sorted(c, key=lambda x:(-int(c[x]), int(x)))

        if not ans_2: print('NA')
        else: [print(str(j) + ' ' + str(c[j])) for j in iter(c_)]

