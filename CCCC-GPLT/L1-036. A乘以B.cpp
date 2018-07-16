L1-036. A乘以B
看我没骗你吧 —— 这是一道你可以在10秒内完成的题：给定两个绝对值不超过100的整数A和B，输出A乘以B的值。

输入格式：
输入在第一行给出两个整数A和B（-100 <= A, B, <= 100），数字间以空格分隔。

输出格式：
在一行中输出A乘以B的值。

输入样例：
-8 13
输出样例：
-104

#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    cout << a * b;
    return 0;
}