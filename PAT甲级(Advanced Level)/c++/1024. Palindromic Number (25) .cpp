1024. Palindromic Number (25)
A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.
Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.
Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it.
Input Specification:
Each input file contains one test case. Each case consists of two positive numbers N and K, where N (<= 10^10) is the initial numer and K (<= 100) is the maximum number of steps. The numbers are separated by a space.
Output Specification:
For each test case, output two numbers, one in each line. The first number is the paired palindromic number of N, and the second number is the number of steps taken to find the palindromic number. If the palindromic number is not found after K steps, just output the number obtained at the Kth step and K instead.
Sample Input 1:
67 3
Sample Output 1:
484
2
Sample Input 2:
69 3
Sample Output 2:
1353
3
题目大意：给定一个数字，和允许翻转后相加的次数cnt，求要多少次才能变成一个回文数字，输出那个回文数字和翻转相加了多少次，如果本身就是回文数字就输出0次，如果超过给定的次数cnt了，就输出那个不是回文的结果，并且输出给定的次数cnt
分析：1.会超出long int类型（会有两个点溢出错误），所以用字符串存储，大整数相加
2.可以通过对字符串翻转后比较来判断是否为回文串

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
void add() {
    string t = s;
    reverse(t.begin(), t.end());
    int len = s.length(), carry = 0;
    for(int i = 0; i < len; i++) {
        s[i] = s[i] + t[i] + carry - '0';
        carry = 0;
        if(s[i] > '9') {
            s[i] = s[i] - 10;
            carry = 1;
        }
    }
    if(carry) s += '1';
    reverse(s.begin(), s.end());
}
int main() {
    int cnt;
    cin >> s >> cnt;
    for(int i = 0; i <= cnt; i++) {
        string t = s;
        reverse(t.begin(), t.end());
        if(s == t) {
            cout << s << endl << i;
            return 0;
        }
        if(i != cnt) add();
    }
    cout << s << endl << cnt;
    return 0;
}
