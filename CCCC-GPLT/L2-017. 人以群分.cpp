#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, sum = 0, half = 0;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        sum += v[i];
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n / 2; i++)
        half += v[i];
    printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d", (n + 1) / 2, n / 2, sum - 2 * half);
    return 0;
}