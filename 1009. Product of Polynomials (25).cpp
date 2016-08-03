1009. Product of Polynomials (25)
This time, you are supposed to find A*B where A and B are two polynomials.

Input Specification:

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.

Output Specification:

For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 3 3.6 2 6.0 1 1.6

分析：简单模拟。
double类型的arr数组保存第一组数据，ans数组保存结果。当输入第二组数据的时候，一边进行运算一边保存结果。最后按照指数递减的顺序输出所有不为0的项
注意：因为相乘后指数可能最大为2000，所以ans数组最大要开到2001。

#include <cstdio>
using namespace std;
int main() {
    int n1, n2, a, cnt = 0;
    double b;
    scanf("%d", &n1);
    double arr[1001] = {0.0};
    double ans[2001] = {0.0};
    for(int i = 0; i < n1; i++) {
        scanf("%d %lf", &a, &b);
        arr[a] = b;
    }
    scanf("%d", &n2);
    for(int i = 0; i < n2; i++) {
        scanf("%d %lf", &a, &b);
        for(int j = 0; j < 1001; j++) {
            if(arr[j] != 0.0) {
                ans[j + a] += arr[j] * b;
            }
        }
    }
    for(int i = 2000; i >= 0; i--) {
        if(ans[i] != 0.0) {
            cnt++;
        }
    }
    printf("%d", cnt);
    for(int i = 2000; i >= 0; i--) {
        if(ans[i] != 0.0) {
            printf(" %d %.1f", i, ans[i]);
        }
    }
    return 0;
}