#include <bits/stdc++.h>
using namespace std;
int n, m, temp, ans;
string s;
int main() {
    cin >> n >> m;
    while (m--) {
        temp = 1 << (n-1);
        ans = 1;
        cin >> s;
        for (auto &it : s) {
            if (it == 'n') ans += temp;
            temp >>= 1;
        }
        cout << ans << '\n';
    }
    return 0;
}