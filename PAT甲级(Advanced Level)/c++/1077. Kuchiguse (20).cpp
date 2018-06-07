1077. Kuchiguse (20)
The Japanese language is notorious for its sentence ending particles. Personal preference of such particles can be considered as a reflection of the speaker’s personality. Such a preference is called "Kuchiguse" and is often exaggerated artistically in Anime and Manga. For example, the artificial sentence ending particle "nyan~" is often used as a stereotype for characters with a cat-like personality:
Itai nyan~ (It hurts, nyan~)
Ninjin wa iyada nyan~ (I hate carrots, nyan~)
Now given a few lines spoken by the same character, can you find her Kuchiguse?
Input Specification:
Each input file contains one test case. For each case, the first line is an integer N (2<=N<=100). Following are N file lines of 0~256 (inclusive) characters in length, each representing a character's spoken line. The spoken lines are case sensitive.
Output Specification:
For each test case, print in one line the kuchiguse of the character, i.e., the longest common suffix of all N lines. If there is no such suffix, write "nai".
Sample Input 1:
3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~
Sample Output 1:
nyan~
Sample Input 2:
3
Itai!
Ninjinnwaiyada T_T
T_T
Sample Output 2:
nai

题目大意：给定N给字符串，求他们的公共后缀，如果不存在公共后缀，就输出“nai”
分析：因为是后缀，反过来比较太麻烦，所以每输入一个字符串，就把它逆序过来再比较，就比较容易了。
首先ans = s；后来每输入的一个字符串，都和ans比较，如果后面不相同的就把它截取掉。
最后输出ans即可（要逆序输出~~）

#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    string ans;
    getchar();
    for(int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        int lens = s.length();
        for(int j = 0; j < lens / 2; j++) {
            swap(s[j], s[lens-1-j]);
        }
        if(i == 0) {
            ans = s;
            continue;
        } else {
            int lenans = ans.length();
            int minlen = lens < lenans ? lens : lenans;
            for(int j = 0; j < minlen; j++) {
                if(ans[j] != s[j]) {
                    ans = ans.substr(0, j);
                    break;
                }
            }
        }
    }
    if(ans.length() == 0) {
        printf("nai");
    } else {
        for(int i = ans.length() - 1; i >= 0; i--) {
            printf("%c", ans[i]);
        }
    }
    return 0;
}