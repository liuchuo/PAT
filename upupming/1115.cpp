#include <iostream>

using namespace std;

int maxLevel, cnt1, cnt2;
int n, a;

class Node {
public:    
    int key, level;
    Node *left = nullptr, *right = nullptr;
    Node(int val, int level) {
        this->key = val;
        this->level = level;
        maxLevel = max(maxLevel, level);
    }
};

Node *add(Node *node, int val, int level) {
    if (node == nullptr) return new Node(val, level);
    if (val > node->key) node->right = add(node->right, val, level+1);
    else node->left = add(node->left, val, level+1);
    return node;
}

void solve(Node *node) {
    if (node == nullptr) return;
    if (node->level == maxLevel - 1) cnt1++;
    if (node->level == maxLevel) cnt2++;
    solve(node->left);
    solve(node->right);
}

int main() {
    cin >> n;
    Node *root = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> a;
        root = add(root, a, 0);
    }
    solve(root);
    cout << cnt2 << " + " << cnt1 << " = " << (cnt1 + cnt2) << endl;

    return 0;
}