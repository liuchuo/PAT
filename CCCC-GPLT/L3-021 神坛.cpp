#include <bits/stdc++.h>
using namespace std;
int n, i, cnt;
long long ans = 1e17;
bool cmp (const pair<long long, long long> &a, const pair<long long, long long> &b) {
    if (a.first * b.second != b.first * a.second)
        return a.first * b.second > b.first * a.second;
    return a.first < b.first;
}
int main() {
    scanf("%d", &n);
    vector<pair<long long, long long>> A(n), B(n - 1);
    for (i = 0; i < n; i++) scanf("%lld %lld", &A[i].first, &A[i].second);
    for (i = 0; i < n; i++, cnt = 0) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            B[cnt++] = {A[j].first - A[i].first, A[j].second - A[i].second};
        }
        sort(B.begin(), B.end(), cmp);
        for (int j = 1; j < n - 1; ++j) ans = min(ans, abs(B[j - 1].first * B[j].second - B[j].first * B[j - 1].second));
    }
    printf("%.3f", 0.5 * ans);
    return 0;
}