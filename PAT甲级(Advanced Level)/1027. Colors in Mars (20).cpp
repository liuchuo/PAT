1027. Colors in Mars (20)
People in Mars represent the colors in their computers in a similar way as the Earth people. That is, a color is represented by a 6-digit number, where the first 2 digits are for Red, the middle 2 digits for Green, and the last 2 digits for Blue. The only difference is that they use radix 13 (0-9 and A-C) instead of 16. Now given a color in three decimal numbers (each between 0 and 168), you are supposed to output their Mars RGB values.
Input
Each input file contains one test case which occupies a line containing the three decimal color values.
Output
For each test case you should output the Mars RGB value in the following format: first output "#, then followed by a 6-digit number where all the English characters must be upper-cased. If a single color is only 1-digit long, you must print a "0" to the left.
Sample Input
15 43 71
Sample Output
#123456

题目大意：给三个十进制的数，把它们转换为十三进制的数输出。要求在前面加上一个"#"号
分析：因为0~168的十进制转换为13进制不会超过两位数，所以这个两位数为(num / 13)(num % 13)构成的数字

#include <iostream>
using namespace std;
int main() {
    char c[14] = {"0123456789ABC"};
    printf("#");
    for(int i = 0; i < 3; i++) {
        int num;
        scanf("%d", &num);
        printf("%c%c", c[num/13], c[num%13]);
    }
    return 0;
}
