#include <iostream>
using namespace std;
int main() {
    string a, b;
    int m, n, counta = 0, countb = 0, ta = 0, tb = 0;
    cin >> a >> m >> b >> n;
    for (int i = 0; i < a.length(); i++)
        if (m == (a[i] - '0')) counta++;
    for (int i = 0; i < b.length(); i++)
        if (n == (b[i] - '0')) countb++;
    if (counta != 0) ta = m;
    if (countb != 0) tb = n;
    for (int i = 1; i < counta; i++)
        ta = 10 * ta + m;
    for (int i = 1; i < countb; i++)
        tb = 10 * tb + n;
    cout << ta + tb;
    return 0;
}