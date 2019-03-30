#include <iostream>
using namespace std;
int main() {
    int m, n, a, b, num, temp;
    scanf("%d%d%d%d%d", &m, &n, &a, &b, &num);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &temp);
            if (temp >= a && temp <= b)
                temp = num;
            if (j != 0) printf(" ");
            printf("%03d", temp);
        }
        printf("\n");
    }
    return 0;
}