def myread():
    return list(map(int, input().split()))

n, m = myread()

database = {}

scores_rank = {'C':[], 'M':[],'E':[],'A':[]}

for i in range(n):
    tmp = myread()
    database[str(tmp[0])] = [sum(tmp[1:])] + tmp[1:]
    scores_rank['C'].append(tmp[1])
    scores_rank['M'].append(tmp[2])
    scores_rank['E'].append(tmp[3])
    scores_rank['A'].append(sum(tmp[1:]))

for key in scores_rank:
    scores_rank[key].sort(reverse=True)

query = []

diary = [ 'A', 'C', 'M', 'E']

for i in range(m):
    tmp = input()
    if not tmp in database.keys():
        print('N/A')
    else:
        finished = False
        for k in range(n):
            if not finished:
                for j in range(4):
                    if scores_rank[diary[j]][k] <= database[tmp][j]:
                        print(str(k+1) + ' ' + diary[j])
                        finished = True
                        break
            else:
                break
