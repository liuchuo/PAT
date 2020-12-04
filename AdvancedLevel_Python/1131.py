n = int(input())

data = []

Number_of_station = {}

Station_of_number = {}

note = 0

for i in range(n):
    tmp = input().split()
    data.append(tmp[1:])

for line in data:
    for station in line:
        if station in Number_of_station.keys():
            pass
        else:
            Number_of_station[station] = note
            note += 1

for station in Number_of_station.keys():
    Station_of_number[Number_of_station[station]] = station

graph = [['' for i in range(note)] for i in range(note)]

m = int(input())

plans = []

for i in range(m): plans.append(input().split())

for i in range(len(data)):
    line = data[i]

    for j in range(len(line) - 1):
        graph[Number_of_station[line[j]]][Number_of_station[line[j + 1]]] = 'Line#' + str(i+1)
        graph[Number_of_station[line[j + 1]]][Number_of_station[line[j]]] = 'Line#' + str(i+1)

def floyd(graph, layer, destination, his, route, boat, cost):
    if not layer: return
    layer_pro = []
    route_pro = []
    for station in layer:
        for number in range(len(graph[Number_of_station[station]])):
            if (graph[Number_of_station[station]][number]) and (Station_of_number[number] not in his):
                layer_pro.append(Station_of_number[number])
                his.append(Station_of_number[number])

                for solution in route:
                    if solution[-1] == station:
                        route_pro.append(solution + [Station_of_number[number]])
                        new_line = graph[Number_of_station[station]][number]
                        if len(solution) > 2:
                            old_line = graph[Number_of_station[solution[-2]]][Number_of_station[solution[-1]]]
                            if new_line != old_line:
                                route_pro[-1][0] += 1
                                cost[Station_of_number[number]] = solution[0] + 1
                            else:
                                cost[Station_of_number[number]] = solution[0]
                        else:
                            cost[Station_of_number[number]] = solution[0]
                    else:
                        route_pro.append(solution)
            else:
                pass

    if route_pro:
       for i in route_pro:
            if not i in boat: boat.append(i)

    #print(cost)
    #print(layer_pro, route)

    layer_pro.sort(key=lambda x:cost[x])

    floyd(graph, layer_pro, destination, his, route_pro, boat, cost)


for task in plans:
    his = [task[0]]
    route = [[0,task[0]]]
    boat = []
    cost = {}
    floyd(graph, [task[0]], task[1], his, route, boat, cost)

    boat.sort(key=lambda x:len(x))
    #[print(i) for i in boat]
    boat_ = []
    for re in boat:
        if re[-1] == task[1]:
            boat_.append(re)
    boat_.sort(key= lambda x:x[0])

    def station2line(graph, line):
        ans = []

        tmp = 'Take ' + graph[Number_of_station[line[1]]][Number_of_station[line[2]]] + ' from ' + str(line[1]) + ' to '

        now_line = graph[Number_of_station[line[1]]][Number_of_station[line[2]]]

        for i in range(2, len(line)-1):
            #print(i, len(line) - 1, line[i])
            if graph[Number_of_station[line[i]]][Number_of_station[line[i + 1]]] != now_line:
                ans.append(tmp + str(line[i]) + '.')
                tmp = 'Take ' + graph[Number_of_station[line[i]]][Number_of_station[line[i + 1]]] + ' from ' + str(
                    line[i]) + ' to '
                now_line = graph[Number_of_station[line[i]]][Number_of_station[line[i + 1]]]
            if i == len(line) - 2:
                ans.append(tmp + str(line[i+1]) + '.')
            #print(tmp)
        return ans
    print(len(boat_[0]) - 2)
    [print(duan) for duan in station2line(graph, boat_[0])]

