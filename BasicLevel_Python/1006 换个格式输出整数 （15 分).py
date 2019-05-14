n = int(input())

n_b = n//100
n_s = (n%100)//10
n_g = n%10

print('B'*n_b+'S'*n_s, end='')

for i in range(n_g):
    print(i+1, end='')