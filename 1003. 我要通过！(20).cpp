1003. 我要通过！(20)
“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。
得到“答案正确”的条件是：
1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。
输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。
输入样例：
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
输出样例：
YES
YES
YES
YES
NO
NO
NO
NO

#include <iostream>
#include <string>
using namespace std;

int func(string str);

int main() {
    int n;
    cin >> n;
    getchar();
    string *s = new string [n];
    for (int i = 0; i < n; i++) {
        getline(cin,s[i]);
    }
    int *t = new int [n];
    for (int i = 0; i < n; i++) {
        t[i] = 0;
    }
    for (int j = 0; j < n; j++) {
        t[j] = func(s[j]);
    }
    
    for (int k = 0; k < n; k++) {
        if (t[k] == 1) {
            cout << "YES" << endl;
        }
        if (t[k] == 0) {
            cout << "NO" << endl;
        }
    }
    delete [] s;
    delete [] t;
    return 0;
}

int func(string str) {
    int len = str.length();
    if (len <= 2)
        return 0;
    for (int i = 0; i < len; i++) {
        if (str[i] != 'P' && str[i] != 'A' && str[i] != 'T') {
            return 0;
        }
        if (str[i] == 'P') {
            for (int j = 0; j < i; j++) {
                if (str[j] != 'A')
                    return 0;
            }
            if (str [i + 1] != 'A')
                return 0;
            for (int k = i + 2; k < len; k++) {
                if (str[k] != 'A') {
                    if (str[k] != 'T') {
                        return 0;
                    }
                    if ((len - 1 - k) != ((k - 1 - i) * i))
                        return 0;
                    for (int m = k + 1; m < len; m++) {
                        if (str[m] != 'A')
                            return 0;
                    }
                }
            }
        }
    }
    return 1;
}
