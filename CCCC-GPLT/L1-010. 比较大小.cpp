L1-010. 比较大小
输入格式：
输入在一行中给出3个整数，其间以空格分隔。
输出格式：
在一行中将3个整数从小到大输出，其间以“->”相连。
输入样例：
4 2 8
输出样例：
2->4->8

#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if(b > c) {
        swap(b, c);
    }
    if(a > b) {
        swap(a, b);
    }
    if(b > c) {
        swap(b, c);
    }
    cout << a << "->" << b << "->" << c;
    return 0;
}