1079. 延迟的回文数 (20)
给定一个 k+1 位的正整数 N，写成 ak...a1a0 的形式，其中对所有 i 有 0 <= ai < 10 且 ak > 0。N 被称为一个回文数，当且仅当对所有 i 有 ai = ak-i。零也被定义为一个回文数。
非回文数也可以通过一系列操作变出回文数。首先将该数字逆转，再将逆转数与该数相加，如果和还不是一个回文数，就重复这个逆转再相加的操作，直到一个回文数出现。如果一个非回文数可以变出回文数，就称这个数为延迟的回文数。（定义翻译自 https://en.wikipedia.org/wiki/Palindromic_number）
给定任意一个正整数，本题要求你找到其变出的那个回文数。
输入格式：
输入在一行中给出一个不超过1000位的正整数。
输出格式：
对给定的整数，一行一行输出其变出回文数的过程。每行格式如下
A + B = C
其中A是原始的数字，B是A的逆转数，C是它们的和。A从输入的整数开始。重复操作直到C在10步以内变成回文数，这时在一行中输出“C is a palindromic number.”；或者如果10步都没能得到回文数，最后就在一行中输出“Not found in 10 iterations.”。
输入样例 1：
97152
输出样例 1：
97152 + 25179 = 122331
122331 + 133221 = 255552
255552 is a palindromic number.
输入样例 2：
196
输出样例 2：
196 + 691 = 887
887 + 788 = 1675
1675 + 5761 = 7436
7436 + 6347 = 13783
13783 + 38731 = 52514
52514 + 41525 = 94039
94039 + 93049 = 187088
187088 + 880781 = 1067869
1067869 + 9687601 = 10755470
10755470 + 07455701 = 18211171
Not found in 10 iterations.

分析：1 将字符串倒置与原字符串比较看是否相等可知s是否为回文串
2 字符串s和它的倒置t相加，只需从头到尾相加然后再倒置（记得要处理最后一个进位carry，如果有进位要在末尾+'1'）
3 倒置可采用algorithm头文件里面的函数reverse(s.begin(), s.end())直接对s进行倒置

#include <iostream>
#include <algorithm>
using namespace std;
string add(string a) {
    string b = a, ans;
    reverse(b.begin(), b.end());
    int len = a.length(), carry = 0;
    for (int i = 0; i < len; i++) {
        int num = (a[i] - '0' + b[i] - '0') + carry;
        carry = 0;
        if (num >= 10) {
            carry = 1;
            num = num - 10;
        }
        ans += char(num + '0');
    }
    if(carry == 1) ans += '1';
    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {
    string s;
    cin >> s;
    int cnt = 0;
    while (cnt < 10) {
        string t = s;
        reverse(t.begin(), t.end());
        if (t == s) {
            cout << s << " is a palindromic number.";
            break;
        } else {
            cout << s << " + " << t << " = " << add(s) << endl;
            s = add(s);
            cnt++;
        }
    }
    if (cnt == 10) cout << "Not found in 10 iterations.";
    return 0;
}