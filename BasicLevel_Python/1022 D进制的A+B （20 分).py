A, B, D = map(int, input().split())

P = A + B

ans = []
while P>=D:
    ans.append(P%D)
    P = P//D
ans.append(P)

print(''.join(list(map(str,ans[::-1]))))