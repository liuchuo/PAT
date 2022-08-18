#include <bits/stdc++.h>
using namespace std;
struct node {
    int pos;
    vector<int> Path;
};
int n, m, now = 1;
vector<int> temp, Edge[100005];
vector<node> Save(105);
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int t2;
            scanf("%d", &t2);
            Edge[i].push_back(t2);
        }
    }
    temp.push_back(1);
    for (int i = 1; i <= m; i++) {
        int c, J;
        scanf("%d%d", &c, &J);
        if (c == 0) {
            temp.push_back(Edge[now][J-1]);
            now = Edge[now][J - 1];
        } else if (c == 1) {
            Save[J].pos = now;
            Save[J].Path = temp;
            printf("%d\n", now);
        } else {
            now = Save[J].pos;
            temp = Save[J].Path;
        }
    }
    printf("%d", temp.back());
    return 0;
}