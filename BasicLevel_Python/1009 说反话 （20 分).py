#这是一种不用内建函数的方法，望采纳
i=input().split()
a=(i[::-1])
b=''
for c in a:
    b=b+c+' '
print(b[0:-1])
