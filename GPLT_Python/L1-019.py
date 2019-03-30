te = input().split()
jiav = int(te[0])
yiv = int(te[1])
N = int(input())
jiah = 0
yih = 0
while True:
    if jiah > jiav:
        print('A')
        print(yih)
        break
    if yih > yiv:
        print('B')
        print(jiah)
        break
    temp = input().split()
    if int(temp[1]) == int(temp[0]) + int(temp[2]) and int(temp[3]) != int(temp[0]) + int(temp[2]):
        jiah = jiah + 1
    if int(temp[1]) != int(temp[0]) + int(temp[2]) and int(temp[3]) == int(temp[0]) + int(temp[2]):
        yih = yih + 1
