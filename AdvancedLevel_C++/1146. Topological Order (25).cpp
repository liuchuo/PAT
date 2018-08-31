#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m, a, b, k, flag = 0, in[1010];
    vector<int> v[1010];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        in[b]++;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int judge = 1;
        vector<int> tin(in, in+n+1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &a);
            if (tin[a] != 0) judge = 0;
            for (int it : v[a]) tin[it]--;
        }
        if (judge == 1) continue;
        printf("%s%d", flag == 1 ? " ": "", i);
        flag = 1;
    }
    return 0;
}