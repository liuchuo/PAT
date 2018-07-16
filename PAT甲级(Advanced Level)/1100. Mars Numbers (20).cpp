1100. Mars Numbers (20)
People on Mars count their numbers with base 13:
Zero on Earth is called "tret" on Mars.
The numbers 1 to 12 on Earch is called "jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec" on Mars, respectively.
For the next higher digit, Mars people name the 12 numbers as "tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou", respectively.
For examples, the number 29 on Earth is called "hel mar" on Mars; and "elo nov" on Mars corresponds to 115 on Earth. In order to help communication between people from these two planets, you are supposed to write a program for mutual translation between Earth and Mars number systems.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (< 100). Then N lines follow, each contains a number in [0, 169), given either in the form of an Earth number, or that of Mars.
Output Specification:
For each number, print in a line the corresponding number in the other language.
Sample Input:
4
29
5
elo nov
tam
Sample Output:
hel mar
may
115
13

#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string a[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct",
"nov", "dec" };
string b[13] = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy",
"lok", "mer", "jou" };
void func1(string s) {
    int len = s.length(), num = 0;
    for (int i = 0; i < len; i++)
        num = num * 10 + (s[i] - '0');
    if (num / 13) {
        cout << b[num / 13];
        if (num % 13) cout << ' ' << a[num % 13];
    } else {
        cout << a[num % 13];
    }
}
void func2(string s) {
    int len = s.length(), num = 0;
    if (len == 4) {
        cout << 0;
        return;
    }
    else if (len == 3) {
        for (int i = 1; i <= 12; i++) {
            if (s == a[i]) {
                cout << i;
                return;
            }
            if (s == b[i]) {
                cout << i * 13;
                return;
            }
        }
    }
    else {
        string temp1 = s.substr(0, 3), temp2 = s.substr(4, 3);
        for (int i = 1; i <= 12; i++) {
            if (temp1 == b[i]) num += i * 13;
            if (temp2 == a[i]) num += i;
        }
        cout << num;
    }
    return;
}
int main() {
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        if (isdigit(s[0]))
            func1(s);
        else
            func2(s);
        cout << endl;
    }
    return 0;
}