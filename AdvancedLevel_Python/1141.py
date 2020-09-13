n = int(input())

TWS_of_School = {}

for i in range(n):
    tmp = input().split()

    def tws_of_tmp(tmp):
        if tmp[0][0] == 'B':
            return int(tmp[1]) * 2
        elif tmp[0][0] == 'A':
            return int(tmp[1]) * 3
        else:
            return int(tmp[1]) * 4.5

    if not tmp[-1].lower() in TWS_of_School.keys():
        TWS_of_School[tmp[-1].lower()] = [tws_of_tmp(tmp)]
    else:
        TWS_of_School[tmp[-1].lower()].append(tws_of_tmp(tmp))


ans = [ [school_name, TWS_of_School[school_name]] for school_name in iter(TWS_of_School)]

ans.sort(key=lambda x : ( -sum(x[1]), len(x[1]), x[0] ))

k = 1
count = 0
pre_TWS = 100000000000000

print(len(ans))

for line in ans:
    tws = int(sum(line[1]) // 3)
    if tws < pre_TWS:
        k += count
        count = 0
        pre_TWS = tws
    count += 1
    print(str(k) + ' ' + line[0] + ' ' + str(tws) + ' ' + str(len(line[1])))
