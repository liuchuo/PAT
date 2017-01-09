1123. Is It a Complete AVL Tree (30)

An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Figures 1-4 illustrate the rotation rules.
Now given a sequence of insertions, you are supposed to output the level-order traversal sequence of the resulting AVL tree, and to tell if it is a complete binary tree.
Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<= 20). Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.

Output Specification:

For each test case, insert the keys one by one into an initially empty AVL tree. Then first print in a line the level-order traversal sequence of the resulting AVL tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line. Then in the next line, print “YES” if the tree is complete, or “NO” if not.

Sample Input 1:
5
88 70 61 63 65

Sample Output 1:
70 63 88 61 65
YES
Sample Input 2:
88 70 61 96 120 90 65 68

Sample Output 2:
88 65 96 61 70 90 120 68
NO
分析：这道题实际上考察AVL树和层序遍历两个知识点。
判断是不是完全二叉树，就看在出现了一个孩子为空的结点之后是否还会出现孩子结点不为空的结点，如果出现了就不是完全二叉树。
AVL树一共有四种情况，这里我把发现树不平衡的那个结点叫做A结点，A发现树不平衡的情况有四种：
新来的结点插入到A的左子树的左子树
新来的结点插入到A的左子树的右子树
新来的结点插入到A的右子树的左子树
新来的结点插入到A的右子树的右子树
发现不平衡时就需要处理，第1种情况只要简单的右旋，第4种情况只需左旋一下，第2种情况需要先对A的左子树左旋一下，然后对A右旋，同理第3种情况需要对A的右子树右旋一下，然后对A左旋，代码如下：

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int val;
    struct Node *left, *right;
};

struct Node* leftRotate(struct Node *tree) {
    struct Node *temp = tree->right;
    tree->right = temp->left;
    temp->left = tree;
    return temp;
}

struct Node* rightRotate(struct Node *tree) {
    struct Node *temp = tree->left;
    tree->left = temp->right;
    temp->right = tree;
    return temp;
}

int getHeight(struct Node *tree) {
    if (tree == NULL) {
        return 0;
    } else {
        int l = getHeight(tree->left);
        int r = getHeight(tree->right);
        return l > r ? l + 1 : r + 1;
    }
}

struct Node* leftRightRotate(struct Node *tree) {
    tree->left = leftRotate(tree->left);
    tree = rightRotate(tree);
    return tree;
}

struct Node* rightLeftRotate(struct Node *tree) {
    tree->right = rightRotate(tree->right);
    tree = leftRotate(tree);
    return tree;
}

struct Node* insert(struct Node *tree, int val) {
    if (tree == NULL) {
        tree = new struct Node();
        tree->val = val;
        return tree;
    }
    if (tree->val > val) {
        tree->left = insert(tree->left, val);
        int l = getHeight(tree->left);
        int r = getHeight(tree->right);
        if (l - r >= 2) {
            if (val < tree->left->val) {
                tree = rightRotate(tree);
            } else {
                tree = leftRightRotate(tree);
            }
        }
    } else {
        tree->right = insert(tree->right, val);
        int l = getHeight(tree->left);
        int r = getHeight(tree->right);
        if (r - l >= 2) {
            if (val > tree->right->val) {
                tree = leftRotate(tree);
            } else {
                tree = rightLeftRotate(tree);
            }
        }
    }
    return tree;
}

int isComplete = 1, after = 0;

vector<int> levelOrder(struct Node *tree) {
    vector<int> v;
    queue<struct Node *> queue;
    queue.push(tree);
    while (queue.size() != 0) {
        struct Node *temp = queue.front();
        queue.pop();
        v.push_back(temp->val);
        if (temp->left != NULL) {
            if (after) {
                isComplete = 0;
            }
            queue.push(temp->left);
        } else {
            after = 1;
        }
        if (temp->right != NULL) {
            if (after) {
                isComplete = 0;
            }
            queue.push(temp->right);
        } else {
            after = 1;
        }
    }

    return v;
}

void print(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        if (i == 0) {
            printf("%d", v[i]);
        } else {
            printf(" %d", v[i]);
        }
    }
    printf("\n");
}

int main() {
    int n = 0;
    scanf("%d", &n);
    struct Node *tree = NULL;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        scanf("%d", &temp);
        tree = insert(tree, temp);
    }

    vector<int> v = levelOrder(tree);
    print(v);
    if (isComplete) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}