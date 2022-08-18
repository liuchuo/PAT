#include <bits/stdc++.h>
using namespace std;
int n, m;
double temp;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &temp);
        if (temp < (double)m) {
            cout << "On Sale! ";
            printf("%.1lf\n", temp);
        }
    }
    return 0;
}