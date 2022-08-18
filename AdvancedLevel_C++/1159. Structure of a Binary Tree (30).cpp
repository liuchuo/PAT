#include<iostream>
using namespace std;
struct node {
    int lchild, rchild, parent, level;
    node() {
        lchild = rchild = parent = -1;
    }
}Tree[1002];
int n, m, a, b, root, f, Full;
int In[32], Post[32];
string t;
int deal(int R, int start, int end, int Pa) {
    if(start > end) return -1;
    int i = start;
    while(i < end && In[i] != Post[R]) i++;
    Tree[Post[R]].parent = Pa;
    Tree[Post[R]].level = Tree[Pa].level + 1;
    Tree[Post[R]].lchild = deal(R - 1 - end + i, start, i - 1, Post[R]);
    Tree[Post[R]].rchild = deal(R - 1, i + 1, end, Post[R]);
    if (Tree[Post[R]].lchild * Tree[Post[R]].rchild < 0) Full = 1;
    return Post[R];
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> Post[i];
    } 
    for (int i = 0; i < n; i++) 
        cin >> In[i];
    root = Post[n - 1];
    deal(n - 1, 0, n - 1, 1001);
    cin >> m;
    while (m--) {
        f = 0;
        cin >> t;
        if (t == "It") {
            cin >> t >> t >> t >> t;
            if (Full) cout << "No\n";
            else cout << "Yes\n";
            continue;
        } 
        a = stoi(t);
        cin >> t;
        if (t == "is") {
            cin >> t >> t;
            if (t == "root") {
                if (a == root) f = 1;
            } else if (t == "parent") {
                cin >> t >> b;
                if (Tree[b].parent == a) f = 1;
            } else if (t == "left") {
                cin >> t >> t >> b;
                if (Tree[b].lchild == a) f = 1;
            } else {
                cin >> t >> t >> b;
                if (Tree[b].rchild == a) f = 1;
            }
        } else {
            cin >> b >> t >> t;
            if (t == "siblings") {
                if (Tree[a].parent == Tree[b].parent) f = 1;
            } else {
                cin >> t >> t >> t;
                if (Tree[a].level == Tree[b].level) f = 1;
            }
        }
        cout << (f ? "Yes\n" : "No\n");
    }
    return 0;
}