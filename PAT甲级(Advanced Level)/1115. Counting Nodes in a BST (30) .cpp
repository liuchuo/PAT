1115. Counting Nodes in a BST (30)
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Insert a sequence of numbers into an initially empty binary search tree. Then you are supposed to count the total number of nodes in the lowest 2 levels of the resulting tree.
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (<=1000) which is the size of the input sequence. Then given in the next line are the N integers in [-1000 1000] which are supposed to be inserted into an initially empty binary search tree.
Output Specification:
For each case, print in one line the numbers of nodes in the lowest 2 levels of the resulting tree in the format:
n1 + n2 = n
where n1 is the number of nodes in the lowest level, n2 is that of the level above, and n is the sum.
Sample Input:
9
25 30 42 16 20 20 35 -5 28
Sample Output:
2 + 4 = 6

题目大意：输出一个二叉搜索树的最后两层结点个数，以及他们的和
分析：用链表存储，构建二叉搜索树，深度优先搜索，将每一层所对应的结点个数存储在数组num中，并标记最大深度maxdepth，输出数组的最后两个的值~~~~


#include <iostream>
#include <vector>
using namespace std;
struct node {
    int v;
    struct node *left, *right;
};
node* build(node *root, int v) {
    if(root == NULL) {
        root = new node();
        root->v = v;
        root->left = root->right = NULL;
    } else if(v <= root->v)
        root->left = build(root->left, v);
    else
        root->right = build(root->right, v);
    return root;
}
vector<int> num(1000);
int maxdepth = -1;
void dfs(node *root, int depth) {
    if(root == NULL) {
        maxdepth = max(depth, maxdepth);
        return ;
    }
    num[depth]++;
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
    
}
int main() {
    int n, t;
    scanf("%d", &n);
    node *root = NULL;
    for(int i = 0; i < n; i++) {
        scanf("%d", &t);
        root = build(root, t);
    }
    dfs(root, 0);
    printf("%d + %d = %d", num[maxdepth-1], num[maxdepth-2], num[maxdepth-1] + num[maxdepth-2]);
    return 0;
}