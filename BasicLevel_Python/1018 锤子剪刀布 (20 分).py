n = int(input())
matchs = []
for i in range(n):
    matchs.append(input())
result = [0,0,0]
win1 = [0,0,0]
win2 = [0,0,0]
m = ['B C','C J','J B'] # 按首字母升序排序
for i in range(3):
    win1[i] = matchs.count(m[i])
    win2[i] = matchs.count(m[i][::-1])
result[0] = sum(win1)
result[2] = sum(win2)
result[1] = n-result[0]-result[2]
print(' '.join(map(str,result)))
print(' '.join(map(str,result[::-1])))
print(m[win1.index(max(win1))][0]+' '+m[win2.index(max(win2))][0])