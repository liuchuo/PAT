#include <iostream>
using namespace std;
string s = "String", in;
int a[200], flag = 1;
int main() {
    cin >> in;
    for (auto it : in) a[it]++;
    while (flag) {
        flag = 0;
        for (int i = 0; i < 6; i++) {
            if (a[s[i]]) {
                cout << s[i];
                a[s[i]]--;
                flag = 1;
            }
        }
    }
    return 0;
}