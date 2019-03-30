#include <iostream>
using namespace std;
int main() {
    long long a, b, c, d, e, f;
    scanf("%lld.%lld.%lld %lld.%lld.%lld", &a, &b, &c, &d, &e, &f);
    long long num = c + b * 29 + a * 29 * 17 + f + e * 29 + d * 29 * 17;
    long long g = num / (17 * 29);
    num = num % (17 * 29);
    printf("%lld.%lld.%lld", g, num / 29, num % 29);
    return 0;
}