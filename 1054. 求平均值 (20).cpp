/*
1054. 求平均值 (20)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
本题的基本要求非常简单：给定N个实数，计算它们的平均值。但复杂的是有些输入数据可能是非法的。
一个“合法”的输入是[-1000，1000]区间内的实数，并且最多精确到小数点后2位。
当你计算平均值的时候，不能把那些非法的数据算在内。

输入格式：

输入第一行给出正整数N（<=100）。随后一行给出N个正整数，数字间以一个空格分隔。

输出格式：

对每个非法输入，在一行中输出“ERROR: X is not a legal number”，其中X是输入。最后在一行中输出结果：“The average of K numbers is Y”，其中K是合法输入的个数，Y是它们的平均值，精确到小数点后2位。如果平均值无法计算，则用“Undefined”替换Y。如果K为1，则输出“The average of 1 number is Y”。

输入样例1：
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
输出样例1：
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
输入样例2：
2
aaa -9999
输出样例2：
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined
*/

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    double average = 0;
    double aver = 0;
    int num = 0, flag;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int len = s.length();
        aver = 0;
        flag = 0;
        int j;
        // 过滤掉所有含有除了数字和小数点外其他字符的非法输入
        for(j = 1; j < len; j++) {
            if(!((s[j] >= '0' && s[j] <= '9') || s[j] == '.')) {
                cout << "ERROR: " << s << " is not a legal number\n";
                flag = 1;
                break;
            }
        }
        if(flag == 1) continue;
        
        int flag1 = 0;
        //过滤掉第一位不是数字or负号的
        if (!((s[0] >= '0' && s[0] <= '9') || s[0] == '-')) {
            cout << "ERROR: " << s << " is not a legal number\n";
            continue;
        }
        
        //看是正数还是负数
        if (s[0] == '-') {
            flag1 = 1;
        }
        
        // 过滤掉只有一位但不是数字的
        if (len == 1 && !(s[0] >= '0' && s[0] <= '9')) {
            cout << "ERROR: " << s << " is not a legal number\n";
            continue;
        }
        
        // 过滤掉有多个小数点的or多余保留两位数的
        for(j = 0; j < len; j++) {
            if(s[j] == '.') {
                for (int k = j + 1; k < len; k++) {
                    if(s[k] == '.' || k > j + 2) {
                        cout << "ERROR: " << s << " is not a legal number\n";
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if(flag == 1) continue;
        
        // 把字符串转化为数字
        //判断这个字符串有没有小数点 有的话flag = 1
        for (j = 1; j < len; j++) {
            if(s[j] == '.') {
                flag = 1;
            }
        }
        
        int flag2 = 0;
        // 有小数点的情况分析
        if (flag == 1) {
            if(flag1 == 1)
                j = 1;
            else
                j = 0;
            for (; j < len; j++) {
                if (s[j] != '.') {
                    aver = aver * 10 + (s[j] - '0');
                }
                if (s[j] == '.' && (j != len - 1)) {
                    aver = aver + ((double)(s[j + 1] - '0')) / 10;
                    if (j == len - 3) {
                        aver = aver + ((double)(s[j + 2] - '0')) / 100;
                    }
                    break;
                }
            }
        }
        
        // 没有小数点的情况分析
        if (flag == 0) {
            if(flag1 == 1)
                j = 1;
            else
                j = 0;
            for (; j < len; j++) {
                aver = aver * 10 + (s[j] - '0');
            }
        }
        
        //处理负数
        if(flag1 == 1) {
            aver = 0 - aver;
        }
        
        if(aver > 1000 || aver < -1000) {
            cout << "ERROR: " << s << " is not a legal number\n";
            continue;
        } else {
            average = average + aver;
        }
        // 统计个数
        num++;
    }
    
    if (num >= 1) {
        average = average / num;
        if (num != 1) {
            printf("The average of %d numbers is %.2f", num, average);
        }
        else {
            printf("The average of 1 number is %.2f", average);
        }
    } else {
        printf("The average of 0 numbers is Undefined");
    }
    
    return 0;
}



