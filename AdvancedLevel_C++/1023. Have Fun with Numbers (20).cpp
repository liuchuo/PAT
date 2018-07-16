1023. Have Fun with Numbers (20)
Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it again!
Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.
Input Specification:
Each input file contains one test case. Each case contains one positive integer with no more than 20 digits.
Output Specification:
For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not. Then in the next line, print the doubled number.
Sample Input:
1234567899
Sample Output:
Yes
2469135798

题目大意：给出一个长度不超过20的整数，问这个整数两倍后的数位是否为原数位的一个排列。不管是yes还是no最后都要输出整数乘以2的结果
分析：使用char数组存储这个数，没个数的数位乘以2，同时设立book来标记数位出现的情况。只有最后book的每个元素都是0的时候才说明这两个数字是相等的一个排列结果~~~
#include <iostream>
#include <string.h>
using namespace std;
int book[10];
int main() {
    char num[22];
    scanf("%s", num);
    int flag = 0;
    int len = strlen(num);
    for(int i = len - 1; i >= 0; i--) {
        int temp = num[i] - '0';
        book[temp]++;
        temp = temp * 2 + flag;
        flag = 0;
        if(temp >= 10) {
            temp = temp - 10;
            flag = 1;
        }
        num[i] = (temp + '0');
        book[temp]--;
    }
    int flag1 = 0;
    for(int i = 0; i < 10; i++) {
        if(book[i] != 0)
            flag1 = 1;
    }
    if(flag == 1 || flag1 == 1) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }
    if(flag == 1)
        printf("1");
    for(int i = 0; i < len; i++) {
        printf("%c", num[i]);
    }
    return 0;
}