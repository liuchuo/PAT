# TODO: 样例5随机超时或错误

N = int(input())

A_vs_B = [0, 0, 0]
A_count = {'C':0, 'B':0, 'J':0}
B_count = {'C':0, 'B':0, 'J':0}

win = {'C':'J', 'J':'B', 'B':'C'}
lose = {'J':'C', 'B':'J', 'C':'B'}

for i in range(N):
    l = input().split()
    if l[0] == l[1]:
        A_vs_B[1] += 1
    elif win[l[0]] == l[1]:
        A_vs_B[0] += 1
        A_count[l[0]] += 1
    else:
        A_vs_B[2] +=1
        B_count[l[1]] += 1

score = ' '.join(map(str, A_vs_B))
print(score)
print(score[::-1])

m_a = 'J'
if A_count[m_a] <= A_count['C']:
    m_a = 'C'
if A_count[m_a] <= A_count['B']:
    m_a = 'B'

m_b = 'J'
if B_count[m_b] <= B_count['C']:
    m_b = 'C'
if B_count[m_b] <= B_count['B']:
    m_b = 'B'

print(m_a+' '+m_b)