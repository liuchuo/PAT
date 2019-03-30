#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node {
    int val;
    struct node *left, *right;
};
node* leftRotate(node *tree) {
    node *temp = tree->right;
    tree->right = temp->left;
    temp->left = tree;
    return temp;
}
node* rightRotate(node *tree) {
    node *temp = tree->left;
    tree->left = temp->right;
    temp->right = tree;
    return temp;
}
node* leftRightRotate(node *tree) {
    tree->left = leftRotate(tree->left);
    return rightRotate(tree);
}
node* rightLeftRotate(node *tree) {
    tree->right = rightRotate(tree->right);
    return leftRotate(tree);
}
int getHeight(node *tree) {
    if (tree == NULL) return 0;
    int l = getHeight(tree->left);
    int r = getHeight(tree->right);
    return max(l, r) + 1;
}
node* insert(node *tree, int val) {
    if (tree == NULL) {
        tree = new node();
        tree->val = val;
    }else if (tree->val > val) {
        tree->left = insert(tree->left, val);
        int l = getHeight(tree->left), r = getHeight(tree->right);
        if (l - r >= 2) {
            if (val < tree->left->val)
                tree = rightRotate(tree);
            else
                tree = leftRightRotate(tree);
        }
    } else {
        tree->right = insert(tree->right, val);
        int l = getHeight(tree->left), r = getHeight(tree->right);
        if (r - l >= 2) {
            if (val > tree->right->val)
                tree = leftRotate(tree);
            else
                tree = rightLeftRotate(tree);
        }
    }
    return tree;
}
int isComplete = 1, after = 0;
vector<int> levelOrder(node *tree) {
    vector<int> v;
    queue<node *> queue;
    queue.push(tree);
    while (!queue.empty()) {
        node *temp = queue.front();
        queue.pop();
        v.push_back(temp->val);
        if (temp->left != NULL) {
            if (after) isComplete = 0;
            queue.push(temp->left);
        } else {
            after = 1;
        }
        if (temp->right != NULL) {
            if (after) isComplete = 0;
            queue.push(temp->right);
        } else {
            after = 1;
        }
    }
    return v;
}
int main() {
    int n, temp;
    scanf("%d", &n);
    node *tree = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        tree = insert(tree, temp);
    }
    vector<int> v = levelOrder(tree);
    for (int i = 0; i < v.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", v[i]);
    }
    printf("\n%s", isComplete ? "YES" : "NO");
    return 0;
}