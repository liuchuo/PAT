1093. Count PAT's (25)
The string APPAPT contains two PAT's as substrings. The first one is formed by the 2nd, the 4th, and the 6th characters, and the second one is formed by the 3rd, the 4th, and the 6th characters.
Now given any string, you are supposed to tell the number of PAT's contained in the string.
Input Specification:
Each input file contains one test case. For each case, there is only one line giving a string of no more than 105 characters containing only P, A, or T.
Output Specification:
For each test case, print in one line the number of PAT's contained in the string. Since the result may be a huge number, you only have to output the result moded by 1000000007.
Sample Input:
APPAPT
Sample Output:
2

#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    int len = s.length();
    int result = 0;
    int countp = 0;
    int countt = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'T')
            countt++;
    }
    for (int i = 0; i < len; i++) {
        if (s[i] == 'P') countp++;
        if (s[i] == 'T') countt--;
        if (s[i] == 'A') {
            result = (result + (countp * countt) % 1000000007) % 1000000007;
        }
    }
    cout << result;
    return 0;
}