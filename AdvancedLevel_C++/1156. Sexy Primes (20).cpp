#include <cmath>
#include <iostream>
using namespace std;

bool IsPrime(int x) {
    if (x < 3) return x == 2;
    if (x % 2 == 0) return false;

    int limit = sqrt(x);
    for (int i = 3; i <= limit; i += 2)
        if (x % i == 0) return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    if (IsPrime(n)) {
        if (IsPrime(n - 6)) {
            cout << "Yes" << endl << n - 6 << endl;
            return 0;
        } else if (IsPrime(n + 6)) {
            cout << "Yes" << endl << n + 6 << endl;
            return 0;
        }
    }
    while (true) {
        if (IsPrime(n) && (IsPrime(n - 6) || IsPrime(n + 6))) {
            cout << "No" << endl << n << endl;
            return 0;
        }
        n++;
    }
}