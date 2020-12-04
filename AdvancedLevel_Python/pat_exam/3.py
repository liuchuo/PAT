n, r , k = list(map(int, input().split()))

edges = []

for i in range(r):
    tmp = list(map(int, input().split()))
    edges.append(tmp)

m = int(input())

quert_list = []

for i in range(m):
    quert_list.append(list(map(int, input().split())))

def judge(edges, query, k):
    if len(list(set(query))) < k:
        return 'Error: Too few species.'
    elif len(list(set(query))) > k:
        return 'Error: Too many species.'

    for edge in edges:
        if query[edge[0] - 1] == query[edge[1] - 1]:
            return 'No'
    else:
        return 'Yes'

[print(judge(edges, query, k)) for query in quert_list]




