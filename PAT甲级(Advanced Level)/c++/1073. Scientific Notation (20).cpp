1073. Scientific Notation (20)
Scientific notation is the way that scientists easily handle very large numbers or very small numbers. The notation matches the regular expression [+-][1-9]"."[0-9]+E[+-][0-9]+ which means that the integer portion has exactly one digit, there is at least one digit in the fractional portion, and the number and its exponent's signs are always provided even when they are positive.
Now given a real number A in scientific notation, you are supposed to print A in the conventional notation while keeping all the significant figures.
Input Specification:
Each input file contains one test case. For each case, there is one line containing the real number A in scientific notation. The number is no more than 9999 bytes in length and the exponent's absolute value is no more than 9999.
Output Specification:
For each test case, print in one line the input number A in the conventional notation, with all the significant figures kept, including trailing zeros,
Sample Input 1:
+1.23400E-03
Sample Output 1:
0.00123400
Sample Input 2:
-1.2E+10
Sample Output 2:
-12000000000


题目大意：题目给出科学计数法的格式的数字A，要求输出普通数字表示法的A，并保证所有有效位都被保留，包括末尾的0

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int len = s.length();
    if (s[0] == '-')
        cout << "-";
    
    int pose = 0;
    for (int i = 1; i < len; i++) {
        if (s[i] == 'E')
            pose = i;
    }
    
    int after = 0;
    for (int i = pose + 2; i < len; i++) {
        after = (s[i] - '0') + 10 * after;
    }
    
    if (s[pose + 1] == '-') {
        if (0 < after) {
            cout << "0.";
            for (int i = 1; i < after; i++) {
                cout << 0;
            }
            for (int i = 1; i < pose; i++) {
                if (s[i] >= '0' && s[i] <= '9') {
                    cout << s[i];
                }
            }
        } else {
            for (int i = 1; i < pose; i++) {
                if (i == 2 - after) {
                    cout << ".";
                }
                if (s[i] >= '0' && s[i] <= '9') {
                    cout << s[i];
                }
            }
        }
    } else {
        if (pose - 3 < after) {
            if (s[1] != '0')
                cout << s[1];
            for (int i = 3; i < pose; i++) {
                if (s[i] >= '0' && s[i] <= '9') {
                    cout << s[i];
                }
            }
            for (int i = 0; i < after - (pose - 3); i++) {
                cout << 0;
            }
        } else {
            if (s[1] != '0')
                cout << s[1];
            for (int i = 3; i < pose; i++) {
                if (i == 3 + after) {
                    cout << ".";
                }
                if (s[i] >= '0' && s[i] <= '9') {
                    cout << s[i];
                }
            }
        }
    }
    return 0;
}