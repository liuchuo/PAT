#include <iostream>
const int maxn = 200005;
int n, m, a1[maxn], a2[maxn], cnt = 0, i, j, ans;
int main() {
    scanf("%d", &n);
    for(i = 1; i <= n; i++) scanf("%d", &a1[i]);
    scanf("%d", &m);
    for(i = 1; i <= m; i++) scanf("%d", &a2[i]);
    int target = (n + m + 1) / 2;
    i = 1, j = 1;
    while(i <= n && j <= m) {
        ans = a1[i] <= a2[j] ? a1[i++] : a2[j++];
        if(++cnt == target) break;
    }
    if(i <= n && cnt < target)  
        ans = a1[i + target - cnt - 1];
    else if(j <= m && cnt < target) 
        ans = a2[j + target - cnt - 1];
    printf("%d", ans);
    return 0;
}