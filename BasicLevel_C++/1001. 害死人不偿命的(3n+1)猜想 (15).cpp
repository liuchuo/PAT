#include <iostream>
using namespace std;
int main() {
    int n, count = 0;
    cin >> n;
    while (n != 1) {
        if (n % 2 != 0) n = 3 * n + 1;
        n = n / 2;
        count++;
    }
    cout << count;
    return 0;
}