1033. 旧键盘打字(20)
时间限制
200 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？

输入格式：

输入在2行中分别给出坏掉的那些键、以及应该输入的文字。其中对应英文字母的坏键以大写给出；每段文字是不超过105个字符的串。可用的字符包括字母[a-z, A-Z]、数字0-9、以及下划线“_”（代表空格）、“,”、“.”、“-”、“+”（代表上档键）。题目保证第2行输入的文字串非空。

注意：如果上档键坏掉了，那么大写的英文字母无法被打出。

输出格式：

在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。

输入样例：
7+IE.
7_This_is_a_test.
输出样例：
_hs_s_a_tst

如果没有一个字符能被打出，则输出空行。
如果没有一个字符能被打出，则输出空行。
如果没有一个字符能被打出，则输出空行。
重要的事情要说三遍！！

#include <iostream>
using namespace std;
int main() {
    string a, b;
    getline(cin, a);//为了防止第一行是空的，不能用cin >> a,用getline(cin, a)
    getline(cin, b);
    if (a.length() == 0) {
        cout << b;
        return 0;
    }
    int flag = 0;
    int lena = a.length();
    int lenb = b.length();
    //检验是否有大写
    for (int i = 0; i < lena; i++) {
        if (a[i] == '+') {
            flag = 1;
            a[i] = '#';
        }
    }
    //去除大写字母
    if(flag) {
        for (int i = 0; i < lenb; i++) {
            if (b[i] >= 'A' && b[i] <= 'Z') {
                b[i] = '#';
            }
        }
    }
    //去除其它字母
    for (int i = 0; i < lenb; i++) {
        for (int j = 0; j < lena; j++) {
            if (a[j] == b[i]) {
                b[i] = '#';
            }
            if (a[j] >= 'A' && a[j] <= 'Z' && b[i] == a[j] + 32) {
                b[i] = '#';
            }
        }
    }
    int flag1 = 0;
    //print
    for (int i = 0; i < lenb; i++) {
        if (b[i] != '#') {
            cout << b[i];
            flag1 = 1;
        }
    }
    if (flag1 == 0)
        cout << endl;
    return 0;
}