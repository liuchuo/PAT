a = []
while True:
    N = input()
    if N != '.':
        a.append(N)
    else:
        break
if len(a) < 2:
    print('Momo... No one is for you ...')
elif 2 <= len(a) < 14:
    print(a[1] + ' is the only one for you...')
else:
    print(a[1] + ' and ' + a[13] + ' are inviting you to dinner...')
