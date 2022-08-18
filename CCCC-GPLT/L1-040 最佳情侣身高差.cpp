#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char c;
        float height;
        scanf("\n%c %f", &c, &height);
        if (c == 'M')
            printf("%.2f\n", height * 1.0 / 1.09);
        else
            printf("%.2f\n", height * 1.09);
    }
    return 0;
}