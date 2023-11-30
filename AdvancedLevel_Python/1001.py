n, m = list(map(int, input().split()))

ans = str(n + m)

def get_list(ans):
    a, b = len(ans) / 3, int(len(ans) % 3)
    if not b == 0:
        re = [ans[:b]]
    else:
        re = []
    for i in range(0, int(a)):
        re.append(ans[b + 3 * i:b + i * 3 + 3])
    return re

if len(ans) < 4:
    print(ans)
else:
    if int(ans) < 0:
        re = get_list(ans[1:])
        tmp = ','.join(re)
        print('-' + tmp)

    else:
        re = get_list(ans)
        print(','.join(re))

