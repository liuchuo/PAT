N = input().split()
a = int(N[0])
b = int(N[-1])
jieguo = 0
if b == 0:
    print(N[0] + '/' + N[-1] + '=Error')
elif b < 0:
    jieguo = a / b
    print("%d/(%d)=%.2f" % (a, b, jieguo))
else:
    jieguo = a / b
    print("%d/%d=%.2f" % (a, b, jieguo))
