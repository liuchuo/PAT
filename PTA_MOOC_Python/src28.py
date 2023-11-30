m, k, n = list(map(int, input().split()))
s = list(map(int, input().split()))

data = {}
Compile = {}
for i in range(int(n)):
    new_input = input().split()
    if new_input[0] in data.keys():
        if data[new_input[0]][int(new_input[1])-1] == '-':
            data[new_input[0]][int(new_input[1]) - 1] = max(int(new_input[2]),0)
            if int(new_input[2]) != -1:
                Compile[new_input[0]] = True
        else:
            data[new_input[0]][int(new_input[1])-1] = max(int(new_input[2]), data[new_input[0]][int(new_input[1])-1])

    else:
        data[new_input[0]] = ['-' for i in range(k)]
        data[new_input[0]][int(new_input[1]) - 1] = max(int(new_input[2]),0)
        Compile[new_input[0]] = False
        if int(new_input[2]) != -1:
            Compile[new_input[0]] = True

score = {}
for key in data.keys():
    score[key] = sum([i for i in data[key] if i != '-'])

distribution = list(set(score.values()))
d = list(score.values())
d.sort(reverse=True)
rank = {}
for key in distribution:
    rank[key] = d.index(key) + 1

key_list = list(score.keys())
key_list.sort(key=lambda x:score[x],reverse=True)

score_extra = {}
for key in key_list:
    score_extra[key] = sum([1 for i in range(len(data[key])) if data[key][i] == s[i]])

for i in range(len(key_list)):
    for j in range(i+1, len(key_list)):
        if score[key_list[i]] == score[key_list[j]]:
            if score_extra[key_list[j]] == score_extra[key_list[i]]:
                if int(key_list[j]) < int(key_list[i]):
                    key_list[i], key_list[j] = key_list[j], key_list[i]
            elif score_extra[key_list[j]] > score_extra[key_list[i]]:
                key_list[i], key_list[j] = key_list[j], key_list[i]
        else:
            pass

for i in key_list:
    if Compile[i]:
        print(str(rank[score[i]]) + ' ' + i + ' ' +str(score[i]) + ' ' + ' '.join(list(map(str, data[i]))))
