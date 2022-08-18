#include <iostream>
using namespace std;
int main() {
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int temp = 1;
        for(int j = 1; j <= i; j++) temp *= j;
        ans += temp;
    }
    cout << ans;
    return 0;
}