1127. ZigZagging on a Tree (30)
Suppose that all the keys in a binary tree are distinct positive integers. A unique binary tree can be determined by a given pair of postorder and inorder traversal sequences. And it is a simple standard routine to print the numbers in level-order. However, if you think the problem is too simple, then you are too naive. This time you are supposed to print the numbers in "zigzagging order" -- that is, starting from the root, print the numbers level-by-level, alternating between left to right and right to left. For example, for the following tree you must output: 1 11 5 8 17 12 20 15.
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (<= 30), the total number of nodes in the binary tree. The second line gives the inorder sequence and the third line gives the postorder sequence. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print the zigzagging sequence of the tree in a line. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.
Sample Input:
8
12 11 20 17 1 15 8 5
12 20 17 11 15 8 5 1
Sample Output:
1 11 5 8 17 12 20 15

题目大意：给出一个树的中序和后序遍历结果，求它的Z字型层序遍历，也就是偶数层从右往左，奇数层从左往右遍历～
分析：分为3步：1.根据中序和后序建树 保存在tree二维数组中，比如：tree[i][0] = val表示post[i]的左孩子是post[val]，tree[i][1] = val表示post[i]的右孩子是post[val]～
2.进行广度优先搜索，将树从根结点开始所有结点层序遍历，保存在result二维数组中，比如：result[i]保存第i层所有结点的序列～
3.进行z字型输出，根据当前层号的奇偶性分别从左往右、从右往左遍历输出～

1. dfs：因为post(后序)是按照左、右、根的顺序遍历的，所以从右往左，最右边的肯定是根结点～所以postRight是当前子树的根结点的下标，将它的赋值给index，并继续dfs tree[index][0]和tree[index][1]～
根据post[postRight]的结点在in里面的下标位置i，可以得到i的左边是左子树，即inLeft 到 i - 1，右边是右子树：i + 1 到 inRight。而对于post来说，根据左子树的结点个数i - inLeft可以得到[postLeft, postLeft + (i - inLeft) - 1]是post中左子树的范围，[postLeft + (i - inLeft), postRight - 1]是post中右子树的范围～
2.广度优先搜索，采用队列q，q中保存的是node结点，node.index表示当前节点在post中的下标，node.depth表示当前结点在树中的层数～
3.当 i % 2 == 0的时候倒序输出，否则正序输出～

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> in, post, result[35];
int n, tree[35][2], root;
struct node {
    int index, depth;
};
void dfs(int &index, int inLeft, int inRight, int postLeft, int postRight) {
    if (inLeft > inRight) return;
    index = postRight;
    int i = 0;
    while (in[i] != post[postRight]) i++;
    dfs(tree[index][0], inLeft, i - 1, postLeft, postLeft + (i - inLeft) - 1);
    dfs(tree[index][1], i + 1, inRight, postLeft + (i - inLeft), postRight - 1);
}
void bfs() {
    queue<node> q;
    q.push(node{root, 0});
    while (!q.empty()) {
        node temp = q.front();
        q.pop();
        result[temp.depth].push_back(post[temp.index]);
        if (tree[temp.index][0] != 0)
            q.push(node{tree[temp.index][0], temp.depth + 1});
        if (tree[temp.index][1] != 0)
            q.push(node{tree[temp.index][1], temp.depth + 1});
    }
}
int main() {
    cin >> n;
    in.resize(n + 1), post.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> in[i];
    for (int i = 1; i <= n; i++) cin >> post[i];
    dfs(root, 1, n, 1, n);
    bfs();
    printf("%d", result[0][0]);
    for (int i = 1; i < 35; i++) {
        if (i % 2 == 1) {
            for (int j = 0; j < result[i].size(); j++)
                printf(" %d", result[i][j]);
        } else {
            for (int j = result[i].size() - 1; j >= 0; j--)
                printf(" %d", result[i][j]);
        }
    }
    return 0;
}