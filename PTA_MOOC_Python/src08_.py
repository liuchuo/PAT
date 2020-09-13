n = int(input())

f = []
temp = []
m = []
l = []
for i in range(2 * n):
    x = input().split()
    if x[0] == 'Push':
        f.append(int(x[1]))
        temp.append(int(x[1]))
    else:
        m.append(temp.pop())
del temp

if n == 1:
    print(str(m[0]))
    exit(0)

def reConstruction (after,pre,cen):
    if len(pre)==0:
        return
    if len(pre)==1:
        return (pre[0])
    after.append(pre[0])
    i=0
    for i in range (len(cen)):
        if cen[i]==pre[0]:
            break
    left_cen=cen[:i]
    right_cen=cen[i+1:]
    left_pre = pre[1:i+1]
    right_pre = pre[i+1:]

    after.append(reConstruction(after, right_pre, right_cen))
    after.append(reConstruction (after,left_pre,left_cen))

reConstruction (l,f,m)
res=[]
for i in l:
    if i !=None:
        res.append(str(i))
print(res)
print(' '.join(res[::-1]))
