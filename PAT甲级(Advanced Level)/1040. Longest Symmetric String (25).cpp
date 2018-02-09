1040. Longest Symmetric String (25)
Given a string, you are supposed to output the length of the longest symmetric sub-string. For example, given "Is PAT&TAP symmetric?", the longest symmetric sub-string is "s PAT&TAP s", hence you must output 11.
Input Specification:
Each input file contains one test case which gives a non-empty string of length no more than 1000.
Output Specification:
For each test case, simply print the maximum length in a line.
Sample Input:
Is PAT&TAP symmetric?
Sample Output:
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
