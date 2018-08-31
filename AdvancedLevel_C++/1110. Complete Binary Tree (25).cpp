#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
struct TREE {
    int left, right;
};
int main() {
    int n, root = 0;
    scanf("%d", &n);
    vector<TREE> tree(n);
    vector<int> book(n);
    for(int i = 0; i < n; i++) {
        string l, r;
        cin >> l >> r;
        if(l == "-") {
            tree[i].left = -1;
        } else {
            tree[i].left = stoi(l);
            book[tree[i].left] = 1;
        }
        if(r == "-"){
            tree[i].right = -1;
        } else {
            tree[i].right = stoi(r);
            book[tree[i].right] = 1;
        }   
    }
    for(int i = 0; i < n; i++) {
        if(book[i] == 0) {
            root = i;
            break;
        }
    }
    queue<int> q;
    q.push(root);
    int cnt = 0, lastnode = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        if(node != -1) {
            lastnode = node;
            cnt++;
        }else {
            if(cnt != n)
                printf("NO %d", root);
            else
                printf("YES %d", lastnode);
            return 0;
        }
        q.push(tree[node].left);
        q.push(tree[node].right);
    }
    return 0;
}