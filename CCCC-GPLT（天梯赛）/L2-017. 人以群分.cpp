L2-017. 人以群分
社交网络中我们给每个人定义了一个“活跃度”，现希望根据这个指标把人群分为两大类，即外向型（outgoing，即活跃度高的）和内向型（introverted，即活跃度低的）。要求两类人群的规模尽可能接近，而他们的总活跃度差距尽可能拉开。

输入格式：
输入第一行给出一个正整数N（2 <= N <= 105）。随后一行给出N个正整数，分别是每个人的活跃度，其间以空格分隔。题目保证这些数字以及它们的和都不会超过231。

输出格式：
按下列格式输出：
Outgoing #: N1
Introverted #: N2
Diff = N3
其中 N1 是外向型人的个数；N2 是内向型人的个数；N3 是两群人总活跃度之差的绝对值。

输入样例1：
10
23 8 10 99 46 2333 46 1 666 555
输出样例1：
Outgoing #: 5
Introverted #: 5
Diff = 3611
输入样例2：
13
110 79 218 69 3721 100 29 135 2 6 13 5188 85
输出样例2：
Outgoing #: 7
Introverted #: 6
Diff = 9359

分析：接收所有数据到数组v中，并且将所有数据的总和累加为sum，然后对数组从小到大排序，计算前一半的总和为half，那么外向的人的个数就为(n + 1) / 2，【因为如果n是偶数就是n/2，如果n是奇数就是n/2 + 1，总的来说就是(n + 1) / 2】，内向的人的个数就是n/2，两者之间的差就是(sum - half) - half【即sum - 2 * half 】～～

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, sum = 0, half = 0;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        sum += v[i];
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n / 2; i++)
        half += v[i];
    printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d", (n + 1) / 2, n / 2, sum - 2 * half);
    return 0;
}