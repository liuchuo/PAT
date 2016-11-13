1030. 完美数列(25)
时间限制
300 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CAO, Peng
给定一个正整数数列，和正整数p，设这个数列中的最大值是M，最小值是m，如果M <= m * p，则称这个数列是完美数列。

现在给定参数p和一些正整数，请你从中选择尽可能多的数构成一个完美数列。

输入格式：

输入第一行给出两个正整数N和p，其中N（<= 105）是输入的正整数的个数，p（<= 109）是给定的参数。第二行给出N个正整数，每个数不超过109。

输出格式：

在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。

输入样例：
10 8
2 3 20 4 5 1 6 7 8 9
输出样例：
8

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long p;
    cin >> n >> p;
    if (n == 0) {
        cout << n;
        return 0;
    }
    long long int *a = new long long int [n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    int result = 1;
    int temp = 1;
    for (int i = 0; i <= n - 2; i++) {
        for (int j = i + result; j <= n - 1; j++) {//因为是为了找最大的result，所以下一次j只要从i的result个后面开始找就行了
            if (a[j] <= a[i] * p) {
                temp = j - i + 1;//计算有多少个数满足
                if (temp > result) { //如果比result中存储的大，就更新result的值
                    result = temp;
                }
            } else {
                break;
            }
        }
    }
    cout << result;
    
    return 0;
}