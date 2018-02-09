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

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> pre, post, arr;
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
void getPost(int root, int end) {
    if (root > end) return;
    int i = root + 1, j = end;
    while (i <= end && pre[root] > pre[i]) i++;
    while (j >= root + 1 && pre[root] <= pre[j]) j--;
    if (i != j + 1) return;
    getPost(root + 1, j);
    getPost(i, end);
    post.push_back(pre[root]);
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
        pre.resize(n);
        node *root = NULL;
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
            root = build(root, arr[j]);
            pre[j] = abs(arr[j]);
        }
        //Is it binary search tree?
        post.clear();
        getPost(0, n-1);
        if (post.size() != n) {
            printf("No\n");
            continue;
        }
        //arr[0] < 0: Is the root black?
        //judge1: If a node is red, are both its children black?
        //judge2: Do all simple paths from the node to descendant leaves contain the same number of black nodes?
        if (arr[0] < 0 || judge1(root) == false || judge2(root) == false)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
