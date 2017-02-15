//1024. 科学计数法 (20)

时间限制
100 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
HOU, Qiming
科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式[+-][1-9]"."[0-9]+E[+-][0-9]+，即数字的整数部分只有1位，小数部分至少有1位，该数字及其指数部分的正负号即使对正数也必定明确给出。

现以科学计数法的格式给出实数A，请编写程序按普通数字表示法输出A，并保证所有有效位都被保留。

输入格式：

每个输入包含1个测试用例，即一个以科学计数法表示的实数A。该数字的存储长度不超过9999字节，且其指数的绝对值不超过9999。

输出格式：

对每个测试用例，在一行中按普通数字表示法输出A，并保证所有有效位都被保留，包括末尾的0。

输入样例1：
+1.23400E-03
输出样例1：
0.00123400
输入样例2：
-1.2E+10
输出样例2：
-12000000000

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int len = s.length();
    // 输出第1位符号
    if (s[0] == '-')
        cout << "-";
    // 找到E的位置，标记为pose = i;
    int pose = 0;
    for (int i = 1; i < len; i++) {
        if (s[i] == 'E')
            pose = i;
    }
    // 把E后面的字符串数转化为after的数值
    int after = 0;
    for (int i = pose + 2; i < len; i++) {
        after = (s[i] - '0') + 10 * after;
    }
    // 如果E后面的那个符号是负号‘-’
    if (s[pose + 1] == '-') {
        if (0 < after) {
            cout << "0.";
            for (int i = 1; i < after; i++) {
                cout << 0;
            }
            for (int i = 1; i < pose; i++) {
                if (s[i] >= '0' && s[i] <= '9') {
                    cout << s[i];
                }
            }
        } else {
            for (int i = 0; i < pose; i++) {
                cout << s[i];
            }
        }
    }
    // 如果E后面的那个符号是‘+’
    else {
        // 如果要在后面添加0
        if (pose - 3 < after) {
            if (s[1] != '0')
                cout << s[1];
            for (int i = 3; i < pose; i++) {
                if (s[i] >= '0' && s[i] <= '9') {
                    cout << s[i];
                }
            }
            for (int i = 0; i < after - (pose - 3); i++) {
                cout << 0;
            }
        }
        // 如果不用再后面添加0
        else {
            if (s[1] != '0')
                cout << s[1];
            for (int i = 3; i < pose; i++) {
                if (i == 3 + after) {
                    cout << ".";
                }
                if (s[i] >= '0' && s[i] <= '9') {
                    cout << s[i];
                }
            }
        }
    }
    return 0;
}