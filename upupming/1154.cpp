#include <iostream>
#include <set>

using namespace std;

#define N 10009

int from[N], to[N], color[N], n, m, k;
set<int> colors;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> from[i] >> to[i];
    cin >> k;
    while(k--){
        colors.clear();
        for (int i = 0; i < n; i++) {
            cin >> color[i];
            colors.insert(color[i]);
        }
        bool flag = true;
        for (int i = 0; i < m; i++) {
            if (color[from[i]] == color[to[i]]) {
                cout << "No" << endl;
                flag = false;
                break;
            }
            // 不能把 colors.insert 放在 else 这里，因为可能有孤立的点，也算做一种颜色
        }
        if (flag) cout << colors.size() << "-coloring" << endl;
    }
    return 0;
}