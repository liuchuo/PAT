#include <iostream>
#include <vector>
using namespace std;
struct stu {
    string s;
    int one, two;
};
int main() {
    int n, m, temp;
    cin >> n;
    vector<stu> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].s >> a[i].one >> a[i].two;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        for (int j = 0; j < n; j++) {
            if (a[j].one == temp) {
                cout << a[j].s << " " << a[j].two << endl;
                break;
            }
        }
    }
    return 0;
}