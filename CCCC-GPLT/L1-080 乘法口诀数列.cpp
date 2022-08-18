#include <bits/stdc++.h>
using namespace std;
int a, b, n, last = 3, sum, A[2000];
int main() {
    cin >> a >> b >> n;
    A[1] = a, A[2] = b;
    for (int i = 1; i <= n; i++) {
        sum = A[i] * A[i + 1];
        if (sum < 10) A[last++] = sum;
        else {
            A[last++] = sum / 10;
            A[last++] = sum % 10;
        } 
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) cout << ' ';
        cout << A[i];
     }
    return 0;
}