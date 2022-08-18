#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
    cin >> s;
    if (s.length() == 4) {
        int a = (s[0] - '0') * 10 + s[1] - '0';
        printf("%d", a < 22 ? 20 : 19);
        cout << s[0] << s[1] << "-" << s[2] << s[3];
    } else {
        cout << s[0] << s[1] << s[2] << s[3] << "-" << s[4] << s[5]; 
    }
    return 0;
}