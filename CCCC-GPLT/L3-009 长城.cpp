#include <bits/stdc++.h>
using namespace std;
long long n, top, ans, X[100005], Y[100005], tower[100005], vis[100005];
bool isConcave (const int &l, const int &mid, const int &r) {
    return (Y[r] - Y[l]) * (X[mid] - X[l]) >= (Y[mid] - Y[l]) * (X[r] - X[l]);
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i];
        if (top) {
            while (top > 1 && isConcave(i, tower[top], tower[top - 1])) top--;
            if (top != 1 && !vis[tower[top]]) vis[tower[top]] = 1, ans++;
        }
        tower[++top] = i;
    }
    cout << ans;
    return 0;
}