#include <cstdio>
using namespace std;
int n, flag = 0;
int result[21];
bool v[21][21], visit[21];
void dfs(int index, int num) {
    if (flag == 1) return;
    result[index] = num;
    if (index == n && v[num][1] == true) {
        flag = 1;
        return;
    }
    if (index == n) return;
    bool cut = false;
    for (int i = 1; i <= n; i++) {
        if (visit[i] == false && v[i][1] == true)
            cut = true;
    }
    if (cut == false) return;
    visit[num] = true;
    for (int i = 1; i <= n; i++) {
        if (visit[i] == false && v[num][i] == true)
            dfs(index + 1, i);
    }
    visit[num] = false;
}
int main() {
    scanf("%d", &n);
    char s[21];
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= n; j++) {
            if (s[j] == 'W') v[i][j] = true;
            if (s[j] == 'L') v[j][i] = true;
        }
    }
    dfs(1, 1);
    if (flag == 1) {
        for (int i = 1; i <= n; i++)
            printf("%s%d", i == 1 ? "" : " ", result[i]);
    } else {
        printf("No Solution");
    }
    return 0;
}