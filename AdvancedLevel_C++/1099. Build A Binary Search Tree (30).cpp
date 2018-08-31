#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct TREE {
    int left, right, value;
};
vector<TREE> tree;
vector<int> v;
int t = 0;
void inorder(int root) {
    if(tree[root].left == -1 && tree[root].right == -1) {
        tree[root].value = v[t++];
        return ;
    }
    if(tree[root].left != -1) inorder(tree[root].left);
    tree[root].value = v[t++];
    if(tree[root].right != -1) inorder(tree[root].right);
}

int main() {
    int n;
    scanf("%d", &n);
    tree.resize(n);
    v.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d %d",&tree[i].left, &tree[i].right);
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    inorder(0);
    queue<int> q;
    q.push(0);
    printf("%d", tree[0].value);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        if(node != 0) printf(" %d", tree[node].value);
        if(tree[node].left != -1) q.push(tree[node].left);
        if(tree[node].right != -1) q.push(tree[node].right);
    }
    return 0;
}