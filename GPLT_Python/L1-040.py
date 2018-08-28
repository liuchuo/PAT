N = int(input())
a = []
for i in range(N):
    temp = input().split()
    if temp[0] == 'M':
        a.append(eval(temp[1]) / 1.09)
    else:
        a.append(eval(temp[1]) * 1.09)
for i in a:
    print("%.2f" % i)
