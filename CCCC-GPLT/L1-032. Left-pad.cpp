#include <iostream>
#include <string.h>
using namespace std;
int main() {
    int cnt;
    char c;
    string s;
    cin >> cnt >> c;
    getchar();
    getline(cin, s);
    int len = s.length();
    if(len >= cnt) {
        cout << s.substr(s.size() - cnt);
    } else {
        for(int i = 0; i < cnt - len; i++) {
            cout << c;
        }
        cout << s;
    }
    return 0;
}