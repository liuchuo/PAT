1066. Root of AVL Tree (25)
An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Figures 1-4 illustrate the rotation rules.
Now given a sequence of insertions, you are supposed to tell the root of the resulting AVL tree.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (<=20) which is the total number of keys to be inserted. Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print ythe root of the resulting AVL tree in one line.
Sample Input 1:
5
88 70 61 96 120
Sample Output 1:
70
Sample Input 2:
7
88 70 61 96 120 90 65
Sample Output 2:
88

#include <iostream>
using namespace std;
struct node {
    int val;
    struct node *left, *right;
};
node *rotateLeft(node *root) {
    node *t = root->right;
    root->right = t->left;
    t->left = root;
    return t;
}
node *rotateRight(node *root) {
    node *t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}
node *rotateLeftRight(node *root) {
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}
node *rotateRightLeft(node *root) {
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}
int getHeight(node *root) {
    if(root == NULL) return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}
node *insert(node *root, int val) {
    if(root == NULL) {
        root = new node();
        root->val = val;
        root->left = root->right = NULL;
    } else if(val < root->val) {
        root->left = insert(root->left, val);
        if(getHeight(root->left) - getHeight(root->right) == 2)
            root = val < root->left->val ? rotateRight(root) : rotateLeftRight(root);
    } else {
        root->right = insert(root->right, val);
        if(getHeight(root->left) - getHeight(root->right) == -2)
            root = val > root->right->val ? rotateLeft(root) : rotateRightLeft(root);
    }
    return root;
}
int main() {
    int n, val;
    scanf("%d", &n);
    node *root = NULL;
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("%d", root->val);
    return 0;
}
