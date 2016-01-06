1009. 说反话 (20)

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
给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

输入格式：测试输入包含一个测试用例，在一行内给出总长度不超过80的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用1个空格分开，输入保证句子末尾没有多余的空格。

输出格式：每个测试用例的输出占一行，输出倒序后的句子。

输入样例：
Hello World Here I Come
输出样例：
Come I Here World Hello




#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int len = s.length();
    int count = 1;
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ')
            count++;
    }
    char **a = new char* [count];
    for (int i = 0; i < count; i++) {
        a[i] = new char [len];
    }
    
    int t = 0;
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < len; j++) {
            if (s[t] != ' ') {
                a[i][j] = s[t];
                t++;
            }
            else {
                a[i][j] = '\0';
                t++;
                break;
            }
        }
    }
    int temp = t;
    for (int j = 0; j < len - temp + 1; j++) {
        a[count - 1][j] = s[t];
        t++;
    }
    a[count - 1][len - temp + 1] = '\0';
    
    for (int i = count - 1; i >= 1; i--) {
        for (int j = 0; j < len; j++) {
            if (a[i][j] != '\0')
                cout << a[i][j];
            else
                break;
        }
        cout << " ";
    }
    for (int j = 0; j < len; j++) {
        if (a[0][j] != '\0')
            cout << a[0][j];
    }
    
    for (int i = 0; i < count; i++) {
        delete [] a[i];
    }
    delete [] a;
    return 0;
}