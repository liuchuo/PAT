#include <iostream>
// #include <set>

using namespace std;


#define MAX_LENGTH 100005

int t, n, m, q, p[MAX_LENGTH], r[MAX_LENGTH];
bool isTorn[MAX_LENGTH];
// Let f(x) be the number of pages that are multiples of x and not torn out.
int f[MAX_LENGTH];

// int pmax = 0;
// set<int> pset;
// int solve() {
//     int res = 0;
//     for (int i = 0; i < q; i++) {
//         res += n / r[i];
//         if (r[i] == 1) {
//             res -= pset.size();
//             // cout << "res = " << res << endl;
//         }
//         else for (int val = r[i]; val <= pmax ; val += r[i]) {
//             if (pset.find(val) != pset.end()) res--;
//             // cout << "val = " << val << endl;
//         }
//         // cout << "i = " << i << ", res = " << res << endl;
//     }
//     return res;
// }

long long solve() {
    // O(N log N)
    for (int i = 1; i <= n; i++) {
        f[i] = 0;
        for (int j = i; j <= n; j += i) {
            if (!isTorn[j]) f[i] += 1;
        }
    }
    long long res = 0;
    for (int i = 0; i < q; i++) {
        res += f[r[i]];
    }
    return res;
}

int solve_old() {
    int res = 0;
    for (int i = 0; i < q; i++) {
        res += n / r[i];
        for (int j = 0; j < m; j++) {
            if (p[j] % r[i] == 0) res -= 1;
        }
    }
    return res;
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n >> m >> q;
        fill(isTorn, isTorn + MAX_LENGTH, false);
        // pset.clear(); pmax = 0;
        for (int i = 0; i < m; i++) {
            cin >> p[i];
            isTorn[p[i]] = true;
            // pset.insert(p[i]);
            // pmax = max(pmax, p[i]);
        }
        for (int i = 0; i < q; i++) cin >> r[i];
        printf("Case #%d: %lld\n", i, solve());
    }
    return 0;
}