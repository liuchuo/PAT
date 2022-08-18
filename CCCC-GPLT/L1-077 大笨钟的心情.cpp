#include <bits/stdc++.h>
using namespace std;
int t, a[30];
int main() {
    for (int i = 0; i < 24; i++) cin >> a[i];
    while (cin >> t) {
        if (t < 0 || t > 23) break;
        printf("%d %s\n", a[t], a[t] <= 50 ? "No" : "Yes");
    }
    return 0;
}