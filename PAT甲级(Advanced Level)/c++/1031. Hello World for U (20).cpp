1031. Hello World for U (20)
Given any string of N (>=5) characters, you are asked to form the characters into the shape of U. For example, "helloworld" can be printed as:
h  d
e  l
l  r
lowo
That is, the characters must be printed in the original order, starting top-down from the left vertical line with n1 characters, then left to right along the bottom line with n2 characters, and finally bottom-up along the vertical line with n3 characters. And more, we would like U to be as squared as possible -- that is, it must be satisfied that n1 = n3 = max { k| k <= n2 for all 3 <= n2 <= N } with n1 + n2 + n3 - 2 = N.

Input Specification:
Each input file contains one test case. Each case contains one string with no less than 5 and no more than 80 characters in a line. The string contains no white space.

Output Specification:
For each test case, print the input string in the shape of U as specified in the description.

Sample Input:
helloworld!

Sample Output:
h   !
e   d
l   l
lowor

题目大意：用所给字符串按U型输出。n1和n3是左右两条竖线从上到下的字符个数，n2是底部横线从左到右的字符个数。
要求：
1. n1 == n3
2. n2 >= n1
3. n1为在满足上述条件的情况下的最大值

分析：假设n = 字符串长度 + 2，因为2 * n1 + n2 = n，且要保证n2 >= n1, n1尽可能地大，分类讨论：
1. 如果n % 3 == 0，n正好被3整除，直接n1 == n2 == n3;
2. 如果n % 3 == 1，因为n2要比n1大，所以把多出来的那1个给n2
3. 如果n % 3 == 2, 就把多出来的那2个给n2
所以得到公式：n1 = n / 3，n2 = n / 3 + n % 3
把它们存储到二维字符数组中，一开始初始化字符数组为空格，然后按照u型填充进去，最后输出这个数组u。

#include <iostream>
#include <string.h>
using namespace std;
int main() {
    char c[81];
    char u[30][30];
    memset(u, ' ', sizeof(u));
    scanf("%s", c);
    int n = strlen(c) + 2;
    int n1 = n / 3;
    int n2 = n1 + n % 3, index = 0;
    for(int i = 0; i < n1; i++) u[i][0] = c[index++];
    for(int i = 1; i <= n2 - 2; i++) u[n1-1][i] = c[index++];
    for(int i = n1 - 1; i >= 0; i--) u[i][n2-1] = c[index++];
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++)
            printf("%c", u[i][j]);
        printf("\n");
    }
    return 0;
}
