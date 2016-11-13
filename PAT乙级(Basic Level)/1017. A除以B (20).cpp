//1017. A除以B (20)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，
使得A = B * Q + R成立。

输入格式：

输入在1行中依次给出A和B，中间以1空格分隔。

输出格式：

在1行中依次输出Q和R，中间以1空格分隔。

输入样例：
123456789050987654321 7
输出样例：
17636684150141093474 3

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int a;
    cin >> a;
    
    int len = s.length();
    int t = (s[0] - '0') / a;
    if ((t != 0 && len > 1) || len == 1) {
        cout << t;
    }

    int temp = (s[0] - '0') % a;

    for (int i = 1; i < len; i++) {
        t = (temp * 10 + s[i] - '0') / a;
        cout << t;
        temp = (temp * 10 + s[i] - '0') % a;
    }
    
    cout << " " << temp;
    return 0;
}