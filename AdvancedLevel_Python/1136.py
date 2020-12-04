n = int(input())

for i in range(10):
    if str(n) == str(n)[::-1]:
        print(str(n) + ' is a palindromic number.')
        exit(0)
    print(str(n) + ' + ' + str(n)[::-1] + ' = ' + str(n + int(str(n)[::-1])))
    n = n + int(str(n)[::-1])
    if str(n) == str(n)[::-1]:
        print(str(n) + ' is a palindromic number.')
        exit(0)
        
print('Not found in 10 iterations.')
