#include <bits/stdc++.h>
double n, temp, sum, ans;
int main() {
    scanf("%lf", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &temp);
        sum += 1.0 / temp;
    }
    printf("%.2lf", n / sum);
    return 0;
}