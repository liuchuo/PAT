#include <iostream>
using namespace std;
int main() {
    string s;
    while (cin >> s) 
        if(s.size() == 3 && s[2] == 'T') cout << s[0]-'A'+1;
    return 0;
}