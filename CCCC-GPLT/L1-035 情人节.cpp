#include <iostream>
using namespace std;
int main() {
    string a, b, str;
    int cnt = 0;
    while(cin >> str) {
        if (str == ".") break;
        cnt++;
        if (cnt == 2) a = str;
        if (cnt == 14) b = str;
    }
    if (cnt >= 14)
        cout << a << " and " << b << " are inviting you to dinner...";
    else if (cnt <= 1)
        cout << "Momo... No one is for you ...";
    else
        cout << a << " is the only one for you...";
    return 0;
}