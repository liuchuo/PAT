num = input()

sum = 0
for i in num:
    sum += eval(i)

l = ['ling','yi','er', 'san', 'si', 'wu', 'liu', 'qi', 'ba', 'jiu']

for k,i in enumerate(str(sum)):
    if k == 0:
        print(l[int(i)], end='')
    else:
        print(' '+l[int(i)], end='')