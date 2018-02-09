1101. Quick Sort (25)
There is a classical process named partition in the famous quick sort algorithm. In this process we typically choose one element as the pivot. Then the elements less than the pivot are moved to its left and those larger than the pivot to its right. Given N distinct positive integers after a run of partition, could you tell how many elements could be the selected pivot for this partition?
For example, given N = 5 and the numbers 1, 3, 2, 4, and 5. We have:
1 could be the pivot since there is no element to its left and all the elements to its right are larger than it;
3 must not be the pivot since although all the elements to its left are smaller, the number 2 to its right is less than it as well;
2 must not be the pivot since although all the elements to its right are larger, the number 3 to its left is larger than it as well;
and for the similar reason, 4 and 5 could also be the pivot.
Hence in total there are 3 pivot candidates.
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (<= 105). Then the next line contains N distinct positive integers no larger than 109. The numbers in a line are separated by spaces.
Output Specification:
For each test case, output in the first line the number of pivot candidates. Then in the next line print these candidates in increasing order. There must be exactly 1 space between two adjacent numbers, and no extra space at the end of each line.
Sample Input:
5
1 3 2 4 5
Sample Output:
3
1 4 5

#include <iostream>
#include <algorithm>
#include <vector>
int a[100000], b[100000];
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(a, a + n);

    int v[100000];
    int max = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if(a[i] == b[i] && b[i] > max) {
            v[cnt++] = b[i];
        }
        if (b[i] > max)
            max = b[i];
    }
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++)
        if(i == 0)
            printf("%d", v[i]);
        else
            printf(" %d", v[i]);
    printf("\n");//不加这句的话会有一个测试点没法通过。。大部分测试用例结尾不输出换行符都可以通过。只有一个出现格式错误，是由于该测试点为特例，其结果为0。没有换行符其结果只有一行～
    return 0;
}
