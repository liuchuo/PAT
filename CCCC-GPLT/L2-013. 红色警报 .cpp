#include <cstdio>
#include <algorithm>
using namespace std;
bool visit[510];
int e[510][510], n, m, k;
void dfs(int node) {
    visit[node] = true;
    for(int i = 0; i < n; i++) {
        if(visit[i] == false && e[node][i] == 1)
            dfs(i);
    }
}
int countcnt() {
    int cnt = 0;
    fill(visit, visit + 510, false);
    for(int i = 0; i < n; i++) {
        if(visit[i] == false) {
            dfs(i);
            cnt++;
        }
    }
    return cnt;
}
int main() {
    scanf("%d%d", &n, &m);
    int a, b, city;
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        e[a][b] = e[b][a] = 1;
    }
    int cnt = countcnt();
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d", &city);
        for(int j = 0; j < n; j++) {
            if(e[city][j] == 1) {
                e[city][j] = 0;
                e[j][city] = 0;
            }
        }
        int tempcnt = countcnt();
        if(tempcnt > cnt + 1)
            printf("Red Alert: City %d is lost!\n", city);
        else
            printf("City %d is lost.\n", city);
        cnt = tempcnt;
        if(i == n - 1) printf("Game Over.\n");
    }
    return 0;
}