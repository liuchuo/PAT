#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int> > v;
int n, k;
double z, r, result = 0.0;
bool visit[100010];
void dfs(int index, double power) {
    if (visit[index] == true) {
        result += power * v[index][0];
        return;
    }
    for (int i = 0; i < v[index].size(); i++)
        dfs(v[index][i], power * (1 - r/100));
}
int main() {
    scanf("%d%lf%lf", &n, &z, &r);
    v.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        int temp;
        if (k == 0) {
            scanf("%d", &temp);
            v[i].push_back(temp);
            visit[i] = true;
        }
        for (int j = 0; j < k; j++) {
            scanf("%d", &temp);
            v[i].push_back(temp);
        }
    }
    dfs(0, z);
    printf("%d", (int)result);
    return 0;
}