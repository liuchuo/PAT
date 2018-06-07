1020. Tree Traversals (25)
Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.
Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
Sample Output:
4 1 6 3 5 7 2

题目大意：给定一棵二叉树的后序遍历和中序遍历，请你输出其层序遍历的序列。这里假设键值都是互不相等的正整数。

#include <iostream>
#include <vector>
using namespace std;
vector<int> post, in, level(100000, -1);
void pre(int root, int start, int end, int index) {
    if(start > end) return ;
    int i = start;
    while(i < end && in[i] != post[root]) i++;
    level[index] = post[root];
    pre(root - 1 - end + i, start, i - 1, 2 * index + 1);
    pre(root - 1, i + 1, end, 2 * index + 2);
}
int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    post.resize(n);
    in.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &post[i]);
    for(int i = 0; i < n; i++) scanf("%d", &in[i]);
    pre(n-1, 0, n-1, 0);
    for(int i = 0; i < level.size(); i++) {
        if (level[i] != -1) {
            if (cnt != 0) printf(" ");
            printf("%d", level[i]);
            cnt++;
        }
        if (cnt == n) break;
    }
    return 0;
}
