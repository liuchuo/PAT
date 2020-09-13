n, m = list(map(int, input().split()))

data = []

if n == 0 :
    exit(0)

for i in range(m):
    data.append(input().split())

def build_tree(data):
    tree = {}
    for i in data:
        tree[i[0]] = i[2:]
    return tree

def deeper(tree):
    head = '01'
    layer = [head]
    ans = []
    while layer:
        num_of_leaves = 0
        next_layer = []
        for node in layer:
            if not node in tree.keys():
                num_of_leaves += 1
            else:
                son_of_node = tree[node]
                next_layer += son_of_node
        ans.append(num_of_leaves)
        layer = next_layer

    return ans

print(' '.join(list(map(str, deeper(build_tree(data))))))
