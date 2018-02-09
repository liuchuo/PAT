1048. 数字加密(20)
本题要求实现一种数字加密方法。首先固定一个加密用正整数A，对任一正整数B，
将其每1位数字与A的对应位置上的数字进行以下运算：对奇数位，对应位的数字相加后对13取余
——这里用J代表10、Q代表11、K代表12；对偶数位，用B的数字减去A的数字，若结果为负数，则再加10。
这里令个位为第1位。
输入格式：
输入在一行中依次给出A和B，均为不超过100位的正整数，其间以空格分隔。
输出格式：
在一行中输出加密后的结果。
输入样例：
1234567 368782971
输出样例：
3695Q8118

#include <iostream>
using namespace std;
int main() {
    string a, b, c;
    cin >> a >> b;
    int lena = a.length(), lenb = b.length();
    for (int i = 0; i <= lena / 2 - 1; i++)
        swap(a[i], a[lena-1-i]);
    for (int i = 0; i <= lenb / 2 - 1; i++)
        swap(b[i], b[lenb-1-i]);
    if (lena > lenb)
        b.append(lena - lenb, '0');
    else
        a.append(lenb - lena, '0');
    char str[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
    for (int i = 0; i < a.length(); i++) {
        if (i % 2 == 0) {
            c += str[(a[i] - '0' + b[i] - '0') % 13];
        } else {
            int temp = b[i] - a[i];
            if (temp < 0) temp = temp + 10;
            c += str[temp];
        }
    }
    for (int i = c.length() - 1; i >= 0; i--)
        cout << c[i];
    return 0;
}