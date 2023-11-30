n = int(input())
data = {}
res = []
for i in range(n):
    tmp = input().split()
    if tmp[1] in data.keys():
        if tmp[0] == 'N':
            res.append('ERROR: Exist')
        if tmp[0] == 'L':
            if tmp[2] == data[tmp[1]][2]:
                res.append('Login: OK')
            else:
                res.append('ERROR: Wrong PW')
    elif tmp[0] == 'N':
        data[tmp[1]] = tmp
        res.append('New: OK')
    else:
        res.append('ERROR: Not Exist')

[print(i) for i in res]