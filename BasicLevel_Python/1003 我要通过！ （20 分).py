n = eval(input())

for i in range(n):
    s = input()

    n_p = s.count('P')
    n_a = s.count('A')
    n_t = s.count('T')

    if sum([n_p, n_a, n_t]) != len(s):
        print('NO')
    elif n_p != 1 or n_t != 1:
        print('NO')
    elif s.find('P') > s.find('T'):
        print('NO')
    else:
        l_a = m_a = r_a = 0
        flag_p = flag_t = False
        for i in s:
            if i == 'P':
                flag_p = True
            elif i == 'T':
                flag_t = True
            else:
                if not (flag_p or flag_t):
                    l_a += 1
                elif flag_p and not flag_t:
                    m_a += 1
                elif flag_p and flag_t:
                    r_a += 1

        if m_a == 0:
            print('NO')
        elif l_a * m_a == r_a:
            print('YES')
        else:
            print('NO')