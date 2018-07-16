1099. Build A Binary Search Tree (30)
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
Given the structure of a binary tree and a sequence of distinct integer keys, there is only one way to fill these keys into the tree so that the resulting tree satisfies the definition of a BST. You are supposed to output the level order traversal sequence of that tree. The sample is illustrated by Figure 1 and 2.
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (<=100) which is the total number of nodes in the tree. The next N lines each contains the left and the right children of a node in the format "left_index right_index", provided that the nodes are numbered from 0 to N-1, and 0 is always the root. If one child is missing, then -1 will represent the NULL child pointer. Finally N distinct integer keys are given in the last line.
Output Specification:
For each test case, print in one line the level order traversal sequence of that tree. All the numbers must be separated by a space, with no extra space at the end of the line.
Sample Input:
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42
Sample Output:
58 25 82 11 38 67 45 73 42

题目大意：给出一棵二叉搜索树（给出每个结点的左右孩子），且已知根结点为0，求并且给出应该插入这个二叉搜索树的数值，求这棵二叉树的层序遍历
分析：
1. 用结构体left right value表示这棵树的结构，根据输入可知树tree[i]的left和right
2. 因为是二叉搜索树，所以中序遍历这棵树得到的结点顺序应该是给出的数值序列从小到大的排列顺序，所以把数值序列排序后，可以在中序遍历的时候直接赋值当前tree[root].value~~~
3. 然后用队列层序遍历这棵树，遍历的时候就可以输出~~~

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct TREE {
    int left, right, value;
};
vector<TREE> tree;
vector<int> v;
int t = 0;
void inorder(int root) {
    if(tree[root].left == -1 && tree[root].right == -1) {
        tree[root].value = v[t++];
        return ;
    }
    if(tree[root].left != -1)
        inorder(tree[root].left);
    tree[root].value = v[t++];
    if(tree[root].right != -1)
        inorder(tree[root].right);
}

int main() {
    int n;
    scanf("%d", &n);
    tree.resize(n);
    v.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d %d",&tree[i].left, &tree[i].right);
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    inorder(0);
    queue<int> q;
    q.push(0);
    printf("%d", tree[0].value);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        if(node != 0) printf(" %d", tree[node].value);
        if(tree[node].left != -1) q.push(tree[node].left);
        if(tree[node].right != -1) q.push(tree[node].right);
    }
    return 0;
}