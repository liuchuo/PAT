#include <cstdio>
using namespace std;
int main() {
    int n, k, num, maxIndex = 0, maxValue = 0;
    scanf("%d", &n);
    int arr[1001] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &num);
            arr[num]++;
        }
    }
    for (int i = 0; i < 1001; i++) {
        if (arr[i] >= maxValue) {
            maxValue = arr[i];
            maxIndex = i;
        }
    }
    printf("%d %d", maxIndex, maxValue);
    return 0;
}