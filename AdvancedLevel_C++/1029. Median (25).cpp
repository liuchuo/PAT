#include <iostream>
using namespace std;
int k[200005];
int main(){
    int n, m, temp, count = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &k[i]);
    k[n + 1] = 0x7fffffff;
    cin >> m;
    int midpos = (n + m + 1) / 2, i = 1;
    for (int j = 1; j <= m; j++) {
        scanf("%d", &temp);
        while (k[i] < temp) {
            count++;
            if (count == midpos) cout << k[i];
            i++;
        }
        count++;
        if (count == midpos) cout << temp;
    }
    while (i <= n) {
        count++;
        if (count == midpos) cout << k[i];
        i++;
    }
    return 0;
}