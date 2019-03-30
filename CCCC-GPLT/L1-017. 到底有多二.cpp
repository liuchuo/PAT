#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    string s;
    cin >> s;
    int flag = (s[0] == '-' ? 1 : 0);
    int len = s.length();
    int bit = len - flag, cnt = 0;
    for(int i = 0; i < len; i++) {
        if(s[i] == '2') cnt++;
    }
    double ans = (double)cnt / bit * 100;
    if(flag == 1) ans = ans * 1.5;
    if((s[len-1] - '0') % 2 == 0) ans = ans * 2;
    printf("%.2f%%", ans);
    return 0;
}