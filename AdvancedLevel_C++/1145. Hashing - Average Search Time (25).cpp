#include <iostream>
#include <vector>
using namespace std;
bool isprime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}
int main() {
    int tsize, n, m, a;
    scanf("%d %d %d", &tsize, &n, &m);
    while(!isprime(tsize)) tsize++;
    vector<int> v(tsize);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        int flag = 0;
        for (int j = 0; j < tsize; j++) {
            int pos = (a + j * j) % tsize;
            if (v[pos] == 0) {
                v[pos] = a;
                flag = 1;
                break;
            }
        }
        if (!flag) printf("%d cannot be inserted.\n", a);
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &a);
        for (int j = 0; j <= tsize; j++) {
            ans++;
            int pos = (a + j * j) % tsize;
            if (v[pos] == a || v[pos] == 0) break;
        }
    }
    printf("%.1lf\n", ans * 1.0 / m);
    return 0;
}