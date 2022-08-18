#include <bits/stdc++.h>
using namespace std;
int n, m, cnt;
string s, ans;
int check(string a) {
    for (int i = 0; i < a.length(); i++)
        if (a.substr(i, 7) == "qiandao" || a.substr(i, 4) == "easy") return 1;
    return 0;
}
int main() {
    cin >> n >> m;
    getchar();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        if (check(s)) continue;
        else {
            if (cnt == m) ans = s;
            cnt++;
        }
    }
    if (cnt <= m) cout << "Wo AK le";
    else cout << ans;
    return 0;
}