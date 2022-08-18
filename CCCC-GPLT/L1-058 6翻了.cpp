#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
    getline(cin, s);
    for (int i = 0, cnt; i < (int)s.size(); i++) {
        if (s[i] != '6') cout << s[i];
        else {
            cnt = 1;
            while (i + cnt < (int)s.size() && s[i+cnt] == '6') cnt++;
            if (cnt <= 3) {
                for (int j = 0; j < cnt; j++) cout << '6';
            } else if (cnt <= 9) cout << '9';
            else cout << "27";
            i += cnt - 1;
        }
    }
    return 0;
}