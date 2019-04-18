import math

M, N = tuple(map(int, input().split()))

def is_primer(p, ans):
    n_sqrt = int(math.sqrt(p))+1
    for i in ans:
        if i >= n_sqrt:
            return True
        if p%i == 0:
            return False
    return True

ans = []
ans_len = 1
p = 2
while ans_len <= N:
    if is_primer(p, ans):
        ans.append(p)
        ans_len += 1
    p += 1

for i in range(M-1, N, 10):
    print(' '.join(map(str,ans[i:i+10])))