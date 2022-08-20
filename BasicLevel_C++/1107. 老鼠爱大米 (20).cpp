#include <iostream>
using namespace std;
int n, m, t, d, D;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        d = 0;
        for (int j = 0; j < m; j++) {
            cin >> t;
            d = max(d, t);
        }
        cout << d << ((i == n - 1) ? '\n' : ' ');
        D = max(D, d);
    }
    cout << D;
    return 0;
}