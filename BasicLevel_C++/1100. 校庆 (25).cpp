#include <iostream>
#include <set>
using namespace std;
int n, m, cnt;
string temp, smallx = "99999999", smalla = "99999999", ansx, ansa;
set<string> record;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        record.insert(temp);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        if (record.count(temp)) {
            cnt++;
            if (smallx > temp.substr(6, 8)) {
                smallx = temp.substr(6, 8);
                ansx = temp;
            }
        }
        if (smalla > temp.substr(6, 8)) {
            smalla = temp.substr(6, 8);
            ansa = temp;
        }
    }
    cout << cnt << endl;
    if (cnt) cout << ansx;
    else cout << ansa;
    return 0;
}