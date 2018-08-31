#include <iostream>
using namespace std;
int main() {
    int n, d, k, maybe = 0, must = 0;
    double e, temp;
    cin >> n >> e >> d;
    for (int i = 0; i < n; i++) {
        cin >> k;
        int sum = 0;
        for (int j = 0; j < k; j++) {
            cin >> temp;
            if (temp < e) sum++;
        }
        if(sum > (k / 2)) {
            k > d ? must++ : maybe++;
        }
    }
    double mayberesult = (double)maybe / n * 100;
    double mustresult = (double)must / n * 100;
    printf("%.1f%% %.1f%%", mayberesult, mustresult);
    return 0;
}