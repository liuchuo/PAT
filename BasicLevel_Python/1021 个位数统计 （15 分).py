N = input()

d = {}
for i in N:
    if i in d.keys():
        d[i] += 1
    else:
        d[i] = 1

for i in sorted(d):
    print(i+':'+str(d[i]))