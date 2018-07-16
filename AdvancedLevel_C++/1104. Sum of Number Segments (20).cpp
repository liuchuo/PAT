1104. Sum of Number Segments (20)
Given a sequence of positive numbers, a segment is defined to be a consecutive subsequence. For example, given the sequence {0.1, 0.2, 0.3, 0.4}, we have 10 segments: (0.1) (0.1, 0.2) (0.1, 0.2, 0.3) (0.1, 0.2, 0.3, 0.4) (0.2) (0.2, 0.3) (0.2, 0.3, 0.4) (0.3) (0.3, 0.4) (0.4).
Now given a sequence, you are supposed to find the sum of all the numbers in all the segments. For the previous example, the sum of all the 10 segments is 0.1 + 0.3 + 0.6 + 1.0 + 0.2 + 0.5 + 0.9 + 0.3 + 0.7 + 0.4 = 5.0.
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N, the size of the sequence which is no more than 105. The next line contains N positive numbers in the sequence, each no more than 1.0, separated by a space.
Output Specification:
For each test case, print in one line the sum of all the numbers in all the segments, accurate up to 2 decimal places.
Sample Input:
4
0.1 0.2 0.3 0.4 
Sample Output:
5.00

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    double a[100001];
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum = sum + a[i] * i * (n - i + 1);
    }
    printf("%.2f", sum);
    return 0;
}