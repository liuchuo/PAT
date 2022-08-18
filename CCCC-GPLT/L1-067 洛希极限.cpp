#include <bits/stdc++.h>
using namespace std;
double a, b, c, ans;
int main() {
    scanf("%lf %lf %lf", &a, &b, &c);
    ans = a * (b == 1.0 ? 1.26 : 2.455);
    printf("%.2lf %s", ans, c > ans ? "^_^" : "T_T");
    return 0;
}