#include <bits/stdc++.h>
using namespace std;
int a[3][3], lost = 45, lx, ly, ans, x, y, dir;
int gua[9][3] = {{0, 0, 0}, {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, {1, 5, 9}, {3, 5, 7}};
int got[30] = {0, 0, 0, 0, 0, 0, 10000, 36, 720, 360, 80, 252, 108, 72, 54, 180, 72, 180, 119, 36, 306, 1080, 144, 1800, 3600};
int main() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
            lost -= a[i][j];
            if (a[i][j] == 0) lx = i, ly = j;
        }
    }
    a[lx][ly] = lost;
    for (int i = 0; i < 3; ++i) {
        cin >> x >> y;
        cout << a[x-1][y-1] << endl;
    }
    cin >> dir;
    for (int i = 0; i < 3; ++i) ans += *(a[0] + gua[dir][i] - 1);
    cout << got[ans];
    return 0;
}