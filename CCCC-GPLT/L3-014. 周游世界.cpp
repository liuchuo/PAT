#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int>> v(10000);
int line[10000][10000], visit[10000];
vector<int> path, tempPath;
int transferCnt(vector<int> a) {
    int cnt = -1, preLine = 0;
    for (int i = 1; i < a.size(); i++) {
        if (line[a[i-1]][a[i]] != preLine) cnt++;
        preLine = line[a[i-1]][a[i]];
    }
    return cnt;
}
void dfs(int node, int end, int cnt, int &minCnt, int &minTransfer) {
    if (node == end && (cnt < minCnt || (cnt == minCnt && transferCnt(tempPath) < minTransfer))) {
        minCnt = cnt;
        minTransfer = transferCnt(tempPath);
        path = tempPath;
    }
    if (node == end) return;
    for (int i = 0; i < v[node].size(); i++) {
        if (visit[v[node][i]] == 0) {
            visit[v[node][i]] = 1;
            tempPath.push_back(v[node][i]);
            dfs(v[node][i], end, cnt + 1, minCnt, minTransfer);
            visit[v[node][i]] = 0;
            tempPath.pop_back();
        }
    }
}
int main() {
    int n, m, k, pre, temp, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &m, &pre);
        for (int j = 1; j < m; j++) {
            scanf("%d", &temp);
            v[pre].push_back(temp);
            v[temp].push_back(pre);
            line[pre][temp] = line[temp][pre] = i + 1;
            pre = temp;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &a, &b);
        int minCnt = 99999, minTransfer = 99999;
        tempPath.clear();
        tempPath.push_back(a);
        visit[a] = 1;
        dfs(a, b, 0, minCnt, minTransfer);
        visit[a] = 0;
        if (minCnt == 99999) {
            printf("Sorry, no line is available.\n");
            continue;
        }
        printf("%d\n", minCnt);
        int preLine = 0, preTransfer = a;
        for (int j = 1; j < path.size(); j++) {
            if (line[path[j-1]][path[j]] != preLine) {
                if (preLine != 0) printf("Go by the line of company #%d from %04d to %04d.\n", preLine, preTransfer, path[j-1]);
                preLine = line[path[j-1]][path[j]];
                preTransfer = path[j-1];
            }
        }
        printf("Go by the line of company #%d from %04d to %04d.\n", preLine, preTransfer, b);
    }
    return 0;
}