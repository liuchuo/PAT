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