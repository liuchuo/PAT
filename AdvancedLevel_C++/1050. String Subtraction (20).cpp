1050. String Subtraction (20)
Given two strings S1 and S2, S = S1 - S2 is defined to be the remaining string after taking all the characters in S2 from S1. Your task is simply to calculate S1 - S2 for any given strings. However, it might not be that simple to do it fast.
Input Specification:
Each input file contains one test case. Each case consists of two lines which gives S1 and S2, respectively. The string lengths of both strings are no more than 104. It is guaranteed that all the characters are visible ASCII codes and white space, and a new line character signals the end of a string.
Output Specification:
For each test case, print S1 - S2 in one line.
Sample Input:
They are students.
aeiou
Sample Output:
Thy r stdnts.
题目大意：给出两个字符串，在第一个字符串中删除第二个字符串中出现过的所有字符并输出。
分析：用flag[256]数组变量标记str2出现过的字符为true，输出str1的时候根据flag[str1[i]]是否为true,如果是true就不输出

#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main() {
    char s1[100000], s2[100000];
    cin.getline(s1, 100000);
    cin.getline(s2, 100000);
    bool flag[256];
    int lens1 = strlen(s1);
    int lens2 = strlen(s2);
    for(int i = 0; i < lens2; i++)
        flag[s2[i]] = true;
    for(int i = 0; i < lens1; i++)
        if(!flag[s1[i]]) printf("%c", s1[i]);
    return 0;
}