l = list(map(int,input().split()))[1:]

def is_o(Ai):
    if isinstance(Ai, str):
        return Ai
    elif Ai == 0:
        return 'N'
    else:
        return str(Ai)

A1, A2, A3, A4, A5 = 0, 0, 0, 0, 0

f_1 = 1
f_2 = 0
for i in l:
    if i%10 == 0:
        A1 += i
    elif i%5 == 1:
        f_1 += 1
        A2 = A2 + i*(-1)**f_1
    elif i%5 == 2:
        A3 += 1
    elif i%5 == 3:
        f_2 += 1
        A4 += i
    elif i%5 == 4:
        if A5 <= i:
            A5 = i

if f_1 == 1:
    A2 = 'N'
elif A2 == 0:
    A2 = '0'

if f_2 == 0:
    A4 = 'N'
else:
    A4 = "{:.1f}".format(A4/f_2)

print(' '.join(list(map(is_o,[A1,A2,A3,A4,A5]))))

