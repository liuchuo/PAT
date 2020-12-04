n, k, s = input().split()

city = {}

number2city = [s]

city[s] = 0

for i in range(int(n) - 1):
    tmp = input().split()
    city[tmp[0]] = int(tmp[1])

    if tmp[0] not in number2city:
        number2city.append(tmp[0])

city2number = {number2city[i]:i for i in range(len(number2city))}

matrix = [[10000000 for j in range(int(n))]for i in range(int(n))]

for i in range(int(k)):

    tmp = input().split()

    matrix[city2number[tmp[0]]][city2number[tmp[1]]] = int(tmp[2])

    matrix[city2number[tmp[1]]][city2number[tmp[0]]] = int(tmp[2])


def djk(matrix, s, d):

    count = [1 for i in range(int(n))]

    his =[s]

    distance = [matrix[i][s] for i in range(int(n)) ]

    values = [city[number2city[i]] for i in range(int(n))]

    min_city_number = [-1 for i in range(int(n))]

    min_city_number[s] = 1

    pre_senquence = [[] for i in range(int(n))]

    pre_senquence[s].append(s)

    while len(his) != int(n):
        min_ = 1000000
        next_ = 0
        for i in range(int(n)):
            if distance[i] < min_ and i not in his:
                min_ = distance[i]
                next_ = i

        for past in his:
            if matrix[past][next_] == min_:
                count[next_] = count[past]
                min_city_number[next_] = min_city_number[past] + 1
                pre_senquence[next_].append(past)

        his.append(next_)

        for i in range(int(n)):
            if i not in his :
                if matrix[next_][i] + distance[next_] < distance[i]:
                    distance[i] = distance[next_] + matrix[i][next_]
                    values[i] = city[number2city[i]] + values[next_]
                    count[i] = count[next_]
                    min_city_number[i] = min_city_number[next_] + 1
                    pre_senquence[i].clear()
                    pre_senquence[i].append(next_)

                elif matrix[i][next_] + distance[next_] == distance[i]:
                    count[i] += count[next_]
                    if city[number2city[i]] + values[next_] > values[i] :
                        values[i] = city[number2city[i]] + values[next_]
                        min_city_number[i] = min_city_number[next_] + 1
                        pre_senquence[i].clear()
                        pre_senquence[i].append(next_)
                    elif city[number2city[i]] + values[next_] == values[i]:
                        if min_city_number[next_] + 1 < min_city_number[i]:
                            min_city_number[i] = min_city_number[next_] + 1
                            pre_senquence[i].clear()
                            pre_senquence[i].append(next_)

    return count[d], distance[d], values[d], pre_senquence, min_city_number


count, dis, happiness, pre_senquence, min_city_number = djk(matrix, city2number[s], city2number['ROM'])


def dfs(pre_senquence, s, d):
    ans = [d]
    now = d
    while now != s:
        now = pre_senquence[now][0]
        ans.append(now)


    return ans

net = dfs(pre_senquence, city2number[s], city2number['ROM'])

avg_happiness = happiness // (min_city_number[city2number['ROM']] - 1)

print(str(count) + ' ' + str(dis) + ' ' + str(happiness) + ' '+ str(avg_happiness))

print('->'.join(list(map(str, [number2city[i] for i in net[::-1]]))))

