1002. 写出这个数 (20)

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
读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。

输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu

update-v2.0:
string是类,printf()只能打印基本类型。

#include <iostream>
using namespace std;
int main() {
    string chinese[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    string s;
    cin >> s;
    int len = s.length();
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum = s[i] - '0' + sum;
    }
    int *a = new int [len];
    int t = 0;
    if (sum == 0) {
        cout << chinese[0];
        return 0;
    }
    while (sum != 0) {
        a[t++] = sum % 10;
        sum = sum / 10;
    }
    for (int i = t - 1; i >= 0; i--) {
        cout << chinese[a[i]];
        if(i != 0)
            printf(" ");
    }
    delete [] a;
    return 0;
}


//以前写的方法。现在想来太傻了。。
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    int len = s.length();
    int *a = new int [len];
    int sum = 0;
    for (int i = 0; i < len; i++) {
        a[i] = s[i] - '0';
        sum = sum + a[i];
    }
    int *b = new int [len];
    int j = 0;
    if (sum == 0) {
        cout << "ling";
    }
    else {
        while (sum != 0) {
            b[j++] = sum % 10;
            sum = sum / 10;
        }
    }
    for (int i = j - 1;i >= 1; i--) {
        switch(b[i]) {
            case 1: cout << "yi ";break;
            case 2: cout << "er ";break;
            case 3: cout << "san ";break;
            case 4: cout << "si ";break;
            case 5: cout << "wu ";break;
            case 6: cout << "liu ";break;
            case 7: cout << "qi ";break;
            case 8: cout << "ba ";break;
            case 9: cout << "jiu ";break;
            case 0: cout << "ling ";break;
        }
    }
    switch(b[0]) {
        case 1: cout << "yi";break;
        case 2: cout << "er";break;
        case 3: cout << "san";break;
        case 4: cout << "si";break;
        case 5: cout << "wu";break;
        case 6: cout << "liu";break;
        case 7: cout << "qi";break;
        case 8: cout << "ba";break;
        case 9: cout << "jiu";break;
        case 0: cout << "ling";break;
    }
    delete [] a;
    delete [] b;
    return 0;
}