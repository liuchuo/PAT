1065. A+B and C (64bit) (20)
Given three integers A, B and C in [-263, 263], you are supposed to tell whether A+B > C.
Input Specification:
The first line of the input gives the positive number of test cases, T (<=10). Then T test cases follow, each consists of a single line containing three integers A, B and C, separated by single spaces.
Output Specification:
For each test case, output in one line "Case #X: true" if A+B>C, or "Case #X: false" otherwise, where X is the case number (starting from 1)."
Sample Input:
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0
Sample Output:
Case #1: false
Case #2: true
Case #3: false


分析：简单模拟。
因为A、B的大小为[-2^63, 2^63]，用long long 存储A和B的值，以及他们相加的值sum：
如果A > 0, B < 0 或者 A < 0, B > 0，sum是不可能溢出的
如果A > 0, B > 0，sum可能会溢出，sum范围理应为(0, 2^64 - 2]，溢出得到的结果应该是[-2^63, -2]是个负数，所以sum < 0时候说明溢出了
如果A < 0, B < 0，sum可能会溢出，同理，sum溢出后结果是大于0的，所以sum > 0 说明溢出了

#include <cstdio>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        long long sum = a + b;
        if(a > 0 && b > 0 && sum < 0) {
            printf("Case #%d: true\n", i + 1);
        } else if(a < 0 && b < 0 && sum >= 0){
            printf("Case #%d: false\n", i + 1);
        } else if(sum > c) {
            printf("Case #%d: true\n", i + 1);
        } else {
            printf("Case #%d: false\n", i + 1);
        }
    }
    return 0;
}