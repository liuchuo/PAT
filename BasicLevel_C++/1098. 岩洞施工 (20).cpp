#include <bits/stdc++.h>
using namespace std;
int n, a, b, minA = 2000, maxB;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        minA = min(a, minA);
    }
    for (int i = 0; i < n; i++) {
        cin >> b;
        maxB = max(b, maxB);
    }
    if (minA <= maxB) 
        cout << "No " << maxB - minA + 1;
    else 
        cout << "Yes " << minA - maxB;
    return 0;
}