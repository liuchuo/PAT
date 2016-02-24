1048. 数字加密(20)
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
本题要求实现一种数字加密方法。首先固定一个加密用正整数A，对任一正整数B，将其每1位数字与A的对应位置上的数字进行以下运算：对奇数位，对应位的数字相加后对13取余——这里用J代表10、Q代表11、K代表12；对偶数位，用B的数字减去A的数字，若结果为负数，则再加10。这里令个位为第1位。

输入格式：

输入在一行中依次给出A和B，均为不超过100位的正整数，其间以空格分隔。

输出格式：

在一行中输出加密后的结果。

输入样例：
1234567 368782971
输出样例：
3695Q8118

#include <iostream>
#include <string>
using namespace std;
int main() {
    string a, b;
    string c;
    cin >> a >> b;
    int lena = a.length();
    int lenb = b.length();
    char d;
    for (int i = 0; i <= lena / 2 - 1; i++) {
        d = a[i];
        a[i] = a[lena - 1 - i];
        a[lena - 1 - i] = d;
    }
    
    for (int i = 0; i <= lenb / 2 - 1; i++) {
        d = b[i];
        b[i] = b[lenb - 1 - i];
        b[lenb - 1 - i] = d;
    }
    int min = lena > lenb ? lenb : lena;
    int flag = lena > lenb ? 0 : 1;
    int max = lena > lenb ? lena : lenb;
    int temp;
    for (int i = 0; i < min; i++) {
        if (i % 2 == 0) {
            temp = (a[i] - '0' + b[i] - '0') % 13;
            if(temp >= 0 && temp <= 9)
                c += ((a[i] - '0' + b[i] - '0') % 13 + '0');
            else if (temp == 10)
                c += 'J';
            else if (temp == 11)
                c += 'Q';
            else
                c += 'K';
        } else {
            temp = b[i] - a[i];
            if (temp < 0)
                temp = temp + 10;
            c += temp + '0';
        }
    }
    if (flag == 0) {
        for (int i = min; i < lena; i++)
            c += a[i];
    } else {
        for (int i = min; i < lenb; i++)
            c += b[i];
    }
    for (int i = max - 1; i >= 0; i--) {
        cout << c[i];
    }
    return 0;
}