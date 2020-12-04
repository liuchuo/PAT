_ = input()

arr = list(map(int, input().split()))

class tree():
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.touched = False

def get_tree(arr):
    head = tree(arr[0])
    layer = [head]
    depth = 1
    from math import pow
    while layer:
        k = 0
        next_layer = []
        for node in layer:
            left_index = int(pow(2, depth) - 1 + k)
            if left_index < len(arr):
                left_node = tree(arr[left_index])
                node.left = left_node
                next_layer.append(left_node)

            if left_index + 1 < len(arr):
                right_node = tree(arr[left_index + 1])
                node.right = right_node
                next_layer.append(right_node)

            k += 2
        depth += 1
        layer = next_layer
    return head

def right_ord(head):
    is_heap = True
    if head.right:
        max_min = head.val - head.right.val
    if head.left:
        max_min = head.val - head.left.val

    ans = []
    path = [head.val]
    stack = [head]
    while stack:

        last_node = stack[-1]

        if last_node.right and not last_node.right.touched:
            path.append(last_node.right.val)
            stack.append(last_node.right)
            if (last_node.val - last_node.right.val) * (max_min) < 0:
                is_heap = False

        elif last_node.left and not last_node.left.touched:
            path.append(last_node.left.val)
            stack.append(last_node.left)
            if (last_node.val - last_node.left.val) * max_min < 0:
                is_heap = False
        else:
            last_node.touched = True
            stack.pop()
            if not last_node.right and not last_node.left:
                from copy import deepcopy
                ans.append(deepcopy(path))
            path.pop()
    return ans, is_heap, max_min

ans, is_heap, max_min = right_ord(head=get_tree(arr))

[print(' '.join(list(map(str, path)))) for path in ans ]

if is_heap:
    max_min = 'Max' if max_min > 0 else 'Min'
    print(max_min + ' Heap')
else:
    print('Not Heap')
