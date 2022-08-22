#include <iostream>
#include <set>
using namespace std;
int n, m, k, l, u, v, s, e, f, f2, A[201][201];
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        A[u][v] = A[v][u] = 1;
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        f = 0;
        set<int> temp;
        cin >> l;
        for (int j = 0; j < l; j++) {
            cin >> e;
            for (auto it : temp) 
                if (!A[e][it]) f = 1;
            temp.insert(e);
        }
        cout << "Area " << i;
        if (f) {
            cout << " needs help.\n";
        } else {
            for (int i = 1; i <= n; i++) {
                f2 = 1;
                if (temp.count(i)) continue;
                for (auto it : temp) {
                    if (!A[i][it]) {
                        f2 = 0;
                        break;
                    }
                }
                if (f2) {
                    f = i;
                    break;
                }
            }
            if (!f) 
                cout << " is OK.\n";
            else 
                cout << " may invite more people, such as " << f << ".\n"; 
        }
    }
    return 0;
}