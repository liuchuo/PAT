C1, C2 = map(int, input().split())

seconds = C2 - C1
if seconds%100 >= 50:
    seconds = seconds//100+1
else:
    seconds = seconds//100

hh = seconds//3600
mm = (seconds%3600)//60
ss = seconds%60

print("{:0>2}:{:0>2}:{:0>2}".format(hh, mm, ss))