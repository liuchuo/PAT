s = input()

loc_e = s.find('E')
if s[0] == '+':
    symbol_a = ''
else:
    symbol_a = '-'
a = s[1]+s[3:loc_e]
symbol_e = s[loc_e+1]
e = int(s[loc_e+2:])

if e == 0:
    a = s[1:loc_e]
elif symbol_e == '-':
    a = '0.'+('0'*(e-1))+a
elif symbol_e == '+':
    if e < len(a)-1:
        a = a[:e+1]+'.'+a[e+1:]
    else:
        a += (e-len(a)+1)*'0'

print(symbol_a+a)