#include <iostream>
using namespace std;
int main() {
    string chinese[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    string s;
    cin >> s;
    int len = s.length();
    int flag = s[0] == '-' ? 1 : 0;
    if(flag == 1) cout << "fu";
    for(int i = flag; i < len; i++) {
        if(i == 0) {
            cout << chinese[s[i] - '0'];
            continue;
        }
        cout << " " << chinese[s[i] - '0'];
    }
    return 0;
}