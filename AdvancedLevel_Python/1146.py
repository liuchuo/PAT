n, m = list(map(int, input().split()))

prenode_of_nodei = {i+1:[] for i in range(n)}

for i in range(m):
    tmp = list(map(int, input().split()))
    prenode_of_nodei[tmp[1]].append(tmp[0])

k = int(input())

def is_wrong(prenode_of_nodei, query):

    for i in range(len(query)):
        pre_set, post_set = query[:i], query[i+1:]
        for prenode in prenode_of_nodei[query[i]]:
            if not prenode in pre_set:
                return True
    return False

ans = []

for i in range(k):
    query = list(map(int, input().split()))
    if is_wrong(prenode_of_nodei, query):
        ans.append(str(i))

print(' '.join(ans))
