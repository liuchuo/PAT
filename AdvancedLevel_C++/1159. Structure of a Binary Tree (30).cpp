#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int key, level;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int key) : key(key) {}
};

bool is_full = true;
unordered_map<int, TreeNode*> nodes;

TreeNode* Build(int* postorder, int* inorder, int n) {
    if (n <= 0) return nullptr;
    TreeNode* root = new TreeNode(postorder[n - 1]);
    nodes[root->key] = root;
    int i;
    for (i = 0; i < n && inorder[i] != root->key; i++);
    root->left  = Build(postorder, inorder, i);
    root->right = Build(postorder + i, inorder + i + 1, n - i - 1);
    if (root->left)  root->left->parent  = root;
    if (root->right) root->right->parent = root;
    return root;
}

void Traversal(TreeNode* root) {
    if (!root) return;
    if (root->parent) root->level = root->parent->level + 1;
    if (root->left && !root->right) is_full = false;
    if (!root->left && root->right) is_full = false;
    Traversal(root->left);
    Traversal(root->right);
}

int main() {
    int n, m;
    cin >> n;
    int* postorder = new int[n];
    int* inorder   = new int[n];
    for (int i = 0; i < n; i++) cin >> postorder[i];
    for (int i = 0; i < n; i++) cin >> inorder[i];
    TreeNode* root = Build(postorder, inorder, n);
    root->level = 1;
    Traversal(root);
    cin >> m; getchar();
    while (m--) {
        bool flag;
        int a, b;
        string statement;
        getline(cin, statement);
        if (statement.find("root") != string::npos) {
            sscanf(statement.c_str(), "%d is the root", &a);
            flag = (a == root->key);
        } else if (statement.find("siblings") != string::npos) {
            sscanf(statement.c_str(), "%d and %d are siblings", &a, &b);
            flag = (nodes[a]->parent == nodes[b]->parent);
        } else if (statement.find("parent") != string::npos) {
            sscanf(statement.c_str(), "%d is the parent of %d", &a, &b);
            flag = (nodes[b]->parent == nodes[a]);
        } else if (statement.find("left child") != string::npos) {
            sscanf(statement.c_str(), "%d is the left child of %d", &a, &b);
            flag = (nodes[b]->left == nodes[a]);
        } else if (statement.find("right child") != string::npos) {
            sscanf(statement.c_str(), "%d is the right child of %d", &a, &b);
            flag = (nodes[b]->right == nodes[a]);
        } else if (statement.find("same level") != string::npos) {
            sscanf(statement.c_str(), "%d and %d are on the same level", &a, &b);
            flag = (nodes[a]->level == nodes[b]->level);
        } else {
            flag = is_full;
        }
        cout << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}