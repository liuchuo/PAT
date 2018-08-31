#include <iostream>
#include <cmath>
using namespace std;
long long a, b, c, d;
long long gcd(long long t1, long long t2) {
    return t2 == 0 ? t1 : gcd(t2, t1 % t2);
}
void func(long long m, long long n) {
    int flag1 = 0, flag2 = 0, flag = 0;
    if (n == 0) {
        printf("Inf");
        return ;
    }
    if (m == 0) {
        printf("0");
        return ;
    }
    if (m < 0) flag1 = 1;
    if (n < 0) flag2 = 1;
    m = abs(m), n = abs(n);
    if (flag1 == 1 && flag2 == 1) flag = 0;
    else if (flag1 == 1 || flag2 == 1) flag = 1;
    if (m == n) {
        if (flag == 1) printf("(-1)");
        else printf("1");
        return;
    }       
    long long x = m % n, y = m / n;
    if (x == 0) {
        if (flag == 0) printf("%d", y);
        else printf("(-%d)", y);
        return ;
    } else {
        long long t1 = m - y * n, t2 = n, t = gcd(t1, t2);
        t1 = t1 / t, t2 = t2 / t;
        if (flag == 1) {
            printf("(-");
            if (y != 0) printf("%lld %lld/%lld)", y, t1, t2);
            else printf("%d/%d)", t1, t2);
        } else {
            if (y != 0) printf("%lld %lld/%lld", y, t1, t2);
            else printf("%lld/%lld", t1, t2);
        }
    }
}
void print() {
    func(a, b); printf(" + "); func(c, d); printf(" = "); func(a * d + b * c, b * d); printf("\n");
    func(a, b); printf(" - "); func(c, d); printf(" = "); func(a * d - b * c, b * d); printf("\n");
    func(a, b); printf(" * "); func(c, d); printf(" = "); func(a * c, b * d); printf("\n");
    func(a, b); printf(" / "); func(c, d); printf(" = "); func(a * d, b * c); printf("\n");
}
int main() {
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    print();
    return 0;
}