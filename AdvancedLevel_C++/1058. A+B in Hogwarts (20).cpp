#include <iostream>
using namespace std;
int main() {
    int a1, b1, c1, a2, b2, c2, a, b, c;
    scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
    c = c1 + c2;
    b = b1 + b2 + c / 29; c = c % 29;
    a = a1 + a2 + b / 17; b = b % 17;
    printf("%d.%d.%d\n", a, b, c);
    return 0;
}