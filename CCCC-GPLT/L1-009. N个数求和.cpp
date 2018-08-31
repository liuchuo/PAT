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