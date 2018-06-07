1136. A Delayed Palindrome (20)
Consider a positive integer N written in standard notation with k+1 digits ai as ak...a1a0 with 0 <= ai < 10 for all i and ak > 0. Then N is palindromic if and only if ai = ak-i for all i. Zero is written 0 and is also palindromic by definition.
Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. Such number is called a delayed palindrome. (Quoted from https://en.wikipedia.org/wiki/Palindromic_number)
Given any positive integer, you are supposed to find its paired palindromic number.
Input Specification:
Each input file contains one test case which gives a positive integer no more than 1000 digits.
Output Specification:
For each test case, print line by line the process of finding the palindromic number. The format of each line is the following:
A + B = C
where A is the original number, B is the reversed A, and C is their sum. A starts being the input number, and this process ends until C becomes a palindromic number -- in this case we print in the last line "C is a palindromic number."; or if a palindromic number cannot be found in 10 iterations, print "Not found in 10 iterations." instead.
Sample Input 1:
97152
Sample Output 1:
97152 + 25179 = 122331
122331 + 133221 = 255552
255552 is a palindromic number.
Sample Input 2:
196
Sample Output 2:
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