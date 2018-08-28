N = input()
if N[0] == '-':
    k = 0
    for i in N:
        if i == '2':
            k = k + 1
    if int(N[-1]) % 2 == 0:
        m = k * 1.5 * 2 / (len(N) - 1)
    else:
        m = k * 1.5 / (len(N) - 1)
else:
    k = 0
    for i in N:
        if i == '2':
            k = k + 1
    if int(N[-1]) % 2 == 0:
        m = k * 2 / (len(N))
    else:
        m = k / (len(N))
print("%.2f" % (m * 100), end='')
print('%')
