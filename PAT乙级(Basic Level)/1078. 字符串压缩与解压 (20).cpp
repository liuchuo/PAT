1078. 字符串压缩与解压 (20)
文本压缩有很多种方法，这里我们只考虑最简单的一种：把由相同字符组成的一个连续的片段用这个字符和片段中含有这个字符的个数来表示。例如 ccccc 就用 5c 来表示。如果字符没有重复，就原样输出。例如 aba 压缩后仍然是 aba。
解压方法就是反过来，把形如 5c 这样的表示恢复为 ccccc。
本题需要你根据压缩或解压的要求，对给定字符串进行处理。这里我们简单地假设原始字符串是完全由英文字母和空格组成的非空字符串。
输入格式：
输入第一行给出一个字符，如果是 C 就表示下面的字符串需要被压缩；如果是 D 就表示下面的字符串需要被解压。第二行给出需要被压缩或解压的不超过1000个字符的字符串，以回车结尾。题目保证字符重复个数在整型范围内，且输出文件不超过1MB。
输出格式：
根据要求压缩或解压字符串，并在一行中输出结果。
输入样例 1：
C
TTTTThhiiiis isssss a   tesssst CAaaa as
输出样例 1：
5T2h4is i5s a3 te4st CA3a as
输入样例 2：
D
5T2h4is i5s a3 te4st CA3a as10Z
输出样例 2：
TTTTThhiiiis isssss a   tesssst CAaaa asZZZZZZZZZZ

分析：1 解压时，cnt初始值为1，若遇到数字则将字符串数字转化为int型数字cnt，之后输出cnt次当前字母。
2 压缩时，用pre保存前一个字母，当当前字母与pre相同时，cnt++；否则输出cnt(cnt>=2时才需输出cnt)和pre，然后令pre=当前字母。最后别忘记结尾处理：当cnt>=2时输出cnt，然后输出pre

#include <iostream>
using namespace std;
int main() {
    char t;
    cin >> t;
    getchar();
    string s, num;
    getline(cin, s);
    int cnt = 1;
    if (t == 'D') {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num += s[i];
            } else {
                if (num.length() > 0) cnt = stoi(num);
                while(cnt--) cout << s[i];
                cnt = 1;
                num = "";
            }
        }
    } else if (s.length() != 0) {
        char pre = s[0];
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == pre) {
                cnt++;
            } else {
                if (cnt >= 2) cout << cnt;
                cout << pre;
                cnt = 1;
                pre = s[i];
            }
        }
        if (cnt >= 2) cout << cnt;
        cout << pre;
    }
    return 0;
}
