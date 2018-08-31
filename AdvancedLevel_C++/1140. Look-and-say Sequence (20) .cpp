#include <iostream>
using namespace std;
int main() {
    string s;
    int n, j;
    cin >> s >> n;
    for (int cnt = 1; cnt < n; cnt++) {
        string t;
        for (int i = 0; i < s.length(); i = j) {
            for (j = i; j < s.length() && s[j] == s[i]; j++);
            t += to_string((s[i] - '0')) + to_string(j - i);
        }
        s = t;
    }
    cout << s;
    return 0;
}