n, _ = list(map(int, input().split()))

senquence_set = []

for i in range(n):
    senquence_set.append(list(map(int, input().split())))

def is_heap(senquence):
    max_or_min = senquence[0] - senquence[1]

    def deeper(start_of_layer, end_of_layer, senquence, max_or_min):
        layer = senquence[start_of_layer:end_of_layer]

        if 2 * len(layer) > len(senquence[end_of_layer:]):
            next_layer = senquence[end_of_layer:]
        else:
            next_layer = senquence[end_of_layer:end_of_layer + 2 * len(layer)]

        if not next_layer: return True

        i_of_node = 0

        for node in layer:
            left_of_node, right_of_node = i_of_node, i_of_node + 1

            if i_of_node < len(next_layer):
                if (node - next_layer[left_of_node]) * max_or_min < 0:
                    return False
            if i_of_node + 1 < len(next_layer):
                if (node - next_layer[right_of_node]) * max_or_min < 0:
                    return False
            i_of_node += 2

        return deeper(end_of_layer, end_of_layer + len(next_layer), senquence, max_or_min)

    return deeper(0,1,senquence,max_or_min), max_or_min,

class tree:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def get_Btree(array):
    import math
    depth = 1
    head = tree(array[0])
    layer = [head]
    while layer:
        k = 0
        tmp = []
        for node in layer:
            left_index = int(math.pow(2, depth) - 1 + k)
            if left_index < len(array):
                new_node = tree(array[left_index])
                node.left = new_node
                tmp.append(new_node)
            if left_index + 1 < len(array):
                new_node = tree(array[left_index + 1])
                node.right = new_node
                tmp.append(new_node)
            k += 2
        depth += 1
        layer = tmp
    return head

def postord(s, tree):
    if tree.left: postord(s, tree.left)
    if tree.right: postord(s, tree.right)
    s.append(tree.val)

def show_heap(senquence, is_heap_, max_or_min):
    if not is_heap_:
        print('Not Heap')
        tree = get_Btree(senquence)
        s = []
        postord(s, tree)
        print(' '.join(list(map(str, s))))
    else:
        if max_or_min > 0:
            print('Max Heap')
            tree = get_Btree(senquence)
            s = []
            postord(s, tree)
            print(' '.join(list(map(str, s))))
        else:
            print('Min Heap')
            tree = get_Btree(senquence)
            s = []
            postord(s, tree)
            print(' '.join(list(map(str, s))))

for senquence in senquence_set:
    is_heap_, max_or_min = is_heap(senquence)
    show_heap(senquence, is_heap_, max_or_min)
