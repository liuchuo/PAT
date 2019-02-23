#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    double num, sum = 0.0;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        sum += num * i * (n - i + 1);
    }
    printf("%.2f\n", sum);
    return 0;
}