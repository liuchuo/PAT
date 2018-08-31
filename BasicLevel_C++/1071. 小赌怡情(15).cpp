#include <iostream>
using namespace std;
int main() {
    int T = 0, K = 0, n1 = 0, n2 = 0, b = 0, t = 0;
    scanf("%d %d", &T, &K);
    for (int i = 0; i < K; i++) {
        scanf("%d %d %d %d", &n1, &b, &t, &n2);
        if (T == 0) {
            printf("Game Over.\n");
            return 0;
        } else if (t > T) {
            printf("Not enough tokens.  Total = %d.\n", T);
        } else if (n2 > n1) {
            if (b == 1) {
                T += t;
                printf("Win %d!  Total = %d.\n", t, T);
            } else {
                T -= t;
                printf("Lose %d.  Total = %d.\n", t, T);
            }
        } else if (n2 < n1) {
            if (b == 1) {
                T -= t;
                printf("Lose %d.  Total = %d.\n", t, T);
            } else {
                T += t;
                printf("Win %d!  Total = %d.\n", t, T);
            }
        }
    }
    return 0;
}