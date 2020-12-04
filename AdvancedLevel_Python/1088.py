a, b = input().split()

a1, a2 = list(map(int, a.split('/')))
b1, b2 = list(map(int, b.split('/')))

min_k = a2 * b2

ans1, ans2= a1 * b2, a2 * b1

def div(top, bottom):
    while 1:
        stop = True
        for i in range(2, int(top)+1):
            if int(bottom) % i == 0 and int(top) % i ==0:
                bottom /= int(i)
                top /= int(i)
                stop = False
                break
        if stop:
            return int(top), int(bottom)


def simplify(top, bottom):
    if top % bottom == 0:
        ans = int(top / bottom)

        return '('+str(ans) +')' if ans < 0 else str(ans)

    if abs(top) < abs(bottom):
        a_, b_ = div(abs(top), abs(bottom))
        ans = str(a_) + '/' + str(b_)
        return '(' +'-' + ans +')' if top * bottom < 0 else ans

    if abs(top) > abs(bottom):
        k0 = str(abs(top) // abs(bottom)) if top * bottom > 0 else '-' +str(abs(top) // abs(bottom))
        k1 = str(abs(top) % abs(bottom))

        a_, b_ = div(int(k1), bottom)
        ans = k0 +' '+ str(a_) + '/' + str(b_)
        return '(' + ans +')' if top * bottom < 0 else ans

in_a, in_b = simplify(a1,a2), simplify(b1,b2)

re1 = simplify(ans1 + ans2, min_k)
print(in_a + ' + ' + in_b +' = ' + re1)

re2 = simplify(ans1 - ans2, min_k)
print(in_a + ' - ' + in_b + ' = ' + re2)

re3 = a1 * b1
re3_ = a2 * b2

print(in_a + ' * ' + in_b + ' = ' + simplify(re3, re3_))

re4 = a1 * b2
re4_ = a2 * b1

if re4_ == 0:
    print(in_a + ' / ' + in_b + ' = ' + 'Inf')
else:
    print(in_a + ' / ' + in_b + ' = ' + simplify(re4, re4_))

