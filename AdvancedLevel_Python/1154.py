n , m = list(map(int, input().split()))

edges = []

for i in range(m):
    edges.append(list(map(int, input().split())))

k = int(input())

tasks = []

def is_k_coloring(edges, tmp):
    for edge in edges:
        if tmp[edge[0]] == tmp[edge[1]]:
            return False
    return True


for i in range(k):
    tmp = list(map(int, input().split()))
    if is_k_coloring(edges, tmp):
        print(str(len(set(tmp))) + '-coloring')
    else:
        print('No')
