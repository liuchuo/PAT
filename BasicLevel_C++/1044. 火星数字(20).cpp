1044. 火星数字(20)
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
#include <cctype>
using namespace std;
string a[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct",
    "nov", "dec"};
string b[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy",
    "lok", "mer", "jou"};
void func1(string s) {
    int len = s.length();
    int num = 0;
    for (int i = 0; i < len; i++) {
        num = num * 10 + (s[i] - '0');
    }
    cout << b[num / 13];
    if((num % 13) && (num / 13)) {
        cout << " " << a[num % 13];
    } else if(num % 13) {
        cout << a[num % 13];
    } else if(num == 0) {
        cout << a[num % 13];
    }
}

void func2(string s) {
    int len = s.length();
    int num = 0;
    if(len == 4) {
        cout << 0;
        return ;
    } else if (len == 3) {
        for (int i = 1; i <= 12; i++) {
            if (s == a[i]) {
                cout << i;
                return ;
            }
            if (s == b[i]) {
                cout << i * 13;
                return ;
            }
        }
    } else {
        string temp1 = s.substr(0, 3);
        string temp2 = s.substr(4, 3);
        for (int i = 1; i <= 12; i++) {
            if (temp1 == b[i]) {
                num += i * 13;
            }
            if (temp2 == a[i]) {
                num += i;
            }
        }
        cout << num;
    }
    return ;
}

int main() {
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        if(isdigit(s[0]))
            func1(s);
        else
            func2(s);
        cout << endl;
    }
    return 0;
}
