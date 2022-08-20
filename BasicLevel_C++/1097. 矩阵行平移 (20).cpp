#include <iostream>
using namespace std;
int n, k, x, cnt = 1, Sum[100], A[100][100];
int main() {
    cin >> n >> k >> x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
            if (i & 1) Sum[j] += A[i][j];
        }
    }
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < cnt; j++) Sum[j] += x;
        for (int j = cnt; j < n; j++) Sum[j] += A[i][j-cnt];
        cnt = cnt % k + 1;
    }
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << Sum[i];
    }
    return 0;
}