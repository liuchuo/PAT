1085. Perfect Sequence (25)
Given a sequence of positive integers and another positive integer p. The sequence is said to be a "perfect sequence" if M <= m * p where M and m are the maximum and minimum numbers in the sequence, respectively.
Now given a sequence and a parameter p, you are supposed to find from the sequence as many numbers as possible to form a perfect subsequence.
Input Specification:
Each input file contains one test case. For each case, the first line contains two positive integers N and p, where N (<= 105) is the number of integers in the sequence, and p (<= 109) is the parameter. In the second line there are N positive integers, each is no greater than 109.
Output Specification:
For each test case, print in one line the maximum number of integers that can be chosen to form a perfect subsequence.
Sample Input:
10 8
2 3 20 4 5 1 6 7 8 9
Sample Output:
8
题目大意：给定一个正整数数列，和正整数p，设这个数列中的最大值是M，最小值是m，如果M <= m * p，则称这个数列是完美数列。现在给定参数p和一些正整数，请你从中选择尽可能多的数构成一个完美数列。输入第一行给出两个正整数N（输入正数的个数）和p（给定的参数），第二行给出N个正整数。在一行中输出最多可以选择多少个数可以用它们组成一个完美数列

分析：简单题。首先将数列从小到大排序，设当前结果为result = 0，当前最长长度为temp = 0；从i = 0～n，j从i + result到n，【因为是为了找最大的result，所以下一次j只要从i的result个后面开始找就行了】每次计算temp若大于result则更新result，最后输出result的值～

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    long long p;
    scanf("%d%lld", &n, &p);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int result = 0, temp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + result; j < n; j++) {
            if (v[j] <= v[i] * p) {
                temp = j - i + 1;
                if (temp > result)
                    result = temp;
            } else {
                break;
            }
        }
    }
    cout << result;
    return 0;
}

【solution 2】如果熟练使用upper_bound()，可以使用以下解法解决问题（代码由Github用户littlesevenmo提供，在此表达感谢）：

#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main() {
    int n;
    long long p;
    cin >> n >> p;
    if (n == 0) {
        cout << n;
        return 0;
    }
    long long int *a = new long long int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int result = 1;
    for (int i = 0; i < n; i++) {
        result = max((int)(upper_bound(a, a+n, a[i] * p) - (a+i)), result);
    }
    cout << result;
    return 0;
}