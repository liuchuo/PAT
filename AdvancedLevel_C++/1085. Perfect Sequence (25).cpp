#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    long long p;
    scanf("%d%lld", &n, &p);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int result = 0, temp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + result; j < n; j++) {
            if (v[j] <= v[i] * p) {
                temp = j - i + 1;
                if (temp > result)
                    result = temp;
            } else {
                break;
            }
        }
    }
    cout << result;
    return 0;
}

#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int main() {
    int n;
    long long p;
    cin >> n >> p;
    if (n == 0) {
        cout << n;
        return 0;
    }
    long long int *a = new long long int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int result = 1;
    for (int i = 0; i < n; i++) {
        result = max((int)(upper_bound(a, a+n, a[i] * p) - (a+i)), result);
    }
    cout << result;
    return 0;
}