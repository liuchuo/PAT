#include <iostream>
#include <cmath>

using namespace std;

// zero[i] 表示所有 a[j] 中第 i 位的 0 的总数
long long t, n, m, a[1005], zeros[55], ones[55];
// Define f(j) to be the minimum value of the above sum over all bits i ≤ j
long long f[55];

long long solve() {
    for (int i = 0; i < 50; i++) {
        // cout << "zeros[" << i << "] = " << zeros[i] << endl;
        // cout << "ones[" << i << "] = " << ones[i] << endl;
        int xorOnes = min(zeros[i], ones[i]);
        f[i] = xorOnes * pow(2, i) + (i > 0 ? f[i-1] : 0);
        // cout << "f[" << i << "] = " << f[i] << endl;
    }
    long long sum = 0, k = 0;
    for (int i = 49; i >= 0; i--) {
        // cout << "zeros[" << i << "] = " << zeros[i] << endl;
        // cout << "ones[" << i << "] = " << ones[i] << endl;
        // k should as max as possible
        long long tail = (i > 0 ? f[i-1] : 0);
        long long current1Value = zeros[i] * pow(2, i);
        long long current0Value = ones[i] * pow(2, i);
        // cout << "current1Value = " << current1Value << endl;
        // cout << "current0Value = " << current0Value << endl;
        // cout << "sum + current1Value + tail = " << sum + current1Value + tail << endl;
        if (sum + current1Value + tail <= m) {
            sum += current1Value;
            k += pow(2, i);
            // cout << "k = " << k << endl;
        } else if (sum + current0Value + tail <= m) {
            sum += current0Value;
        } else {
            return -1;
        }
    }
    return k;
}

long long solve_old() {
    // long long maxK = max(a[0], m);
    // for (int i = 1; i < n; i++) maxK = max(maxK, (long long)a[i]);
    // cout << "maxK = " << maxK << endl;
    long long k = 10000;
    while(k>=0) {
        long long sum = 0;
        for (int i = 0; i < n; i++) sum += a[i] ^ k;
        // cout << "k = " << k << ", sum = " << sum << endl;
        if (sum <= m) return k;
        k--;
    }
    return -1;
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n >> m;
        fill(zeros, zeros + 55, 0);
        fill(ones, ones + 55, 0);
        // N log (max Ai)
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            for (int j = 0; j < 50; j++) {
                // cout << "a[" << i << "] = " << a[i] << ", a[i] >> " << j << " & 1 = " << ((a[i] >> j) & 1) << endl;
                int shift;
                if (j > 31) {
                    shift = a[i] >> 31 >> (j - 31);
                } else shift = a[i] >> j;
                if ((shift & 1) == 1) ones[j]++;
                else zeros[j]++;
            }
        }
        printf("Case #%d: %lld\n", i, solve());
    }
    return 0;
}   