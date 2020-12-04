n = int(input())
array = [-1 for i in range(n)]
oper = []
tmp = input().split()
while tmp[0] != 'S' :
    oper.append(tmp)
    tmp = input().split()

def is_connected(oper1, oper2, array):
    if Counter(array)[-1] == 0:
        return 'yes'
    father1 = oper1
    while array[father1] != -1:
        father1 = array[father1]
    array[oper1] = father1 if father1 != oper1 else -1

    father2 = oper2
    while array[father2] != -1:
        father2 = array[father2]
    array[oper2] = father2 if father2 != oper2 else -1
    #print(array)
    if father1 == father2:
        return 'yes'
    else:
        return 'no'

from collections import Counter
for inst in oper:
    if inst[0] == 'C':
        print(is_connected(int(inst[1]) - 1, int(inst[2]) - 1, array))
    else:
        #print(array)
        tmp = min(int(inst[1]), int(inst[2])) - 1
        num_of_None = Counter(array)[-1]
        if int(inst[1]) > int(inst[2]):
            father = int(inst[1]) - 1
            if num_of_None == 0:
                break
            while array[father] != -1:
                father = array[father]
            array[father] = tmp
        else:
            if num_of_None == 0:
                break
            father = int(inst[2]) - 1
            while array[father] != -1:
                father = array[father]
            array[father] = tmp
#print(array)
k =  Counter(array)[-1]
if k == 1:
    print('The network is connected.')
else:
    print('There are '+ str(k) + ' components.')
