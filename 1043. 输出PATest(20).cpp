//1043. 输出PATest(20)
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
给定一个长度不超过10000的、仅由英文字母构成的字符串。请将字符重新调整顺序，
按“PATestPATest....”这样的顺序输出，并忽略其它字符。当然，六种字符的个
数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按PATest的顺序打印，
直到所有字符都被输出。
输入格式：
输入在一行中给出一个长度不超过10000的、仅由英文字母构成的非空字符串。
输出格式：
在一行中按题目要求输出排序后的字符串。题目保证输出非空。
输入样例：
redlesPayBestPATTopTeePHPereatitAPPT
输出样例：
PATestPATestPTetPTePePee


update: v2.0
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    map<char, int> a {
        {'P', 0}, {'A', 0}, {'T', 0}, {'e', 0}, {'s', 0}, {'t', 0}
    };
    string s;
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] == 'P' || s[i] == 'A' || s[i] == 'T'
            || s[i] == 'e' || s[i] == 's' || s[i] == 't') {
            a[s[i]]++;
        }
    }
    
    while(a['P'] != 0 || a['A'] != 0 || a['T'] != 0 || a['e'] != 0 || a['s'] != 0 || a['t'] != 0) {
        if(a['P'] != 0) {cout << "P"; a['P']--;}
        if(a['A'] != 0) {cout << "A"; a['A']--;}
        if(a['T'] != 0) {cout << "T"; a['T']--;}
        if(a['e'] != 0) {cout << "e"; a['e']--;}
        if(a['s'] != 0) {cout << "s"; a['s']--;}
        if(a['t'] != 0) {cout << "t"; a['t']--;}
    }
    return 0;
}



#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    int len = s.length();
    int a[6] = {0};
    for (int i = 0; i < len; i++) {
        if (s[i] == 'P') a[0]++;
        if (s[i] == 'A') a[1]++;
        if (s[i] == 'T') a[2]++;
        if (s[i] == 'e') a[3]++;
        if (s[i] == 's') a[4]++;
        if (s[i] == 't') a[5]++;
    }
    int max = a[0];
    for (int i = 1; i < 6; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    for (int i = 0; i < max; i++) {
        if (a[0] != 0) {cout << "P";a[0]--;}
        if (a[1] != 0) {cout << "A";a[1]--;}
        if (a[2] != 0) {cout << "T";a[2]--;}
        if (a[3] != 0) {cout << "e";a[3]--;}
        if (a[4] != 0) {cout << "s";a[4]--;}
        if (a[5] != 0) {cout << "t";a[5]--;}
    }
    return 0;
}