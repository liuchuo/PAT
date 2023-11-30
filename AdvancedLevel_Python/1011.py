def myread():
    return list(map(float, input().split()))


games = [myread() for i in range(3)]

diary = ['W', 'T', "L"]

ans = ' '.join([diary[i] for i in [x.index(max(x)) for x in games]])

from functools import reduce

total = str(round((reduce(lambda x, y:x*y, [max(i) for i in games]) * 0.65 - 1) * 2 * 100) / 100)

print(ans + ' ' + total)
