#include <iostream>
#include <map>
#include <cmath>
using namespace std;
long long m, n, a, b, d, c, flag, temp;
map<long long, long long> record;
int main() {
    cin >> m >> n;
    for (a = m; a <= n; a++) {
        d = a * a * a - (a-1) * (a-1) * (a-1), c = sqrt(d);
        if (c * c != d) continue;
        for (long long b = 1; b < c; b++) {
            if (record.count(b)) temp = record[b];
            else {
                temp = b * b + (b - 1) * (b - 1);
                record[b] = temp;
            }
            if (temp == c) {
                cout << a << ' ' << b << '\n';
                flag = 1;
                break;
            }
        }
    }
    if (!flag) cout << "No Solution";
    return 0;
}