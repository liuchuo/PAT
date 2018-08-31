#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string a[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string b[13] = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
void func1(string s) {
    int len = s.length(), num = 0;
    for (int i = 0; i < len; i++)
        num = num * 10 + (s[i] - '0');
    if (num / 13) {
        cout << b[num / 13];
        if (num % 13) cout << ' ' << a[num % 13];
    } else {
        cout << a[num % 13];
    }
}
void func2(string s) {
    int len = s.length(), num = 0;
    if (len == 4) {
        cout << 0;
        return;
    } else if (len == 3) {
        for (int i = 1; i <= 12; i++) {
            if (s == a[i]) {
                cout << i;
                return;
            }
            if (s == b[i]) {
                cout << i * 13;
                return;
            }
        }
    }
    else {
        string temp1 = s.substr(0, 3), temp2 = s.substr(4, 3);
        for (int i = 1; i <= 12; i++) {
            if (temp1 == b[i]) num += i * 13;
            if (temp2 == a[i]) num += i;
        }
        cout << num;
    }
    return;
}
int main() {
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        if (isdigit(s[0]))
            func1(s);
        else
            func2(s);
        cout << endl;
    }
    return 0;
}