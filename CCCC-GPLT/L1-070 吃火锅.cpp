#include <bits/stdc++.h>
using namespace std;
int sum, cnt, first;
string s;
int main() {
    while (getline(cin, s)) {
        if (s == ".") break;
        sum++;
        if (s.find("chi1 huo3 guo1") != -1) {
            if (!first) first = sum;
            cnt++;
        }
    }
    cout << sum << '\n';
    if (!cnt) cout << "-_-#";
    else cout << first << ' ' << cnt;
    return 0;
}