#include <iostream>
#include <cctype>
using namespace std;
int main() {
    string bad, should;
    getline(cin, bad);
    getline(cin, should);
    for (int i = 0, length = should.length(); i < length; i++) {
        if (bad.find(toupper(should[i])) != string::npos) continue;
        if (isupper(should[i]) && bad.find('+') != string::npos) continue;
        cout << should[i];
    }
    return 0;
}