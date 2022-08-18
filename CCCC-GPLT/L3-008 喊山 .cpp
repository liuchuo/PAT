#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> v(10010);
int book[10010];
int main() {
    int n, m, k, a, b;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 0; i < k; i++) {
        scanf("%d", &a);
        queue<int> q;
        fill(book, book + 10010, 0);
        q.push(a);
        int level[10010];
        int ans = 10010, maxlevel = 0;
        book[a] = 1;
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            if(level[top] > maxlevel) {
                maxlevel = level[top];
                ans = 10010;
            }
            if(top != a)
                ans = min(ans, top);
            for(int j = 0; j < v[top].size(); j++) {
                if(book[v[top][j]] == 0) {
                    q.push(v[top][j]);
                    book[v[top][j]] = 1;
                    level[v[top][j]] = level[top] + 1;
                }
            }
        }
        if(ans != 10010) printf("%d\n", ans);
        else printf("0\n");
    }
    return 0;
}