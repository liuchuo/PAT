1038. Recover the Smallest Number (30)
Given a collection of number segments, you are supposed to recover the smallest number from them. For example, given {32, 321, 3214, 0229, 87}, we can recover many numbers such like 32-321-3214-0229-87 or 0229-32-87-321-3214 with respect to different orders of combinations of these segments, and the smallest number is 0229-321-3214-32-87.
Input Specification:
Each input file contains one test case. Each case gives a positive integer N (<=10000) followed by N number segments. Each segment contains a non-negative integer of no more than 8 digits. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print the smallest number in one line. Do not output leading zeros.
Sample Input:
5 32 321 3214 0229 87
Sample Output:
22932132143287
题目大意：给一些字符串，求它们拼接起来构成最小数字的方式
分析：贪心算法。不是按照字典序排列就可以的，必须保证两个字符串构成的数字是最小的才行，所以cmp函数写成return a + b < b + a;的形式，保证它排列按照能够组成的最小数字的形式排列。
因为字符串可能前面有0，这些要移除掉。输出拼接后的字符串即可。
注意：如果移出了0之后发现s.length() == 0了，说明这个数是0，那么要特别地输出这个0，否则会什么都不输出。

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp0(string a, string b) {
    return a + b < b + a;
}
string str[10010];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        cin >> str[i];
    sort(str, str + n, cmp0);
    string s;
    for(int i = 0; i < n; i++)
        s += str[i];
    while(s.length() != 0 && s[0] == '0')
        s.erase(s.begin());
    if(s.length() == 0)
        cout << 0;
    else
        cout << s;
    return 0;
}