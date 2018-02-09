1044. Shopping in Mars (25)
Shopping in Mars is quite a different experience. The Mars people pay by chained diamonds. Each diamond has a value (in Mars dollars M$). When making the payment, the chain can be cut at any position for only once and some of the diamonds are taken off the chain one by one. Once a diamond is off the chain, it cannot be taken back. For example, if we have a chain of 8 diamonds with values M$3, 2, 1, 5, 4, 6, 8, 7, and we must pay M$15. We may have 3 options:
1. Cut the chain between 4 and 6, and take off the diamonds from the position 1 to 5 (with values 3+2+1+5+4=15).
2. Cut before 5 or after 6, and take off the diamonds from the position 4 to 6 (with values 5+4+6=15).
3. Cut before 8, and take off the diamonds from the position 7 to 8 (with values 8+7=15).
Now given the chain of diamond values and the amount that a customer has to pay, you are supposed to list all the paying options for the customer.
If it is impossible to pay the exact amount, you must suggest solutions with minimum lost.
Input Specification:
Each input file contains one test case. For each case, the first line contains 2 numbers: N (<=105), the total number of diamonds on the chain, and M (<=108), the amount that the customer has to pay. Then the next line contains N positive numbers D1 ... DN (Di<=103 for all i=1, ..., N) which are the values of the diamonds. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print "i-j" in a line for each pair of i <= j such that Di + ... + Dj = M. Note that if there are more than one solution, all the solutions must be printed in increasing order of i.
If there is no solution, output "i-j" for pairs of i <= j such that Di + ... + Dj > M with (Di + ... + Dj - M) minimized. Again all the solutions must be printed in increasing order of i.
It is guaranteed that the total value of diamonds is sufficient to pay the given amount.
Sample Input 1:
16 15
3 2 1 5 4 6 8 7 16 10 15 11 9 12 14 13
Sample Output 1:
1-5
4-6
7-8
11-11
Sample Input 2:
5 13
2 4 5 7 9
Sample Output 2:
2-4
4-5

题目大意，求一串的数字中连续的一段，使得这个连续的段内数字的和恰好等于所期望的值m。如果不能找到恰好等于，就找让自己付出最少的价格（总和必须大于等于所给值）的那段区间。求所有可能的结果。
分析：一开始用的简单模拟，有两个超时了。后来想到因为sum数组是递增的，所以改用二分法查找～Func函数的作用是二分查找，修改tempsum和j的值～一开始接收输入的时候可以直接保存它的sum函数，即sum[i]表示1～i的所有数字的总和～

#include <cstdio>
#include <vector>
using namespace std;
vector<int> sum, resultArr;
int n, m;
void Func(int i, int &j, int &tempsum) {
    int left = i, right = n;
    while(left < right) {
        int mid = (left + right) / 2;
        if(sum[mid] - sum[i-1] >= m) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    j = right;
    tempsum = sum[j] - sum[i-1];
}
int main() {
    scanf("%d%d", &n, &m);
    sum.resize(n+1);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &sum[i]);
        sum[i] += sum[i-1];
    }
    int minans = sum[n];
    for(int i = 1; i <= n; i++) {
        int j, tempsum;
        Func(i, j, tempsum);
        if(tempsum > minans)
            continue;
        if(tempsum >= m) {
            if(tempsum < minans) {
                resultArr.clear();
                minans = tempsum;
            }
            resultArr.push_back(i);
            resultArr.push_back(j);
        }
    }
    for(int i = 0; i < resultArr.size(); i += 2)
        printf("%d-%d\n", resultArr[i], resultArr[i+1]);
    return 0;
}
