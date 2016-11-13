L1-009. N个数求和

输入格式：

输入第一行给出一个正整数N（<=100）。随后一行按格式“a1/b1 a2/b2 ...”给出N个有理数。题目保证所有分子和分母都在长整型范围内。另外，负数的符号一定出现在分子前面。

输出格式：

输出上述数字和的最简形式 —— 即将结果写成“整数部分 分数部分”，其中分数部分写成“分子/分母”，要求分子小于分母，且它们没有公因子。如果结果的整数部分为0，则只输出分数部分。

输入样例1：
5
2/5 4/15 1/30 -2/60 8/3
输出样例1：
3 1/3
输入样例2：
2
4/3 2/3
输出样例2：
2
输入样例3：
3
1/3 -1/6 1/8
输出样例3：
7/24

分析：先根据分数加法的公式累加，后分离出整数部分和分数部分。
分子和分母都在长整型内，所以不能用int存储，否则有一个测试点不通过。
一开始一直是浮点错误，按理来说应该是出现了/0或者%0的情况，找了半天也不知道错在哪里。
后来注意到应该在累加的时候考虑是否会超出long long的范围，所以在累加每一步之前进行分子分母的约分处理，然后就AC了。
以及：abs()在stdlib.h头文件里面。
应该还要考虑整数和小数部分都为0时候输出0的情况，但是测试用例中不涉及，所以如果没有最后两句也是可以AC的。

#include <cstdio>
#include <cstdlib>
using namespace std;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
int main() {
    long long n, a, b, suma = 0, sumb = 1, gcdvalue;
    scanf("%lld", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld/%lld", &a, &b);
        gcdvalue = (suma == 0 || sumb == 0) ? 1 : gcd(abs(suma), abs(sumb));
        sumb = sumb / gcdvalue;
        suma = suma / gcdvalue;
        gcdvalue = (a == 0 || b == 0) ? 1 : gcd(abs(a), abs(b));
        a = a / gcdvalue;
        b = b / gcdvalue;
        suma = a * sumb + suma * b;
        sumb = b * sumb;
    }
    long long integer = suma / sumb;
    suma = suma - (sumb * integer);
    gcdvalue = (suma == 0 || sumb == 0) ? 1 : gcd(abs(suma), abs(sumb));
    suma = suma / gcdvalue;
    sumb = sumb / gcdvalue;
    if(integer != 0) {
        printf("%lld", integer);
        if(suma != 0)
            printf(" ");
    }
    if(suma != 0) {
        printf("%lld/%lld", suma, sumb);
    }
    if(integer == 0 && suma == 0)
        printf("0");
    return 0;
}