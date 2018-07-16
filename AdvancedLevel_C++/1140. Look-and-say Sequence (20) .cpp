1140. Look-and-say Sequence (20)
Look-and-say sequence is a sequence of integers as the following:
D, D1, D111, D113, D11231, D112213111, ...
where D is in [0, 9] except 1. The (n+1)st number is a kind of description of the nth number. For example, the 2nd number means that there is one D in the 1st number, and hence it is D1; the 2nd number consists of one D (corresponding to D1) and one 1 (corresponding to 11), therefore the 3rd number is D111; or since the 4th number is D113, it consists of one D, two 1’s, and one 3, so the next number must be D11231. This definition works for D = 1 as well. Now you are supposed to calculate the Nth number in a look-and-say sequence of a given digit D.
Input Specification:
Each input file contains one test case, which gives D (in [0, 9]) and a positive integer N (<=40), separated by a space.
Output Specification:
Print in a line the Nth number in a look-and-say sequence of D.
Sample Input:
1 8
Sample Output:
1123123111

题目大意：给两个数字D和n，第一个序列是D，后一个序列描述前一个序列的所有数字以及这个数字出现的次数，比如D出现了1次，那么第二个序列就是D1，对于第二个序列D1，第三个序列这样描述：D出现1次，1出现1次，所以是D111……以此类推，输出第n个序列
分析：用string s接收所需变幻的数字，每次遍历s，从当前位置i开始，看后面有多少个与s[i]相同，设j处开始不相同，那么临时字符串t += to_string((s[i] - '0') * 10 + j - i);然后再将t赋值给s，cnt只要没达到n次就继续加油循环下一次，最后输出s的值～

#include <iostream>
using namespace std;
int main() {
    string s;
    int n, j;
    cin >> s >> n;
    for (int cnt = 1; cnt < n; cnt++) {
        string t;
        for (int i = 0; i < s.length(); i = j) {
            for (j = i; j < s.length() && s[j] == s[i]; j++);
            t += to_string((s[i] - '0') * 10 + j - i);
        }
        s = t;
    }
    cout << s;
    return 0;
}