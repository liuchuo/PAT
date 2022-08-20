#include <iostream>
#include <cmath>
using namespace std;
int p, ans;
int is_prime(int x) {
    if (x < 2) return 0;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0) return 0; 
    return 1;
}
int main() {
    cin >> p;
    if (is_prime(p) && is_prime(p - 6)) {
        cout << "Yes\n" << p - 6;
    } else if (is_prime(p) && is_prime(p + 6)) {
        cout << "Yes\n" << p + 6;
    } else {
        for (ans = p + 1; ; ans++) {
            if (is_prime(ans) && is_prime(ans - 6)) break;
            if (is_prime(ans) && is_prime(ans + 6)) break;
        }
        cout << "No\n" << ans;
    }
    return 0;
}