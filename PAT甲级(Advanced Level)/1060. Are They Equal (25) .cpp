1060. Are They Equal (25)
If a machine can save only 3 significant digits, the float numbers 12300 and 12358.9 are considered equal since they are both saved as 0.123*105 with simple chopping. Now given the number of significant digits on a machine and two float numbers, you are supposed to tell if they are treated equal in that machine.
Input Specification:
Each input file contains one test case which gives three numbers N, A and B, where N (<100) is the number of significant digits, and A and B are the two float numbers to be compared. Each float number is non-negative, no greater than 10100, and that its total digit number is less than 100.
Output Specification:
For each test case, print in a line "YES" if the two numbers are treated equal, and then the number in the standard form "0.d1...dN*10^k" (d1>0 unless the number is 0); or "NO" if they are not treated equal, and then the two numbers in their standard form. All the terms must be separated by a space, with no extra space at the end of a line.
Note: Simple chopping is assumed without rounding.
Sample Input 1:
3 12300 12358.9
Sample Output 1:
YES 0.123*10^5
Sample Input 2:
3 120 128
Sample Output 2:
NO 0.120*10^3 0.128*10^3

题目大意：给出两个数，问将它们写成保留N位小数的科学计数法后是否相等。如果相等，输出YES，输出他们的科学记数法表示方法。如果不相等输出NO，分别输出他们的科学计数法
分析：
1. cnta 和 cntb 通过扫描字符串得到小数点所在的下标（初始化cnta cntb为字符串长度，即下标为strlen(str））
2. 考虑到可能前面有多余的零，用 p 和 q 通过扫描字符串使 p q 开始于第一个非0（且非小数点）处的下标
3. 如果cnta >= p ，说明小数点在第一个开始的非0数的下标的右边，那么科学计数法的指数为cnta - p ; 否则应该为cnta - p + 1; 字符串b同理。
4. 如果 p 和 q 等于字符串长度， 说明字符串是 0， 此时直接把 cnta（或者cntb）置为0，因为对于0来说乘以几次方都是相等的，如果不置为0可能会出现两个0比较导致判断为它们不相等
5. indexa = 0开始给新的A数组赋值，共赋值n位除去小数点外的正常数字，从p的下标开始。如果p大于等于strlen，说明字符串遍历完毕后依旧没能满足需要的位数，此时需要在A数组后面补上0直到满足n位数字。indexb同理，产生新的B数组
6. 判断A和B是否相等，且cnta和cntb是否相等。如果相等，说明他们用科学计数法表示后是相同的，输出YES，否则输出NO，同时输出正确的科学计数法
注意：
- 10的0次方和1次方都要写。
- 题目中说，无需四舍五入。
- 数组开大点，虽然只有100位，但是很有可能前面的0很多导致根本不止100位。一开始开的110，几乎没有AC的任何测试点。。后来开了10000就AC了~

#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int n, p = 0, q = 0;
    char a[10000], b[10000], A[10000], B[10000];
    scanf("%d%s%s", &n, a, b);
    int cnta = strlen(a), cntb = strlen(b);
    for(int i = 0; i < strlen(a); i++) {
        if(a[i] == '.') {
            cnta = i;
            break;
        }
    }
    for(int i = 0; i < strlen(b); i++) {
        if(b[i] == '.') {
            cntb = i;
            break;
        }
    }
    int indexa = 0, indexb = 0;
    while(a[p] == '0' || a[p] == '.') p++;
    while(b[q] == '0' || b[q] == '.') q++;
    if(cnta >= p)
        cnta = cnta - p;
    else
        cnta = cnta - p + 1;
    if(cntb >= q)
        cntb = cntb - q;
    else
        cntb = cntb - q + 1;
    if(p == strlen(a))
        cnta = 0;
    if(q == strlen(b))
        cntb = 0;
    while(indexa < n) {
        if(a[p] != '.' && p < strlen(a))
            A[indexa++] = a[p];
        else if(p >= strlen(a))
            A[indexa++] = '0';
        p++;
    }
    while(indexb < n) {
        if(b[q] != '.' && q < strlen(b))
            B[indexb++] = b[q];
        else if(q >= strlen(b))
            B[indexb++] = '0';
        q++;
    }
    if(strcmp(A, B) == 0 && cnta == cntb)
        printf("YES 0.%s*10^%d", A, cnta);
    else
        printf("NO 0.%s*10^%d 0.%s*10^%d" , A, cnta, B, cntb);
    return 0;
}