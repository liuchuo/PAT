def get_tree():
    nums = int(input())
    node = dict()
    for i in range(nums):
        node[str(i)] = input().split()
    return nums, node

def get_root(nums, tree):
    tmp = []
    for i in tree.values():
        tmp += i[1:]
    for i in range(nums):
        if not str(i) in tmp:
            return tree[str(i)]

nums1, tree1 = get_tree()
nums2, tree2 = get_tree()

#print(tree1)
#print(tree2)

if not tree1 or not tree2:
    if not tree1 and not tree2:
        print('Yes')
        exit(0)
    else:
        print('No')
        exit(0)

root1, root2 = get_root(nums1, tree1), get_root(nums2, tree2)

#print(root1, root2)

from collections import Counter

def judge(n1, n2, tree1, tree2):
    if n1[0] != n2[0]:
        #print(n1[0], n2[0])
        print('No')
        exit(0)
    if Counter(n1)['-'] != Counter(n2)['-']:
        #print(Counter(n1)['-'], Counter(n2)['-'])
        print('No')
        exit(0)
    if not n1[0]:
        return 0
    else:
        l1, r1 = deeper(n1, tree1)
    if not n2[0]:
        return 0
    else:
        l2, r2 = deeper(n2, tree2)

    if l1[0] == l2[0] and r1[0] == r2[0]:
        judge(l1, l2, tree1, tree2)
        judge(r1, r2, tree1, tree2)
    elif l1[0] == r2[0] and r1[0] == l2[0]:
        judge(l1, r2, tree1, tree2)
        judge(r1, l2, tree1, tree2)
    else:
        print('No')
        exit(0)

def deeper(node, tree):
    if not node[1] == '-':
        left = tree[node[1]]
    else:
        left = [None]
    if not node[2] == '-':
        right = tree[node[2]]
    else:
        right = [None]
    return left,right

judge(root1, root2, tree1, tree2)
print('Yes')

