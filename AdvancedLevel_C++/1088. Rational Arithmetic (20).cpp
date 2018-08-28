1088. Rational Arithmetic (20)
For two rational numbers, your task is to implement the basic arithmetics, that is, to calculate their sum, difference, product and quotient.
Input Specification:
Each input file contains one test case, which gives in one line the two rational numbers in the format "a1/b1 a2/b2". The numerators and the denominators are all in the range of long int. If there is a negative sign, it must appear only in front of the numerator. The denominators are guaranteed to be non-zero numbers.
Output Specification:
For each test case, print in 4 lines the sum, difference, product and quotient of the two rational numbers, respectively. The format of each line is "number1 operator number2 = result". Notice that all the rational numbers must be in their simplest form "k a/b", where k is the integer part, and a/b is the simplest fraction part. If the number is negative, it must be included in a pair of parentheses. If the denominator in the division is zero, output "Inf" as the result. It is guaranteed that all the output integers are in the range of long int.
Sample Input 1:
2/3 -4/2
Sample Output 1:
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
Sample Input 2:
5/3 0/6
Sample Output 2:
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf

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