N = '{:0>4}'.format(int(input()))

while 1:
    up = ''.join(sorted(N)[::-1])
    down = ''.join(sorted(N))
    N = '{:0>4}'.format(eval(str(int(up)) + '-'+ str(int(down))))
    print(up+' - '+down+' = '+N)
    if N == '0000' or N == '6174':
        break