#include <iostream>
#include <string>
using namespace std;
bool func(string a);
int main() {
    int n, count = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        if (func(a)) count++;
    }
    if (count == 0) cout << "All passed";
    return 0;
}
bool func(string s) {
    int sum = 0, a[18];
    for (int i = 0; i < 17; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            a[i] = s[i] - '0';
        } else {
            cout << s << endl;
            return true;
            break;
        }
    }
    a[17] = (s[17] == 'X') ? 10 : (s[17] - '0');
    int b[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    for (int i = 0; i < 17; i++)
        sum = sum + a[i] * b[i];
    sum = sum % 11;
    int c[11] = {1, 0, 10, 9, 8, 7, 6, 5, 4, 3, 2};
    if (c[sum] != a[17]) {
        cout << s << endl;
        return true;
    }
    return false;
}