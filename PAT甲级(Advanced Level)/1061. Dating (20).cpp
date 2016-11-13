1061. Dating (20)
Sherlock Holmes received a note with some strange strings: "Let's date! 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm". It took him only a minute to figure out that those strange strings are actually referring to the coded time "Thursday 14:04" -- since the first common capital English letter (case sensitive) shared by the first two strings is the 4th capital letter 'D', representing the 4th day in a week; the second common character is the 5th capital letter 'E', representing the 14th hour (hence the hours from 0 to 23 in a day are represented by the numbers from 0 to 9 and the capital letters from A to N, respectively); and the English letter shared by the last two strings is 's' at the 4th position, representing the 4th minute. Now given two pairs of strings, you are supposed to help Sherlock decode the dating time.

Input Specification:

Each input file contains one test case. Each case gives 4 non-empty strings of no more than 60 characters without white space in 4 lines.

Output Specification:

For each test case, print the decoded time in one line, in the format "DAY HH:MM", where "DAY" is a 3-character abbreviation for the days in a week -- that is, "MON" for Monday, "TUE" for Tuesday, "WED" for Wednesday, "THU" for Thursday, "FRI" for Friday, "SAT" for Saturday, and "SUN" for Sunday. It is guaranteed that the result is unique for each case.

Sample Input:
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
Sample Output:
THU 14:04

#include <iostream>
#include <string>
using namespace std;
int main() {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    int lena = a.length();
    int lenb = b.length();
    int min1 = lena < lenb ? lena : lenb;
    int lenc = c.length();
    int lend = d.length();
    int min2 = lenc < lend ? lenc : lend;
    string weekday[7] = {"MON ", "TUE ", "WED ", "THU ", "FRI ", "SAT ", "SUN "};
    char t[2];
    int pos;
    int j;
    for (int i = 0; i < min1; i++) {
        if (a[i] == b[i] && (a[i] >= 'A' && a[i] <= 'G')) {
            t[0] = a[i];
            a[i] = '#';
            j = i;
            break;
        }
    }
    for (int i = j + 1; i < min1; i++) {
        if (a[i] == b[i] && ((a[i] >= 'A' && a[i] <= 'N') ||
                             (a[i] >= '0' && a[i] <= '9'))) {
            t[1] = a[i];
            break;
        }
    }
    for (int i = 0; i < min2; i++) {
        if (c[i] == d[i] && ((c[i] >= 'A' && c[i] <= 'Z') || (c[i] >= 'a' && c[i] <= 'z'))) {
            pos = i;
            break;
        }
    }

    int m;
    if (t[1] >= '0' && t[1] <= '9') {
        m = t[1] - '0';
    } else {
        m = t[1] - 'A' + 10;
    }
    cout << weekday[t[0] - 'A'];
    if (m >= 0 && m <= 9) {
        cout << 0 << m << ":";
    } else {
        cout << m << ":";
    }
    if (pos >= 0 && pos <= 9) {
        cout << 0 << pos;
    } else {
        cout << pos;
    }
    return 0;
}