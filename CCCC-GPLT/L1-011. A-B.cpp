#include <iostream>
using namespace std;
int book[256];
int main() {
    string s, a;
    getline(cin, s);
    getline(cin, a);
    for(int i = 0; i < a.length(); i++) book[a[i]] = 1;
    for(int i = 0; i < s.length(); i++) {
        if(book[s[i]] == 1) continue;
        cout << s[i];
    }
    return 0;
}