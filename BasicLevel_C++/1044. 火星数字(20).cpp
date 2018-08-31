#include <iostream>
#include <string>
using namespace std;
void func1(string s);
void func2(string s);
int main() {
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        int leng = s.length();
        if (leng == 1 && s[0] == '0') {
            cout << "tret" << endl;
        } else {
            if (s[0] >= '0' && s[0] <= '9') {
                func1(s);
            } else {
                func2(s);
            }
        }
    }
    return 0;
}
void func1(string s) {
    string a[13] = {"###", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string b[13] = {"###", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    int len = s.length();
    int t;
    if (len == 1) {
        t = s[0] - '0';
    } else if(len == 2) {
        t = (s[0] - '0') * 10 + (s[1] - '0');
    } else {
        t = (s[0] - '0') * 100 + (s[1] - '0') * 10 + (s[2] - '0');
    }
    if (t <= 12) {
        cout << a[t] << endl;
    } else if (t % 13 == 0) {
        cout << b[t / 13] << endl;
    } else {
        cout << b[t / 13] << " " << a[t % 13] << endl;
    }
}
void func2(string s) {
    string a[13] = {"###", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string b[13] = {"###", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    int len = s.length();
    if (len == 3) {
        for (int j = 1; j <= 12; j++) {
            if (s[0] == a[j][0] && s[1] == a[j][1] && s[2] == a[j][2]) {
                cout << j << endl;
            } else if (s[0] == b[j][0] && s[1] == b[j][1] && s[2] == b[j][2]) {
                cout << 13 * j << endl;
            }
        }
    } else {
        int t1 = 0;
        int t2 = 0;
        for (int j = 1; j <= 12; j++) {
            if (s[0] == b[j][0] && s[1] == b[j][1] && s[2] == b[j][2]) {
                t1 = j;
            }
            if (s[4] == a[j][0] && s[5] == a[j][1] && s[6] == a[j][2]) {
                t2 = j;
            }
        }
        cout << t1 * 13 + t2 << endl;
    }
}