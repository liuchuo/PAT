L1-008. 求整数段和
给定两个整数A和B，输出从A到B的所有整数以及这些数的和。
输入格式：
输入在一行中给出2个整数A和B，其中-100<=A<=B<=100，其间以空格分隔。
输出格式：
首先顺序输出从A到B的所有整数，每5个数字占一行，每个数字占5个字符宽度，向右对齐。最后在一行中输出全部数字的和。
输入样例：
-3 8
输出样例：
   -3   -2   -1    0    1
    2    3    4    5    6
    7    8
Sum = 30

#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int temp = a;
    int sum = 0;
    while(temp <= b) {
        for(int j = 0; j < 5 && temp <= b; j++) {
            printf("%5d", temp);
            sum += temp;
            temp++;
        }
        cout << endl;
    }
    cout << "Sum = " << sum;
    return 0;
}