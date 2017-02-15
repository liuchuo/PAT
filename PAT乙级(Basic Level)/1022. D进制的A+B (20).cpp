1022. D进制的A+B (20)
输入两个非负10进制整数A和B(<=2^30-1)，输出A+B的D (1 < D <= 10)进制数。

输入格式：

输入在一行中依次给出3个整数A、B和D。

输出格式：

输出A+B的D进制数。

输入样例：
123 456 8
输出样例：
1103

#include <iostream>
using namespace std;

int main() {
    int a, b, d;
    cin >> a >> b >> d;
    int t = a + b;
    if (t == 0) {
        cout << 0;
        return 0;
    }
    int s[100];
    int i = 0;
    while (t != 0) {
        s[i++] = t % d;
        t = t / d;
    }
    for (int j = i - 1; j >= 0; j--) {
        cout << s[j];
    }
    return 0;
}