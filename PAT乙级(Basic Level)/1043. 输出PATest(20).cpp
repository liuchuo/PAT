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


#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main() {
    char t;
    map<char, int> m;
    while(cin >> t) {
        if (t == 'P' || t == 'A' || t == 'T' || t == 'e' || t == 's' || t == 't')
            m[t]++;
    }
    char c[7] = {"PATest"};
    int maxCnt = 0;
    for (auto it : m) {
        maxCnt = max(maxCnt, it.second);
    }
    for (int i = 0; i < maxCnt; i++) {
        for (int j = 0; j < 6; j++) {
            if (m[c[j]] != 0) {
                cout << c[j];
                m[c[j]]--;
            }
        }
    }
    return 0;
}