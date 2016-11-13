L1-032. Left-pad
根据新浪微博上的消息，有一位开发者不满NPM（Node Package Manager）的做法，收回了自己的开源代码，其中包括一个叫left-pad的模块，就是这个模块把javascript里面的React/Babel干瘫痪了。这是个什么样的模块？就是在字符串前填充一些东西到一定的长度。例如用“*”去填充字符串“GPLT”，使之长度为10，调用left-pad的结果就应该是“******GPLT”。Node社区曾经对left-pad紧急发布了一个替代，被严重吐槽。下面就请你来实现一下这个模块。

输入格式：

输入在第一行给出一个正整数N（<=104）和一个字符，分别是填充结果字符串的长度和用于填充的字符，中间以1个空格分开。第二行给出原始的非空字符串，以回车结束。

输出格式：

在一行中输出结果字符串。

输入样例1：
15 _
I love GPLT
输出样例1：
____I love GPLT
输入样例2：
4 *
this is a sample for cut
输出样例2：
 cut
分析：需要的长度少于字符串长度的时候，使用substr输出，需要的长度大于字符串长度的时候，在前面补字符
#include <iostream>
#include <string.h>
using namespace std;
int main() {
    int cnt;
    char c;
    string s;
    cin >> cnt >> c;
    getchar();
    getline(cin, s);
    int len = s.length();
    if(len >= cnt) {
        cout << s.substr(s.size() - cnt);
    } else {
        for(int i = 0; i < cnt - len; i++) {
            cout << c;
        }
        cout << s;
    }
    return 0;
}