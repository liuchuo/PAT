a = str(input())
b = {'0': 0, '1': 0, '2': 0, '3': 0, '4': 0, '5': 0, '6': 0, '7': 0, '8': 0, '9': 0}
for i in a:
    b[i] = b[i] + 1
for i in range(len(b)):
    if b[str(i)] == 0:
        continue
    print(str(i) + ':' + str(b[str(i)]))
