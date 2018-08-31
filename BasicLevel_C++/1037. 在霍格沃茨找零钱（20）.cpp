#include <iostream>
using namespace std;
int main() {
    int a, b ,c;
    int m, n, t;
    scanf("%d.%d.%d",&a, &b, &c);
    scanf("%d.%d.%d",&m, &n, &t);
    int flag;
    if (a > m ||(a == m && b > n) ||(a == m && b == n && c > t))
        flag = 0;
    else
        flag = 1;
    
    int x, y, z;
    if (flag == 1) {
        if (t >= c) {
            z = t - c;
        } else {
            z = t + 29 - c;
            n = n - 1;
        }
        if (n >= b) {
            y = n - b;
        } else {
            y = n + 17 - b;
            m = m - 1;
        }
        x = m - a;
        cout << x << "." << y << "." << z;
    } else {
        if (c >= t) {
            z = c - t;
        } else {
            z = c + 29 - t;
            b = b - 1;
        }
        if (b >= n) {
            y = b - n;
        } else {
            y = b + 17 - n;
            a = a - 1;
        }
        x = a - m;
        cout << "-" << x << "." << y << "." << z;
    }
    return 0;
}