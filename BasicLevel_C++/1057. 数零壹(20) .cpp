#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int n = 0;
    for(int i = 0; i < s.length(); i++) {
        if(isalpha(s[i])) {
            s[i] = toupper(s[i]);
            n += (s[i] - 'A' + 1);
        }
    }
    int cnt0 = 0, cnt1 = 0;
    while(n != 0) {
        if(n % 2 == 0) {
            cnt0++;
        } else {
            cnt1++;
        }
        n = n / 2;
    }
    printf("%d %d", cnt0, cnt1);
    return 0;
}