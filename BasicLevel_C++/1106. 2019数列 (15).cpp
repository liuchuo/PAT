#include <iostream>
using namespace std;
int n, sum, a[4] = {2, 0, 1, 9};
int main() {
    cin >> n;
    for (int i = 0; i < min(4, n); i++) cout << a[i];
    for (int i = 4; i < n; i++) {
        sum = (a[0] + a[1] + a[2] + a[3]) % 10;
        cout << sum;
        a[0] = a[1], a[1] = a[2], a[2] = a[3], a[3] = sum;
    }
    return 0;
}