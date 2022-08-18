#include <bits/stdc++.h>
using namespace std;
string s;
long long dp[1000001][4], vis[128], last;
int main() {
    cin >> s;
    for (int i = 0; i <= s.size(); i++) dp[i][0] = 1;
    for (int i = 1; i <= s.size(); i++) {
        last = vis[s[i - 1]];
        vis[s[i - 1]] = i;
        for (int j = 1; j <= 3; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            if (last && j - (i - last) >= 0) dp[i][j] -= dp[last - 1][j - (i - last)];
        }
    }
    cout << dp[s.size()][0] + dp[s.size()][1] + dp[s.size()][2] + dp[s.size()][3];
    return 0;
}