
l = []
for i in range(120)[1:]:
    if 2*i**2-1 > 1000:
        break
    l.append(2*i**2-1)

print(l)