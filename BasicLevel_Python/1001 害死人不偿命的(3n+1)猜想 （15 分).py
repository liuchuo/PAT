n = eval(input())
times = 0

while n != 1 :
    if n % 2 == 0:
        n /= 2
    else:
        n = (n*3+1)/2
    times = times + 1

print(times)