
def myread():
    return list(map(int, input().split()))

a, b = myread()

n, m = myread()

data = []

rounds = []

for i in range(n):
    data.append(myread())

rounds = [[data[j][i] for j in range(n)] for i in range(m)]

his = {a:0}

his[b] = 0

table = {abs(a - b):0}


def is_ok(his, table, new):
    try:
        a = table[new]
    except:
        return False
    try:
        b = his[new]
        return False
    except:
        his[new] = 0

    for num in his:
        if num != new:
            table[abs(num - new)] = 0

    return True

playing_player = [True for i in range(n)]

report = []

for r in range(m):
    for player_id in range(n):
        if playing_player[player_id]:
            new = rounds[r][player_id]
            if is_ok(his, table, new):
                pass
            else:
                playing_player[player_id] = False
                report.append('Round #' + str(r + 1) +': ' + str(player_id + 1) + ' is out.')

[print(message) for message in report]

winners = [id + 1 for id in range(n) if playing_player[id]]

if not winners:
    print('No winner.')
else:
    print('Winner(s): ' + ' ' .join(list(map(str, winners))))

