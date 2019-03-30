H = input()
N = H.split()
if len(N) > 2:
    N[1] = '?'
if N[0].isdigit() and 1 <= int(N[0]) <= 1000:
    a = int(N[0])
else:
    a = '?'
if N[1].isdigit() and 1 <= int(N[1]) <= 1000:
    b = int(N[1])
else:
    b = '?'
if H[0] == ' ':
    a = '?'
    if H[1:].isdigit():
        b = int(H[1:])
        if b > 1000 or b < 1:
            b = '?'
    else:
        b = '?'
if a != '?' and b != '?':
    print(N[0] + ' + ' + N[1] + ' = ' + str(a + b))
else:
    print(str(a) + ' + ' + str(b) + ' = ?')
