1064. Complete Binary Search Tree (30)
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
A Complete Binary Tree (CBT) is a tree that is completely filled, with the possible exception of the bottom level, which is filled from left to right.
Now given a sequence of distinct non-negative integer keys, a unique BST can be constructed if it is required that the tree must also be a CBT. You are supposed to output the level order traversal sequence of this BST.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (<=1000). Then N distinct non-negative integer keys are given in the next line. All the numbers in a line are separated by a space and are no greater than 2000.
Output Specification:
For each test case, print in one line the level order traversal sequence of the corresponding complete binary search tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.
Sample Input:
10
1 2 3 4 5 6 7 8 9 0
Sample Output:
6 3 8 1 5 7 9 0 2 4

题目大意：给一串构成树的序列，已知该树是完全二叉搜索树，求它的层序遍历的序列
分析：总得概括来说，已知中序，可求root下标，可以求出层序。
1. 因为二叉搜索树的中序满足：是一组序列的从小到大排列，所以只需排序所给序列即可得到中序
2. 因为根据完全二叉树的结点数，可以求出它的根结点在中序中对应的下标
3. 如此，已知了中序，又可以根据结点数求出根结点的下标，就可以递归求出左右子树的根结点的下标
4. i结点的左孩子为2 * i + 1，右孩子2 * i + 2，就可以根据结点下标和中序数组赋值level数组
5. 最后输出所有结点的层序数组level

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> in, level;
void levelorder(int start, int end, int index) {
    if(start > end) return ;
    int n = end - start + 1;
    int l = log(n + 1) / log(2); // 除了最后一层的层数
    int leave = n - (pow(2, l) - 1);// 最后一层的叶子节点数
    int root = start + (pow(2, l - 1) - 1) + min((int)pow(2, l - 1), leave); // pow(2, l - 1) - 1是除了root结点所在层和最后一层外，左子树的结点个数，pow(2, l - 1) 是l+1层最多拥有的属于根结点左子树的结点个数，min(pow(2, l - 1), leave)是最后一个结点真正拥有的属于根结点左子树上的结点个数
    level[index] = in[root];
    levelorder(start, root - 1, 2 * index + 1);
    levelorder(root + 1, end, 2 * index + 2);
}
int main() {
    int n;
    scanf("%d", &n);
    in.resize(n);
    level.resize(n);
    for(int i = 0 ; i < n; i++)
        scanf("%d", &in[i]);
    sort(in.begin(), in.end());
    levelorder(0, n - 1, 0);
    printf("%d", level[0]);
    for(int i = 1; i < n; i++)
        printf(" %d", level[i]);
    return 0;
}
