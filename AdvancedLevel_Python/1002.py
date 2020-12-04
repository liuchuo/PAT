p = []

p.append(input().split())

p.append(input().split())

p_dict = [{int(x[2 * i + 1]) : float(x[2 * i+2]) for i in range(int(x[0]))} for x in p]

final = {}

for d in p_dict:
    for key in d.keys():
        if not key in final:
            final[key] = d[key]
        else:
            final[key] += d[key]

s = ''

tmp = []

final_sorted_keys = sorted(final, key=lambda x:-x)

k = 0

for i in iter(final_sorted_keys):
    if not final[i] == 0:
        tmp.append(str(i))
        tmp.append(str(round(final[i]* 10) / 10))
        k += 1
if k != 0:
    s += str(k) + ' '
else:
    s += str(k)
s += ' '.join(tmp)

print(s)
