n = int(input())
nums = list(map(int, input().split()))
nums.sort()

class tree:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def get_root(n):
    from math import log, pow
    c = int(log(n+1,2) - 1)
    k = pow(2, c+1) - 1
    return int(pow(2, c) - 1 + (((n - k) - pow(2, c)) if (n - k) > pow(2, c) else  0))

def get_Btree(array):
    if not array:return None
    if len(array) == 1:
        return tree(array[0])
    root = (get_root(len(array)))
    head = tree(array[-(root + 1)])
    head.left = get_Btree(array[:-(root+1)])
    head.right = get_Btree(array[-(root):]) if not root == 0 else []
    return head

tree = get_Btree(nums)
layer = [tree]
ans = []
while layer:
    layer_tmp = []
    for node in layer:
        ans.append(node.val)
        if node.left:layer_tmp.append(node.left)
        if node.right:layer_tmp.append(node.right)
    layer = layer_tmp

print(' '.join(list(map(str, ans))))