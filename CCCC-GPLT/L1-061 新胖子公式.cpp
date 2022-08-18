#include <bits/stdc++.h>
float kg, m, res;
int main() {
    scanf("%f %f", &kg, &m);
    res = kg / (m * m);
    printf("%.1f\n", res);
    if(res > 25.0) printf("PANG");
    else printf("Hai Xing");
    return 0;
}