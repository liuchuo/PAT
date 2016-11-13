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

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long p;
    cin >> n >> p;
    if (n == 0) {
        cout << n;
        return 0;
    }
    long long int *a = new long long int [n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    int result = 1;
    int temp = 1;
    for (int i = 0; i <= n - 2; i++) {
        for (int j = i + result; j <= n - 1; j++) {//因为是为了找最大的result，所以下一次j只要从i的result个后面开始找就行了
            if (a[j] <= a[i] * p) {
                temp = j - i + 1;//计算有多少个数满足
                if (temp > result) { //如果比result中存储的大，就更新result的值
                    result = temp;
                }
            } else {
                break;
            }
        }
    }
    cout << result;
    
    return 0;
}