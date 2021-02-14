expected_output = input()
real_output = input()

tmp = expected_output
bad_keys = []

for i in expected_output:
    if tmp == real_output:
        break
    if i in bad_keys:
        continue
    if i not in real_output:
        if i.upper() not in bad_keys:
            bad_keys.append(i.upper())
        tmp.replace(i, '')
        tmp.replace(i.upper(), '')

for i in bad_keys:
    print(i, end="")
