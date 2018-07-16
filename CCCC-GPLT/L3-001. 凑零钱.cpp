L3-001. 凑零钱
韩梅梅喜欢满宇宙到处逛街。现在她逛到了一家火星店里，发现这家店有个特别的规矩：你可以用任何星球的硬币付钱，但是绝不找零，当然也不能欠债。韩梅梅手边有104枚来自各个星球的硬币，需要请你帮她盘算一下，是否可能精确凑出要付的款额。

输入格式：

输入第一行给出两个正整数：N（<=104）是硬币的总个数，M（<=102）是韩梅梅要付的款额。第二行给出N枚硬币的正整数面值。数字间以空格分隔。

输出格式：

在一行中输出硬币的面值 V1 <= V2 <= ... <= Vk，满足条件 V1 + V2 + ... + Vk = M。数字间以1个空格分隔，行首尾不得有多余空格。若解不唯一，则输出最小序列。若无解，则输出“No Solution”。

注：我们说序列{A[1], A[2], ...}比{B[1], B[2], ...}“小”，是指存在 k >= 1 使得 A[i]=B[i] 对所有 i < k 成立，并且 A[k] < B[k]。

输入样例1：
8 9
5 9 8 7 2 3 4 1
输出样例1：
1 3 5
输入样例2：
4 8
7 2 4 3
输出样例2：
No Solution

分析：01背包问题，因为要输出从小到大的排列，可以先把硬币面额从大到小排列，然后用bool类型的choice[i][j]数组dp[i][j]是否选取，如果选取了就令choice为true；然后进行01背包问题求解，如果最后求解的结果不是恰好等于所需要的价值的，就输出No Soultion，否则从choice[i][j]判断选取的情况，i从n到1表示从后往前看第i个物品的选取情况，j从m到0表示从容量m到0是否选取(j = j - w[i])，把选取情况压入arr数组中，最后输出arr数组

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int dp[10010];
int w[10010];
bool choice[10010][10010];
int cmp1(int a, int b){return a > b;}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    sort(w + 1, w + n + 1, cmp1);
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= w[i]; j--) {
            if(dp[j] <= dp[j-w[i]] + w[i]) {
                choice[i][j] = true;
                dp[j] = dp[j-w[i]] + w[i];
            }
        }
    }
    if(dp[m] != m) printf("No Solution");
    else {
        vector<int> arr;
        int v = m, index = n;
        while(v > 0) {
            if(choice[index][v] == true) {
                arr.push_back(w[index]);
                v -= w[index];
            }
            index--;
        }
        for(int i = 0; i < arr.size(); i++) {
            if(i != 0) printf(" ");
            printf("%d", arr[i]);
        }
    }
    return 0;
}