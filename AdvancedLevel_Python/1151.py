n, m =list(map(int, input().split()))

inord = list(map(int, input().split()))

preord = list(map(int, input().split()))

tasks = []

for i in range(n):
    tasks.append(list(map(int,input().split())))

def solve(preord, inord, task):
    u, v = task[0], task[1]
    root = preord[0]
    left_inord, right_inord = inord[:inord.index(root)], inord[inord.index(root) + 1:]
    left_preord, right_preord = preord[1:len(left_inord)+1], preord[len(left_inord) + 1:]

    if (u in preord and not v in preord):
        return 'ERROR: ' + str(v) + ' is not found.'
    elif (not u in preord and v in preord):
        return 'ERROR: ' + str(u) + ' is not found.'
    elif (not u in preord and not v in preord):
        return 'ERROR: ' + str(u) + ' and ' + str(v) + ' are not found.'

    if u == root:
        return str(u) + ' is an ancestor of ' + str(v) +'.'
    if v == root:
        return str(v) + ' is an ancestor of ' + str(u) + '.'

    elif (u in left_preord and v in right_preord) or (u in right_preord and v in left_preord):
        return 'LCA of ' + str(u) + ' and ' + str(v) + ' is ' + str(root) + '.'
    elif (u in left_preord and v in left_preord):
        return solve(left_preord, left_inord, task)
    elif (u in right_preord and v in right_preord):
        return solve(right_preord, right_inord, task)


for task in tasks:
    print(solve(preord, inord, task))


