//1013. 数素数 (20)
令Pi表示第i个素数。现任给两个正整数M <= N <= 10^4，请输出PM到PN的所有素数。

输入格式：
输入在一行中给出M和N，其间以空格分隔。

输出格式：
输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103

#include <iostream>
#include <cmath>
using namespace std;
bool isprime(int a) {
    for (int i = 2; i <= sqrt(a); i++) {
        if(a % i == 0)
            return false;
    }
    return true;
}

int main() {
    int M, N;
    cin >> M >> N;
    int t = 0;
    int k = 2;
    int a[10000];
    int j = 0;
    while (t < N) {
        if (isprime(k)) {
            t++;
            if (t >= M)
                a[++j] = k;
        }
        k++;
    }
    int row = j / 10;
    if (j % 10 == 0)
        row = row - 1;
    for (int i = 0; i < row; i++) {
        for (int k = 1; k < 10; k++) {
            cout << a[10 * i + k] << " ";
        }
        cout << a[(i + 1) * 10] << endl;
    }
    for (int i = row * 10 + 1; i < j; i++) {
        cout << a[i] << " ";
    }
    cout << a[j];
    
    
    return 0;
}