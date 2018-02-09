1113. Integer Set Partition (25)
Given a set of N (> 1) positive integers, you are supposed to partition them into two disjoint sets A1 and A2 of n1 and n2 numbers, respectively. Let S1 and S2 denote the sums of all the numbers in A1 and A2, respectively. You are supposed to make the partition so that |n1 - n2| is minimized first, and then |S1 - S2| is maximized.
Input Specification:
Each input file contains one test case. For each case, the first line gives an integer N (2 <= N <= 105), and then N positive integers follow in the next line, separated by spaces. It is guaranteed that all the integers and their sum are less than 231.
Output Specification:
For each case, print in a line two numbers: |n1 - n2| and |S1 - S2|, separated by exactly one space.
Sample Input 1:
10
23 8 10 99 46 2333 46 1 666 555
Sample Output 1:
0 3611
Sample Input 2:
13
110 79 218 69 3721 100 29 135 2 6 13 5188 85
Sample Output 2:
1 9359

题目大意：要求把一个集合分成两个不相交的集合，使得这两个集合的元素个数相差最小的前提下，两个集合的总和之差最大
分析：先把集合内n个元素排序，计算前n/2个元素的总和，然后用总的总和sum - 2 * halfsum即为 |S1 - S2|。
|n1 - n2|就是n % 2的结果，奇数为1，偶数为0。（总和sum的值其实可以在输入的时候就累加得到啦~~~~

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n, sum = 0, halfsum = 0;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        sum += v[i];
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n / 2; i++)
        halfsum += v[i];
    printf("%d %d", n % 2, sum - 2 * halfsum);
    return 0;
}