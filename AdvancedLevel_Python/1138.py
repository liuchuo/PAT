n = input()

preord = list(map(int, input().split()))

inord = list(map(int, input().split()))


def cycle(preord, inord):
    if not preord: return []
    if len(preord) == 1: return preord
    key = inord.index(preord[0])
    return cycle(preord[1:key+1], inord[:key]) + cycle(preord[key+1:], inord[key+1:]) + [preord[0]]

print(str(cycle(preord, inord)[0]))
