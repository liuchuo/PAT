#include <iostream>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < b.length(); i++) {
        for (int j = 0; j < a.length(); j++) {
            if (a[j] == b[i]) {
                b[i] = '#';
                a[j] = '#';
            }
        }
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < b.length(); i++)
        if (b[i] != '#') cnt1++;
    for (int i = 0; i < a.length(); i++)
        if (a[i] != '#') cnt2++;
    if (cnt1 != 0)
        cout << "No " << cnt1;
    else
        cout << "Yes " << cnt2;
    return 0;
}