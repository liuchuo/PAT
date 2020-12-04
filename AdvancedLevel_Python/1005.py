n = input()

s = str(sum([int(i) for i in n]))

database = ['zero', 'one', 'two','three', 'four', 'five', 'six', 'seven', 'eight', 'nine']

print(' '.join([database[int(j)] for j in s]))
