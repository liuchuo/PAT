#include <iostream>
using namespace std;
int main() {
    string a, b;
    int da, db, pa = 0, pb = 0;
    cin >> a >> da >> b >> db;
    for (int i = 0; i < a.length(); i++)
        if (da == (a[i] - '0')) pa = pa * 10 + da;
    for (int i = 0; i < b.length(); i++)
        if (db == (b[i] - '0')) pb = pb * 10 + db;
    cout << pa + pb;
    return 0;
}