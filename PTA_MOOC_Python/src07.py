def get_tree():
    nums = int(input())
    node = dict()
    for i in range(nums):
        node[str(i)] = [str(i)] + input().split()
    return nums, node

def get_root(nums, tree):
    tmp = []
    for i in tree.values():
        tmp += i[1:]
    for i in range(nums):
        if not str(i) in tmp:
            return tree[str(i)]

nums, tree = get_tree()
root = get_root(nums, tree)

#print(tree)
#print(root)

def deeper(node, tree):
    if not node[0] == '-':
        left = tree[node[0]]
    else:
        left = [None]
    if not node[1] == '-':
        right = tree[node[1]]
    else:
        right = [None]
    return left,right

from collections import Counter

def dive(root, tree):
    ans = ''
    layer = [root]
    while layer:
        layer_new = []
        for node in layer:
            if Counter(node)['-'] == 2:
                ans += node[0]
                ans += ' '
            for i in range(1,3):
                if node[i] != '-':
                    layer_new.append(tree[node[i]])
        layer = layer_new
    print(ans[:-1])
dive(root, tree)

