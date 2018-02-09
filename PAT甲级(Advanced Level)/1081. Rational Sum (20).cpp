1081. Rational Sum (20)
Given N rational numbers in the form "numerator/denominator", you are supposed to calculate their sum.
Input Specification:
Each input file contains one test case. Each case starts with a positive integer N (<=100), followed in the next line N rational numbers "a1/b1 a2/b2 ..." where all the numerators and denominators are in the range of "long int". If there is a negative number, then the sign must appear in front of the numerator.
Output Specification:
For each test case, output the sum in the simplest form "integer numerator/denominator" where "integer" is the integer part of the sum, "numerator" < "denominator", and the numerator and the denominator have no common factor. You must output only the fractional part if the integer part is 0.
Sample Input 1:
5
2/5 4/15 1/30 -2/60 8/3
Sample Output 1:
3 1/3
Sample Input 2:
2
4/3 2/3
Sample Output 2:
2
Sample Input 3:
3
1/3 -1/6 1/8
Sample Output 3:
7/24

分析：先根据分数加法的公式累加，后分离出整数部分和分数部分。
分子和分母都在长整型内，所以不能用int存储，否则有一个测试点不通过。
一开始一直是浮点错误，按理来说应该是出现了/0或者%0的情况，找了半天也不知道错在哪里。
后来注意到应该在累加的时候考虑是否会超出long long的范围，所以在累加每一步之前进行分子分母的约分处理，然后就AC了。
以及：abs()在stdlib.h头文件里面。
应该还要考虑整数和小数部分都为0时候输出0的情况，但是测试用例中不涉及，所以如果没有最后两句也是可以AC的。

#include <iostream>
#include <cstdlib>
using namespace std;
long long gcd(long long a, long long b) {return b == 0 ? abs(a) : gcd(b, a % b);}
int main() {
    long long n, a, b, suma = 0, sumb = 1, gcdvalue;
    scanf("%lld", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld/%lld", &a, &b);
        gcdvalue = gcd(a, b);
        a = a / gcdvalue;
        b = b / gcdvalue;
        suma = a * sumb + suma * b;
        sumb = b * sumb;
        gcdvalue = gcd(suma, sumb);
        sumb = sumb / gcdvalue;
        suma = suma / gcdvalue;
    }
    long long integer = suma / sumb;
    suma = suma - (sumb * integer);
    if(integer != 0) {
        printf("%lld", integer);
        if(suma != 0) printf(" ");
    }
    if(suma != 0)
        printf("%lld/%lld", suma, sumb);
    if(integer == 0 && suma == 0)
        printf("0");
    return 0;
}