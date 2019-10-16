#include <iostream>
#include <algorithm>

using namespace std;

int a[100005], n, ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<int>());
    int i;
    for (i = 0; i < n; i ++) {
        if (a[i] <= i) break;
    }
    ans = i;
    for (int j = i - 1; j >= 0; j--) {
        if (a[j] == ans) ans--;
        else break;
    }
    cout << ans << endl;
    return 0;
}
/**
1
1

1
2

10
6 7 6 9 3 10 8 2 7 8

2
1 2

1
0

3
4 0 1

4  
1 2 2 3

3
3 3 3
*/