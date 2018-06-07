1059. Prime Factors (25)
Given any positive integer N, you are supposed to find all of its prime factors, and write them in the format N = p1^k1 * p2^k2 *…*pm^km.
Input Specification:
Each input file contains one test case which gives a positive integer N in the range of long int.
Output Specification:
Factor N in the format N = p1^k1 * p2^k2 *…*pm^km, where pi's are prime factors of N in increasing order, and the exponent ki is the number of pi -- hence when there is only one pi, ki is 1 and must NOT be printed out.
Sample Input:
97532468
Sample Output:
97532468=2^2*11*17*101*1291
题目大意：给出一个整数，按照从小到大的顺序输出其分解为质因数的乘法算式
分析：先建立个500000以内的素数表，然后从2开始一直判断是否为它的素数，如果是就将a=a/i继续判断i是否为a的素数，判断完成后输出这个素数因子和个数，用state判断是否输入过因子，输入过就要再前面输出“*”

#include <iostream>
#include <vector>
using namespace std;
vector<int> prime(500000, 1);
int main() {
    for(int i = 2; i * i < 500000; i++)
        for(int j = 2; j * i < 500000; j++)
            prime[j * i] = 0;
    long int a;
    scanf("%ld", &a);
    printf("%ld=", a);
    if(a == 1) printf("1");
    bool state = false;
    for(int i = 2; a >= 2;i++) {
        int cnt = 0, flag = 0;
        while(prime[i] == 1 && a % i == 0) {
            cnt++;
            a = a / i;
            flag = 1;
        }
        if(flag) {
            if(state) printf("*");
            printf("%d", i);
            state = true;
        }
        if(cnt >= 2)
            printf("^%d", cnt);
    }
    return 0;
}
