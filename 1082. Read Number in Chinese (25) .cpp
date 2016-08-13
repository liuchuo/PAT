1082. Read Number in Chinese (25)
Given an integer with no more than 9 digits, you are supposed to read it in the traditional Chinese way. Output "Fu" first if it is negative. For example, -123456789 is read as "Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu". Note: zero ("ling") must be handled correctly according to the Chinese tradition. For example, 100800 is "yi Shi Wan ling ba Bai".
Input Specification:
Each input file contains one test case, which gives an integer with no more than 9 digits.
Output Specification:
For each test case, print in a line the Chinese way of reading the number. The characters are separated by a space and there must be no extra space at the end of the line.
Sample Input 1:
-123456789
Sample Output 1:
Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu
Sample Input 2:
100800
Sample Output 2:
yi Shi Wan ling ba Bai

分析：
1. 四位四位的分离读取，每次read(num)中的num为万或者亿之前的四位数
2. 子函数和主函数里面都设立多个flag1flag2flag3..保证输出的“ling”
3. 设立全局flag表示跨越（从亿到万或者从亿到千，或者从万到千）是否会产生“ling”
4. 空格采取不确定的用flag单独判断的形式，没有统一的形式。


#include <cstdio>
using namespace std;
char c[6][5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};
char t[11][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int a, flag = 0;
void read(int num) {
    int flag1 = 0, flag2 = 0, flag3 = 0;
    if(num / 1000) {
        printf("%s %s", t[num / 1000], c[2]);
        flag1 = 1;
    }
    if(flag == 1 && flag1 == 0) printf("ling ");
    if(num / 100 % 10) {
        if(flag1 == 1) printf(" ");
        printf("%s %s", t[num / 100 % 10], c[1]);
        flag2 = 1;
    }
    if(flag1 == 1 && flag2 == 0 && num % 100 != 0)
        printf(" ling");
    if(num / 10 % 10) {
        if(flag1 == 1 || flag2 == 1) printf(" ");
        printf("%s %s", t[num / 10 % 10], c[0]);
        flag3 = 1;
    }
    if(flag2 == 1 && flag3 == 0 && num % 10 != 0)
        printf(" ling");
    if(num % 10) {
        if(flag1 == 1 || flag2 == 1 || flag3 == 1) printf(" ");
        printf("%s", t[num % 10]);
    }
    
}
int main() {
    int flag1 = 0, flag2 = 0;
    scanf("%d", &a);
    if(a < 0) {
        printf("Fu ");
        a = 0 - a;
    }
    if(a == 0) printf("ling");
    if(a > 99999999) {
        int temp = a / 100000000;
        read(temp);
        printf(" %s", c[4]);
        a = a % 100000000;
        flag1 = 1;
    }
    if(a > 9999) {
        int temp = a / 10000;
        if(flag1 == 1) {
            printf(" ");
            flag = 1;
        }
        read(temp);
        printf(" %s", c[3]);
        a = a % 10000;
        flag2 = 1;
    }
    flag = 0;
    if((flag1 == 1 || flag2 == 1) && a != 0) {
        flag = 1;
        printf(" ");
    }
    read(a);
    return 0;
}