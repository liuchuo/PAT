1015. Reversible Primes (20)
A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers N (< 105) and D (1 < D <= 10), you are supposed to tell if N is a reversible prime with radix D.

Input Specification:

The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.

Output Specification:

For each test case, print in one line "Yes" if N is a reversible prime with radix D, or "No" if not.

Sample Input:
73 10
23 2
23 10
-2
Sample Output:
Yes
Yes
No
题目大意：如果一个数本身是素数，而且在d进制下反转后的数在十进制下也是素数，就输出Yes，否则就输出No
分析：判断输入是否为负数，判断n是否为素数，把n转换为d进制再反过来转换为10进制，判断是否为素数
#include <cstdio>
#include <cmath>
using namespace std;
bool isprime(int n) {
	if(n <= 1) return false;
	int sqr = int(sqrt(n * 1.0));
	for(int i = 2; i <= sqr; i++) {
		if(n % i == 0)
			return false;
	}
	return true;
}
int main() {
	int n, d;
	while(scanf("%d", &n) != EOF) {
		if(n < 0) break;
		scanf("%d", &d);
		if(isprime(n) == false) {
			printf("No\n");
			continue;
		}
		int len = 0;
		int arr[100];
		do{
			arr[len++] = n % d;
			n = n / d;
		}while(n != 0);
		for(int i = 0; i < len; i++) {
			n = n * d + arr[i];
		}
		if(isprime(n) == false) {
			printf("No\n");
		} else {
			printf("Yes\n");
		}
	}
	return 0;
}