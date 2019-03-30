#include <iostream>
#include <set>
using namespace std;
int main() {
    int a, b, c;
    cin >> a;
    set<string> s, ans;
    string str;
    for(int i = 0; i < a; i++) {
        cin >> b;
        if(b >= 2) {
            for(int j = 0; j < b; j++) {
                cin >> str;
                s.insert(str);
            }
        } else {
            cin >> str;
        }
    }
    cin >> c;
    int flag = 0;
    for(int i = 0; i < c; i++) {
        cin >> str;
        if(s.find(str) == s.end() && ans.find(str) == ans.end()) {
            ans.insert(str);
            if(flag == 1)
                cout << " ";
            cout << str;
            flag = 1;
        }
    }
    if(flag == 0)
        cout << "No one is handsome";
    return 0;
}