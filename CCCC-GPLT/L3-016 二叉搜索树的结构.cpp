#include <bits/stdc++.h>
using namespace std;
struct node {
    int num, lchild, rchild, parent, level;
    node() {
        lchild = rchild = parent = -1;
    }
}Tree[128];
int n, m, a, b, in, cnt, root = 1, f;
map<int, int> Find;
string t;
void insert(int x) {
    int now = root;
    while(Tree[now].num != x) {
        if (x < Tree[now].num) {
            if (Tree[now].lchild == -1) {
                Tree[cnt].num = x;
                Tree[cnt].level = Tree[now].level + 1;
                Tree[cnt].parent = now;
                Tree[now].lchild = cnt;
            }
            now = Tree[now].lchild;
        } else {
            if (Tree[now].rchild == -1) {
                Tree[cnt].num = x;
                Tree[cnt].level = Tree[now].level + 1;
                Tree[cnt].parent = now;
                Tree[now].rchild = cnt;
            }
            now = Tree[now].rchild;
        }
    }
}
int main() {
    cin >> n >> in;
    Tree[++cnt].num = in;
    Find[in] = cnt;
    for (int i = 1; i < n; i++) {
        cin >> in;
        Find[in] = ++cnt;
        insert(in);
    }
    cin >> m;
    while (m--) {
        f = 0;
        cin >> a >> t;
        if (t == "is") {
            cin >> t >> t;
            if (t == "root") {
                if (Find[a] == root) f = 1;
            } else if (t == "parent") {
                cin >> t >> b;
                if (Tree[Find[b]].parent == Find[a]) f = 1;
            } else if (t == "left") {
                cin >> t >> t >> b;
                if (Tree[Find[b]].lchild == Find[a]) f = 1;
            } else {
                cin >> t >> t >> b;
                if (Tree[Find[b]].rchild == Find[a]) f = 1;
            }
        } else {
            cin >> b >> t >> t;
            if (t == "siblings") {
                if (Find[a] && Find[b] && Tree[Find[a]].parent == Tree[Find[b]].parent) f = 1;
            } else {
                cin >> t >> t >> t;
                if (Find[a] && Find[b] && Tree[Find[a]].level == Tree[Find[b]].level) f = 1;
            }
        }
        cout << (f ? "Yes" : "No") << '\n';
    }
    return 0;
}