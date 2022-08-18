#include <iostream>
#include <cmath>
using namespace std;
bool isprime(int a) {
    if (a == 1) return false;
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) return false;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (isprime(temp))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}