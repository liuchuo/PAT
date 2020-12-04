n, m = list(map(int, input().split()))

preord = list(map(int, input().split()))

task_set = []

for i in range(n):
    task_set.append(list(map(int, input().split())))

ans = []

def solve(preord, task):
    if (not task[0] in preord) and (not task[1] in preord):
        return 'ERROR: ' + str(task[0]) + ' and ' + str(task[1]) + ' are not found.'
    elif not task[0] in preord:
        return 'ERROR: ' + str(task[0]) +' is not found.'
    elif not task[1] in preord:
        return 'ERROR: ' + str(task[1]) +' is not found.'
    else:
        for node in preord:
            if (node - task[0]) * (node - task[1]) < 0:
                return 'LCA of ' + str(task[0]) + ' and ' + str(task[1]) + ' is ' + str(node) + '.'
            elif node - task[0] == 0:
                return str(task[0]) + ' is an ancestor of '+ str(task[1]) + '.'
            elif node - task[1] == 0:
                return str(task[1]) + ' is an ancestor of ' + str(task[0]) + '.'

for task in task_set:
    ans.append(solve(preord, task))


[print(i) for i in ans]

