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
分析：用string s接收所需变幻的数字，char pre标记前一个字符，遍历字符串s，每次比较当前字符和前一个字符是否相等，如果不等，就将之前统计的相等的个数tempcnt追加到临时字符串temp后面，再将当前字符追加到temp字符串后面，并将tempcnt标记为1，否则就tempcnt++; 最终不要忘记把最后一个tempcnt放入temp字符串后面，然后赋值给s，只要没达到n次就继续循环，最后输出s的值

#include <iostream>
using namespace std;
int main() {
    string s;
    int n, cnt = 1;
    cin >> s >> n;
    while (cnt < n) {
        char pre = s[0];
        int tempcnt = 1;
        string temp;
        temp += s[0];
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != pre) {
                temp += to_string(tempcnt);
                temp += s[i];
                tempcnt = 1;
                pre = s[i];
            } else {
                tempcnt++;
            }
        }
        s = temp + to_string(tempcnt);
        cnt++;
    }
    cout << s;
    return 0;
}