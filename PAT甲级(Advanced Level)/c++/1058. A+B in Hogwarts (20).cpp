1058. A+B in Hogwarts (20)
If you are a fan of Harry Potter, you would know the world of magic has its own currency system -- as Hagrid explained it to Harry, "Seventeen silver Sickles to a Galleon and twenty-nine Knuts to a Sickle, it's easy enough." Your job is to write a program to compute A+B where A and B are given in the standard form of "Galleon.Sickle.Knut" (Galleon is an integer in [0, 107], Sickle is an integer in [0, 17), and Knut is an integer in [0, 29)).
Input Specification:
Each input file contains one test case which occupies a line with A and B in the standard form, separated by one space.
Output Specification:
For each test case you should output the sum of A and B in one line, with the same format as the input.
Sample Input:
3.2.1 10.16.27
Sample Output:
14.1.28

题目大意：17个Sickle对换一个Galleon，29个Knut对换一个Sickle。根据Galleon.Sickle.Knut的方式相加A和B
分析：把A和B都化为Knut的形式，然后相加，最后转换为Galleon.Sickle.Knut的形式。
注意：A和B相加有可能超出int范围，使用long long格式存储数据。

#include <iostream>
using namespace std;
int main() {
    long long a, b, c, d, e, f;
    scanf("%lld.%lld.%lld %lld.%lld.%lld", &a, &b, &c, &d, &e, &f);
    long long num = c + b * 29 + a * 29 * 17 + f + e * 29 + d * 29 * 17;
    long long g = num / (17 * 29);
    num = num % (17 * 29);
    printf("%lld.%lld.%lld", g, num / 29, num % 29);
    return 0;
}
