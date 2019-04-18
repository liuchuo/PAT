A, d_A, B, d_B = tuple(input().split())

c_A = A.count(d_A)
c_B = B.count(d_B)

if c_A == 0:
    c_A = '0'
else:
    c_A *= d_A

if c_B == 0:
    c_B = '0'
else:
    c_B *= d_B

print(eval(c_A +'+'+ c_B))