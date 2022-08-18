#include <bits/stdc++.h>
using namespace std;
struct node {
    double x, y1, y2;
    bool friend operator < (const node &a, const node &b) {
        return a.x < b.x;
    }
}Fruit[10000];
int n, hx, hy;
double kmax, kmin, tkmax, tkmin;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> Fruit[i].x >> Fruit[i].y1 >> Fruit[i].y2;
    sort(Fruit, Fruit + n);
    for (int i = 0, j; i < n; i++) {
        kmax = 1e9, kmin = -1e9;
        for (j = 0; j < n; j++) {
            if (i == j) continue;
            if (i < j) {
                tkmax = (Fruit[j].y1 - Fruit[i].y2) / (Fruit[j].x - Fruit[i].x);
                tkmin = (Fruit[j].y2 - Fruit[i].y2) / (Fruit[j].x - Fruit[i].x);
            } else {
                tkmax = (Fruit[i].y2 - Fruit[j].y2) / (Fruit[i].x - Fruit[j].x);
                tkmin = (Fruit[i].y2 - Fruit[j].y1) / (Fruit[i].x - Fruit[j].x);
            }
            if (tkmax < kmin || tkmin > kmax) break;
            if (tkmax < kmax) {
                kmax = tkmax;
                hx = Fruit[j].x;
                hy = Fruit[j].y1;
            }
            kmin = max(kmin, tkmin);
        }
        if (j == n) {
            cout << hx << ' ' << hy << ' ' << (int)Fruit[i].x << ' ' << (int)Fruit[i].y2;
            break;
        }
    }
    return 0;
}