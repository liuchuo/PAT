kind, need = map(int, input().split())
amount = list(map(float, input().split()))
price = list(map(float, input().split()))

ans = 0

rate = {i: price[i]/amount[i] for i in range(kind)}

order = sorted(rate, key=lambda i:rate[i], reverse=True)

for i in order:
    if amount[i] > need:
        ans += rate[i]*need
        break
    else:
        need -= amount[i]
        ans += price[i]

print('{:.2f}'.format(ans))
