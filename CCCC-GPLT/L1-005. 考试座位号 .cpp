#include <iostream>
using namespace std;
struct stu {
    string s;
    int one;
    int two;
};

int main() {
    int n;
    cin >> n;
    stu *a = new stu [n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].s;
        cin >> a[i].one;
        cin >> a[i].two;
    }
    int m;
    cin >> m;
    int temp;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        for (int j = 0; j < n; j++) {
            if (a[j].one == temp) {
                cout << a[j].s << " ";
                cout << a[j].two << endl;
                break;
            }
        }
    }
    return 0;
}