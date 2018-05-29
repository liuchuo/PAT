1081. 检查密码 (15)
本题要求你帮助某网站的用户注册模块写一个密码合法性检查的小功能。该网站要求用户设置的密码必须由不少于6个字符组成，并且只能有英文字母、数字和小数点"."，还必须既有字母也有数字。
输入格式：
输入第一行给出一个正整数 N（<=100），随后 N 行，每行给出一个用户设置的密码，为不超过80个字符的非空字符串，以回车结束。
输出格式：
对每个用户的密码，在一行中输出系统反馈信息，分以下5种：
如果密码合法，输出“Your password is wan mei.”；
如果密码太短，不论合法与否，都输出“Your password is tai duan le.”；
如果密码长度合法，但存在不合法字符，则输出“Your password is tai luan le.”；
如果密码长度合法，但只有字母没有数字，则输出“Your password needs shu zi.”；
如果密码长度合法，但只有数字没有字母，则输出“Your password needs zi mu.”。
输入样例：
5
123s
zheshi.wodepw
1234.5678
WanMei23333
pass*word.6
输出样例：
Your password is tai duan le.
Your password needs shu zi.
Your password needs zi mu.
Your password is wan mei.
Your password is tai luan le.

分析：非空字符串，每个字符串以回车结束，但是字符串里面可能会有空格，所以不能直接用cin，要用getline接收一行字符。在接收完n后要getchar()读取一下换行符才能用getline，否则换行符会被读进getline中～

#include <iostream>
#include <cctype>
using namespace std;
int main() {
    int n;
    cin >> n; getchar();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        if (s.length() >= 6) {
            int invalid = 0, hasAlpha = 0, hasNum = 0;
            for (int j = 0; j < s.length(); j++) {
                if (s[j] != '.' && !isalnum(s[j])) invalid = 1;
                else if (isalpha(s[j])) hasAlpha = 1;
                else if (isdigit(s[j])) hasNum = 1;
            }
            if (invalid == 1) cout << "Your password is tai luan le.\n";
            else if (hasNum == 0) cout << "Your password needs shu zi.\n";
            else if (hasAlpha == 0) cout << "Your password needs zi mu.\n";
            else cout << "Your password is wan mei.\n";
        } else
            cout << "Your password is tai duan le.\n";
    }
    return 0;
}
