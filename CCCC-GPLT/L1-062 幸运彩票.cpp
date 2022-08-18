#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
    cin >> s;
    while (cin >> s) {
        if (s[0] + s[1] + s[2] == s[3] + s[4] + s[5]) cout << "You are lucky!\n";
        else cout << "Wish you good luck.\n";
    }
    return 0;
}