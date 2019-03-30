N = input().split()
M = input().split()
if N[0] > N[1]:
    if '0' in M:
        k = 0
        for i in M:
            if i == '0':
                k = k + 1
        print('The winner is a: ' + N[0] + ' + ' + str(k))
    else:
        print('The winner is b: ' + N[1] + ' + 3')
else:
    if '1' in M:
        k = 0
        for i in M:
            if i == '1':
                k = k + 1
        print('The winner is b: ' + N[1] + ' + ' + str(k))
    else:
        print('The winner is a: ' + N[0] + ' + 3')
