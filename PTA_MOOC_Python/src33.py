prime = int(input())

seq = list(map(int, input().split()))

m = [list(map(lambda x:x % prime if x!= -1 else -1,[x]))[0] for x in seq]

seq_ = sorted([[i, seq[i]] for i in range(len(seq)) if seq[i] > 0], key=lambda x:x[1])

mo = [0 for i in range(len(m))]
ans = []
p = 0
while len(ans) != len(seq_):
    add_of_p = seq_[p][0]
    value_of_p = seq_[p][1]
    designed_add = m[add_of_p]
    if add_of_p == designed_add and mo[add_of_p] == 0:
        mo[add_of_p] = 1
        ans.append(value_of_p)
        p = 0
    elif 0 not in mo[designed_add if designed_add != len(seq) -1 else 0:add_of_p] and mo[add_of_p] == 0:
        mo[add_of_p] = 1
        ans.append(value_of_p)
        p = 0
    else:
        p += 1

from functools import reduce
print(reduce(lambda x,y:str(x)+' '+str(y), ans))