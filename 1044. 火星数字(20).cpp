//1044. 火星数字(20)

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
火星人是以13进制计数的：

地球人的0被火星人称为tret。
地球人数字1到12的火星文分别为：jan, feb, mar, apr, may, 
jun, jly, aug, sep, oct, nov, dec。
火星人将进位以后的12个高位数字分别称为：tam, hel, maa,
 huh, tou, kes, hei, elo, syy, lok, mer, jou。
例如地球人的数字“29”翻译成火星文就是“hel mar”；而火星文
“elo nov”对应地球数字“115”。为了方便交流，请你编写程序
实现地球和火星数字之间的互译。

输入格式：

输入第一行给出一个正整数N（<100），随后N行，每行给出一个
[0, 169)区间内的数字 —— 或者是地球文，或者是火星文。

输出格式：

对应输入的每一行，在一行中输出翻译后的另一种语言的数字。

输入样例：
4
29
5
elo nov
tam
输出样例：
hel mar
may
115
13

#include <iostream>
#include <string>
using namespace std;

void func1(string s);
void func2(string s);

int main() {
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        int leng = s.length();
        if (leng == 1 && s[0] == '0') {
            cout << "tret" << endl;
        } else {
            if (s[0] >= '0' && s[0] <= '9') {
                func1(s);
            } else {
                func2(s);
            }
        }
    }
    return 0;
}

void func1(string s) {
    string a[13] = {"###", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string b[13] = {"###", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    int len = s.length();
    int t;
    if (len == 1) {
        t = s[0] - '0';
    } else if(len == 2) {
        t = (s[0] - '0') * 10 + (s[1] - '0');
    } else {
        t = (s[0] - '0') * 100 + (s[1] - '0') * 10 + (s[2] - '0');
    }
    if (t <= 12) {
        cout << a[t] << endl;
    } else if (t % 13 == 0) {
        cout << b[t / 13] << endl;
    } else {
        cout << b[t / 13] << " " << a[t % 13] << endl;
    }
}

void func2(string s) {
    string a[13] = {"###", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string b[13] = {"###", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    int len = s.length();
    if (len == 3) {
        for (int j = 1; j <= 12; j++) {
            if (s[0] == a[j][0] && s[1] == a[j][1] && s[2] == a[j][2]) {
                cout << j << endl;
            } else if (s[0] == b[j][0] && s[1] == b[j][1] && s[2] == b[j][2]) {
                cout << 13 * j << endl;
            }
        }
    } else {
        int t1 = 0;
        int t2 = 0;
        for (int j = 1; j <= 12; j++) {
            if (s[0] == b[j][0] && s[1] == b[j][1] && s[2] == b[j][2]) {
                t1 = j;
            }
            if (s[4] == a[j][0] && s[5] == a[j][1] && s[6] == a[j][2]) {
                t2 = j;
            }
        }
        cout << t1 * 13 + t2 << endl;
    }
}
