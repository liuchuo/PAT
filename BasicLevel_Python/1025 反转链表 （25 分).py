head, N_all, gap = map(int, input().split())

l_data = [None]*100001
l_next = [None]*100001

for i in range(N_all):
    a_address, a_data, a_next = map(int, input().split())
    l_next[a_address] = a_next
    l_data[a_address] = a_data

l = []
while head != -1:
    l.append(head)
    head = l_next[head]

N_all = len(l)
n = N_all//gap

for i in range(n):
    gaps = i*gap
    l[gaps:gaps+gap] = l[gaps:gaps+gap][::-1]

for k,i in enumerate(l[:-1]):
    print("{:0>5} {} {:0>5}".format(i, l_data[i], l[k+1]))
print("{:0>5} {} -1".format(l[-1], l_data[l[-1]]))