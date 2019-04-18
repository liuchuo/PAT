r = input().split()
N = int(r[0])
M = int(r[1])

l = list(input().split())

print(' '.join(l[N-M:]+l[:N-M]))