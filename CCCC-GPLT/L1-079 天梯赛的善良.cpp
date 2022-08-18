#include <bits/stdc++.h>
using namespace std;
map<int, int> A;
int n, minn = INT_MAX, maxn = INT_MIN;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        A[t]++;
        if (minn > t) minn = t;
        if (maxn < t) maxn = t;
    }
    cout << minn << ' ' << A[minn] << '\n' << da << ' ' << A[maxn];
    return 0;
}