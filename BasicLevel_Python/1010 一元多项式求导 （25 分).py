l = input().split()

o = []

for i in range(int(len(l)/2)):
    a_i = int(l[i*2])
    n_i = int(l[i*2+1])

    if a_i == 0:
        o.append('0 0')
    elif n_i == 0:
        continue
    elif n_i == 1:
        o.append(str(a_i))
        o.append('0')
    else:
        o.append(str(a_i*n_i))
        o.append(str(n_i-1))

if len(o) == 0:
    print('0 0')
else:
    print(' '.join(o))