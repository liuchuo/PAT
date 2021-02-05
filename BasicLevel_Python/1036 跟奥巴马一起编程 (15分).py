a,b=input().split()
a=int(a)
c=a/2
if str(c)[-1]=="5":
    Columns_Num=int(c)+1
else:
    Columns_Num=int(c)

print(b*a)
for i in range(Columns_Num-2):
    print(b+' '*(a-2)+b)
print(b*a)
