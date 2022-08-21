#include <iostream>
using namespace std;
int n, root = 1, lc[32], rc[32], mark[32];
string Data[32];
void deal(int x) {
    cout << '('; 
    if (lc[x] * rc[x] > 1) {
        deal(lc[x]);
        deal(rc[x]);
    }
    cout << Data[x];
    if (lc[x] * rc[x] < 0) deal(rc[x]);
    cout << ')';
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> Data[i] >> lc[i] >> rc[i];
        mark[lc[i]] = mark[rc[i]] = 1;
    }
    while(mark[root]) root++;
    deal(root);
    return 0;
}