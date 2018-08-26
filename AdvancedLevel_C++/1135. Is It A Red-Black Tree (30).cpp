1135. Is It A Red-Black Tree (30)
There is a kind of balanced binary search tree named red-black tree in the data structure. It has the following 5 properties:
(1) Every node is either red or black.
(2) The root is black.
(3) Every leaf (NULL) is black.
(4) If a node is red, then both its children are black.
(5) For each node, all simple paths from the node to descendant leaves contain the same number of black nodes.
For example, the tree in Figure 1 is a red-black tree, while the ones in Figure 2 and 3 are not.
For each given binary search tree, you are supposed to tell if it is a legal red-black tree.
Input Specification:
Each input file contains several test cases. The first line gives a positive integer K (<=30) which is the total number of cases. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the preorder traversal sequence of the tree. While all the keys in a tree are positive integers, we use negative signs to represent red nodes. All the numbers in a line are separated by a space. The sample input cases correspond to the trees shown in Figure 1, 2 and 3.
Output Specification:
For each test case, print in a line "Yes" if the given tree is a red-black tree, or "No" if not.
Sample Input:
3
9
7 -2 1 5 -4 -11 8 14 -15
9
11 -2 1 -7 5 -4 8 14 -15
8
10 -7 5 -6 8 15 -11 17
Sample Output:
Yes
No
No

题目大意：给一个二叉搜索树的前序遍历，判断它是否为红黑树，是输出Yes，否则输出No。

分析：判断以下几点：
1.根结点是否为黑色 
2.如果一个结点是红色，它的孩子节点是否都为黑色 
3.从任意结点到叶子结点的路径中，黑色结点的个数是否相同
所以分为以下几步：
0. 根据先序建立一棵树，用链表表示
1. 判断根结点（题目所给先序的第一个点即根结点）是否是黑色【arr[0] < 0】
2. 根据建立的树，从根结点开始遍历，如果当前结点是红色，判断它的孩子节点是否为黑色，递归返回结果【judge1函数】
3. 从根节点开始，递归遍历，检查每个结点的左子树的高度和右子树的高度（这里的高度指黑色结点的个数），比较左右孩子高度是否相等，递归返回结果【judge2函数】

注意：终于知道自己PAT考试的时候错在哪了。。。维基百科定义：红黑树（英语：Red–black tree）是一种自平衡二叉查找树。AVL树：在计算机科学中，AVL树是最先发明的自平衡二叉查找树。在AVL树中任何节点的两个子树的高度最大差别为1，所以它也被称为高度平衡树。所以说红黑树不是一种AVL树，红黑树相对于AVL树来说，牺牲了部分平衡性以换取插入/删除操作时少量的旋转操作，整体来说性能要优于AVL树。而我根据先序遍历直接建树后判断了是否AVL平衡，把判断是否平衡的那段代码注释掉就AC了～

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> arr;
struct node {
    int val;
    struct node *left, *right;
};
node* build(node *root, int v) {
    if(root == NULL) {
        root = new node();
        root->val = v;
        root->left = root->right = NULL;
    } else if(abs(v) <= abs(root->val))
        root->left = build(root->left, v);
    else
        root->right = build(root->right, v);
    return root;
}
bool judge1(node *root) {
    if (root == NULL) return true;
    if (root->val < 0) {
        if (root->left != NULL && root->left->val < 0) return false;
        if (root->right != NULL && root->right->val < 0) return false;
    }
    return judge1(root->left) && judge1(root->right);
}
int getNum(node *root) {
    if (root == NULL) return 0;
    int l = getNum(root->left);
    int r = getNum(root->right);
    return root->val > 0 ? max(l, r) + 1 : max(l, r);
}
bool judge2(node *root) {
    if (root == NULL) return true;
    int l = getNum(root->left);
    int r = getNum(root->right);
    if(l != r) return false;
    return judge2(root->left) && judge2(root->right);
}
int main() {
    int k, n;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &n);
        arr.resize(n);
        node *root = NULL;
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
            root = build(root, arr[j]);
        }
        if (arr[0] < 0 || judge1(root) == false || judge2(root) == false)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
