1117. Eddington Number(25)
British astronomer Eddington liked to ride a bike. It is said that in order to show off his skill, he has even defined an "Eddington number", E -- that is, the maximum integer E such that it is for E days that one rides more than E miles. Eddington's own E was 87.
Now given everyday's distances that one rides for N days, you are supposed to find the corresponding E (<=N).
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N(<=105), the days of continuous riding. Then N non-negative integers are given in the next line, being the riding distances of everyday.
Output Specification:
For each case, print in a line the Eddington number for these N days.
Sample Input:
10
6 7 6 9 3 10 8 2 7 8
Sample Output:
6

题目大意：英国天文学家爱丁顿很喜欢骑车。据说他为了炫耀自己的骑车功力，还定义了一个“爱丁顿数”E，即满足有E天骑车超过E英里的最大整数E。据说爱丁顿自己的E等于87。
分析：在数组a中存储n天的公里数，对n个数据从大到小排序，i表示了骑车的天数，那么满足a[i] > i+1的最大i+1即为所求

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