1102. Invert a Binary Tree (25)
The following is from Max Howell @twitter:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can't invert a binary tree on a whiteboard so fuck off.
Now it's your turn to prove that YOU CAN invert a binary tree!
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (<=10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N-1. Then N lines follow, each corresponds to a node from 0 to N-1, and gives the indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.
Output Specification:
For each test case, print in the first line the level-order, and then in the second line the in-order traversal sequences of the inverted tree. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.
Sample Input:
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
Sample Output:
3 7 2 6 4 0 5 1
6 5 7 4 3 2 0 1
题目大意：反转一棵二叉树，给出原二叉树的每个结点的左右孩子，输出它的层序和前序遍历
分析：
1. 反转二叉树就是存储的时候所有左右结点都交换。
2. 二叉树使用tree[i].left和tree[i].right存储每个结点的左右结点
3. 根结点是所有左右结点中没有出现的那个结点
4. 已知根结点，用队列广度优先搜索，队列里面元素出现的顺序就是层序遍历的结果，push_back到数组level里面
5. 已知根结点，用递归的方法可以把中序遍历的结果push_back到数组in里面


#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
vector<int> in;
struct TREE {
    int left, right;
};
vector<TREE> tree;
void inorder(int root) {
    if(tree[root].left == -1 && tree[root].right == -1) {
        in.push_back(root);
        return ;
    }
    if(tree[root].left != -1)
        inorder(tree[root].left);
    in.push_back(root);
    if(tree[root].right != -1)
        inorder(tree[root].right);
}
int main() {
    int n, root;
    scanf("%d", &n);getchar();
    tree.resize(n);
    vector<int> book(n);
    for(int i = 0; i < n; i++) {
        char c1, c2;
        scanf("%c %c", &c1, &c2);getchar();
        tree[i].right = (c1 == '-' ? -1 : (c1 - '0'));
        tree[i].left = (c2 == '-' ? -1 : (c2 - '0'));
        if(tree[i].left != -1)
            book[tree[i].left] = 1;
        if(tree[i].right != -1)
            book[tree[i].right] = 1;
    }
    for(int i = 0; i < n; i++) {
        if(book[i] == 0) {
            root = i;
            break;
        }
    }
    queue<int> q;
    q.push(root);
    vector<int> level;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        if(tree[node].left != -1)
            q.push(tree[node].left);
        if(tree[node].right != -1)
            q.push(tree[node].right);
        level.push_back(node);
    }
    for(int i = 0; i < n; i++)
        printf("%d%c", level[i], i == n - 1 ? '\n' : ' ');
    inorder(root);
    printf("%d", in[0]);
    for(int i = 1; i < n; i++)
        printf(" %d", in[i]);
    return 0;
}

