L2-008. 最长对称子串
对给定的字符串，本题要求你输出最长对称子串的长度。例如，给定"Is PAT&TAP symmetric?"，最长对称子串为"s PAT&TAP s"，于是你应该输出11。

输入格式：

输入在一行中给出长度不超过1000的非空字符串。

输出格式：

在一行中输出最长对称子串的长度。

输入样例：
Is PAT&TAP symmetric?
输出样例：
11

分析：有两种可能，一种是回文字符串的长度为奇数，一种是偶数的情况。i为字符串当前字符的下标。
当回文字串为奇数的时候，j表示i-j与i+j构成的回文字串长度；当回文字串长度为偶数的时候，j表示i+1左边j个字符一直到i右边j个字符的回文字串长度~~~
用maxvalue保存遍历结果得到的最大值并且输出~~

#include <iostream>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int maxvalue = 0, temp;
    int len = s.length();
    for(int i = 0; i < len; i++) {
        temp = 1;
        for(int j = 1; j < len; j++) {
            if(i - j < 0 || i + j >= len || s[i - j] != s[i + j])
                break;
            temp += 2;
        }
        maxvalue = temp > maxvalue ? temp : maxvalue;
        temp = 0;
        for(int j = 1; j < len; j++) {
            if(i - j + 1 < 0 || i + j >= len || s[i - j + 1] != s[i + j])
                break;
            temp += 2;
        }
        maxvalue = temp > maxvalue ? temp : maxvalue;
    }
    cout << maxvalue;
    return 0;
}