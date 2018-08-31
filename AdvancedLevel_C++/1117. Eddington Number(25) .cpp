#include <iostream>
#include <algorithm>
using namespace std;
int a[1000000];
int main() {
    int n, e = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a+n, greater<int>());
    while(e < n && a[e] > e+1) e++;
    printf("%d", e);
    return 0;
}