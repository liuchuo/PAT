//1042. 字符统计(20)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
请编写程序，找出一段给定文字中出现最频繁的那个英文字母。

输入格式：
输入在一行中给出一个长度不超过1000的字符串。字符串由ASCII码表中任意可见字符及空格组成，
至少包含1个英文字母，以回车结束（回车不算在内）。

输出格式：

在一行中输出出现频率最高的那个英文字母及其出现次数，其间以空格分隔。如果有并列，
则输出按字母序最小的那个字母。统计时不区分大小写，输出小写字母。

输入样例：
This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........
输出样例：
e 7

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int cmp(int a, int b) {
    return a > b;
}
int main() {
    string s;
    getline(cin, s);
    int len = s.length();
    for (int i = 0; i < len; i++) {
        s[i] = tolower(s[i]);
    }
    int a[26] = {0};
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            a[s[i] - 'a']++;
    }
    int max = a[0];
    int t = 0;
    for (int i = 1; i < 26; i++) {
        if (a[i] > max) {
            max = a[i];
            t = i;
        }
    }
    char temp = t + 'a';
    cout << temp << " " << max;
    return 0;
}