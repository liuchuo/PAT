N = input()
dic = {'G': 0, 'P': 0, 'L': 0, 'T': 0}
for i in N:
    if i == 'g' or i == 'G':
        dic['G'] = dic['G'] + 1
    if i == 'p' or i == 'P':
        dic['P'] = dic['P'] + 1
    if i == 'l' or i == 'L':
        dic['L'] = dic['L'] + 1
    if i == 't' or i == 'T':
        dic['T'] = dic['T'] + 1
while max(dic.values()) != 0:
    if dic['G'] != 0:
        print('G', end='')
        dic['G'] = dic['G'] - 1
    if dic['P'] != 0:
        print('P', end='')
        dic['P'] = dic['P'] - 1
    if dic['L'] != 0:
        print('L', end='')
        dic['L'] = dic['L'] - 1
    if dic['T'] != 0:
        print('T', end='')
        dic['T'] = dic['T'] - 1
