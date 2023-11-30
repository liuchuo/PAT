k = int(input())

diary = []

def date2second(date):
    h,m,s = date.split(':')
    return 3600 * h + 60 * m + s

for i in range(k):
    record = input().split()
    diary.append(record)

diary.sort(key=lambda x:date2second(x[1]))

first_bird = diary[0][0]

diary.sort(key=lambda x:date2second(x[2]))

last_one = diary[-1][0]

print(first_bird + ' ' + last_one)


