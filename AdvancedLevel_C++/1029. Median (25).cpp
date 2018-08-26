1029 Median（25 分）
Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1 = { 11, 12, 13, 14 } is 12, and the median of S2 = { 9, 10, 15, 16, 17 } is 15. The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.

Given two increasing sequences of integers, you are asked to find their median.

Input Specification:
Each input file contains one test case. Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer N (≤2×10
​5
​​ ) is the size of that sequence. Then N integers follow, separated by a space. It is guaranteed that all the integers are in the range of long int.

Output Specification:
For each test case you should output the median of the two given sequences in a line.

Sample Input:
4 11 12 13 14
5 9 10 15 16 17
Sample Output:
13

题目大意：给出两个已排序序列，求这两个序列合并后的中间数

分析：开一个数组，在线处理第二个数组。 第一二个数组（下标从1开始）分别有n，m个元素，中间数在(n + m + 1) / 2的位置。所以只要从小到大数到(n + m + 1) / 2的位置就行了~ count计总个数 ，给第一个数组设置指针i，每次从第二个数组中读入temp，检查第一个数组中前几个数是不是比temp小，小就count+1并判断是否到数了中间数，到了就输出。 如果数完比temp小的数还没到中间数，count+1，检查temp是不是中间数，是就输出。循环上述过程。如果第二个数组读取完了，还没数到中间数，说明中间数在剩下的第一个数组中，就在剩下的数组中数到中间数位置即可

PS：感谢LittleMeepo提供的更优解～

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