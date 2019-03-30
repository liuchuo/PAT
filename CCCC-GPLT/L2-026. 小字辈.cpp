#include <iostream>
#include <vector>
#include <set>
using namespace std;
int maxlevel = 1;
vector<vector<int>> v;
set<int> s;
void dfs(int node, int level) {
    if (level > maxlevel) {
        maxlevel = level;
        s.clear();
        s.insert(node);
    } else if (level == maxlevel) {
        s.insert(node);
    }
    for (int i = 0; i < v[node].size(); i++)
        dfs(v[node][i], level+1);
}
int main() {
    int n, num, root = 0;
    cin >> n;
    v.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> num;
        if (num == -1) {
            root = i;
            continue;
        }
        v[num].push_back(i);
    }
    dfs(root, 1);
    cout << maxlevel << endl;
    for (auto it = s.begin(); it != s.end(); it++) {
        if (it != s.begin()) cout << " ";
        cout << *it;
    }
    return 0;
}
