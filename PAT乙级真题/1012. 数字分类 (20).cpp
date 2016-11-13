//1012. 数字分类 (20)
给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：

A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。
输入格式：

每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，
随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。

输出格式：

对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。
数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出“N”。

输入样例1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例1：
30 11 2 9.7 9
输入样例2：
8 1 2 4 5 6 7 9 16
输出样例2：
N 11 2 N 9

#include <iostream>
using namespace std;
int main() {
    int A1, A2, A3, A5;
    float A4;
    int N;
    cin >> N;
    int *a = new int [N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    A1 = 0;
    A2 = 0;
    A3 = 0;
    A4 = 0.0;
    A5 = 0;
    int flag1 = 0, flag2 = 0, flag3 = 0;
    int flag4 = 0, flag5 = 0;
    
    int *b = new int [N];
    for (int i = 0; i < N; i++) {
        b[i] = 0;
    }
    int t = 0;
    int count = 0;
    
    for (int i = 0; i < N; i++) {
        if (a[i] % 10 == 0) {
            A1 = A1 + a[i];
            flag1 = 1;
        }
        if (a[i] % 5 == 1) {
            b[t++] = a[i];
            flag2 = 1;
        }
        if (a[i] % 5 == 2) {
            A3++;
            flag3 = 1;
        }
        if (a[i] % 5 == 3) {
            A4 = A4 + a[i];
            count++;
            flag4 = 1;
        }
        if (a[i] % 5 == 4) {
            if (A5 < a[i]) {
                A5 = a[i];
                flag5 = 1;
            }
        }
    }
    
    
    for (int i = 0; i < t; i++) {
        if (i == 0 || i % 2 == 0) {
            A2 = A2 + b[i];
        } else {
            A2 = A2 - b[i];
        }
    }
    A4 = A4 / count;
    
    if (flag1 == 0)
        cout << "N";
    else
        cout << A1;
    cout << " ";
    if (flag2 == 0)
        cout << "N";
    else
        cout << A2;
    cout << " ";
    if (flag3 == 0)
        cout << "N";
    else
        cout << A3;
    cout << " ";
    if (flag4 == 0)
        cout << "N";
    else
        printf("%.1f",A4);
    cout << " ";
    if (flag5 == 0)
        cout << "N";
    else
        cout << A5;
    delete [] a;
    delete [] b;
    return 0;
}