L1-017. 到底有多二
一个整数“犯二的程度”定义为该数字中包含2的个数与其位数的比值。如果这个数是负数，则程度增加0.5倍;如果还是个偶数，则再增加1倍。
例如数字“-13142223336”是个11位数，其中有3个2，并且是负数，也是偶数，则它的犯二程度计算为：3/11*1.5*2*100%，约为81.82%。本题就请你计算一个给定整数到底有多二。

输入格式：

输入第一行给出一个不超过50位的整数N。

输出格式：

在一行中输出N犯二的程度，保留小数点后两位。

输入样例：
-13142223336
输出样例：
81.82%

#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    string s;
    cin >> s;
    int flag = (s[0] == '-' ? 1 : 0);
    int len = s.length();
    int bit = len - flag;
    int cnt = 0;
    for(int i = 0; i < len; i++) {
        if(s[i] == '2')
            cnt++;
    }
    double ans = (double)cnt / bit * 100;
    if(flag == 1)
        ans = ans * 1.5;
    if((s[len-1] - '0') % 2 == 0)
        ans = ans * 2;
    printf("%.2f%%", ans);
    return 0;
}