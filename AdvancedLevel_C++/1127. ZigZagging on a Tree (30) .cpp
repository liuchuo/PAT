#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> in, post, result[35];
int n, tree[35][2], root;
struct node {
    int index, depth;
};
void dfs(int &index, int inLeft, int inRight, int postLeft, int postRight) {
    if (inLeft > inRight) return;
    index = postRight;
    int i = 0;
    while (in[i] != post[postRight]) i++;
    dfs(tree[index][0], inLeft, i - 1, postLeft, postLeft + (i - inLeft) - 1);
    dfs(tree[index][1], i + 1, inRight, postLeft + (i - inLeft), postRight - 1);
}
void bfs() {
    queue<node> q;
    q.push(node{root, 0});
    while (!q.empty()) {
        node temp = q.front();
        q.pop();
        result[temp.depth].push_back(post[temp.index]);
        if (tree[temp.index][0] != 0)
            q.push(node{tree[temp.index][0], temp.depth + 1});
        if (tree[temp.index][1] != 0)
            q.push(node{tree[temp.index][1], temp.depth + 1});
    }
}
int main() {
    cin >> n;
    in.resize(n + 1), post.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> in[i];
    for (int i = 1; i <= n; i++) cin >> post[i];
    dfs(root, 1, n, 1, n);
    bfs();
    printf("%d", result[0][0]);
    for (int i = 1; i < 35; i++) {
        if (i % 2 == 1) {
            for (int j = 0; j < result[i].size(); j++)
                printf(" %d", result[i][j]);
        } else {
            for (int j = result[i].size() - 1; j >= 0; j--)
                printf(" %d", result[i][j]);
        }
    }
    return 0;
}