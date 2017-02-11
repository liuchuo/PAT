1029. 旧键盘(20)
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。
现在给出应该输入的一段文字、以及实际被输入的文字，请你列出肯定坏掉
的那些键。

输入格式：

输入在2行中分别给出应该输入的文字、以及实际被输入的文字。每段文字是
不超过80个字符的串，由字母A-Z（包括大、小写）、数字0-9、以及下划线
“_”（代表空格）组成。题目保证2个字符串均非空。

输出格式：

按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键
只输出一次。题目保证至少有1个坏键。

输入样例：
7_This_is_a_test
_hs_s_a_es
输出样例：
7TI

#include <iostream>
#include <string>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    int lena = a.length();
    int lenb = b.length();
    char c[80];
    int flag;
    int t = 0;
    for (int i = 0; i < lena; i++) {
        flag = 0;
        // 找b字符串中有没有i对应的这个字母。，如果有，flag == 1
        for (int j = 0; j < lenb; j++) {
            if (a[i] == b[j]) {
                flag = 1;
                break;
            }
        }
        // 并没有找到满足条件的字母，就把它存储在c数组里面
        if (flag == 0) {
            if (a[i] >= 'a' && a[i] <= 'z') {
                c[t++] = a[i] - 32;
            }
            else {
                c[t++] = a[i];
            }
        }
    }
    // 去重，搜索i之前的所有字符有没有和i相同的，如果有，那么把i（后面一个字符）标为‘#’，这样才能保证字符的顺序是和给出的字符串顺序一致
    for (int i = 1; i < t; i++) {
        for (int j = 0; j < i; j++) {
            if (c[i] == c[j]) {
                c[i] = '#';
                break;
            }
        }
    }
    // 输出所有不是‘#’的字符。
    for (int i = 0; i < t; i++) {
        if (c[i] != '#')
            cout << c[i];
    }
    return 0;
}