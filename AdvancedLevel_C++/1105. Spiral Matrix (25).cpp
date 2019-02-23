#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end(), greater<int>());
    for (k = sqrt(n); n % k != 0; k--);
    m = n / k;
    vector<vector<int>> ans(m, vector<int>(k, 0));
    int i = 0, row = 0, col = 0;
    while (i < n) {
        // 向右填充
        while (i < n && col <  k && ans[row][col] == 0) ans[row][col++] = nums[i++];
        row++; col--;
        // 向下填充
        while (i < n && row <  m && ans[row][col] == 0) ans[row++][col] = nums[i++];
        row--; col--;
        // 向左填充
        while (i < n && col >= 0 && ans[row][col] == 0) ans[row][col--] = nums[i++];
        row--; col++;
        // 向上填充
        while (i < n && row >= 0 && ans[row][col] == 0) ans[row--][col] = nums[i++];
        row++; col++;
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
            cout << ans[i][j] << (j < k - 1 ? ' ' : '\n');
    return 0;
}