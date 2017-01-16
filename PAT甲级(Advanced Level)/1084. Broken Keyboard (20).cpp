1084. Broken Keyboard (20)
On a broken keyboard, some of the keys are worn out. So when you type some sentences, the characters corresponding to those keys will not appear on screen.

Now given a string that you are supposed to type, and the string that you actually type out, please list those keys which are for sure worn out.

Input Specification:

Each input file contains one test case. For each case, the 1st line contains the original string, and the 2nd line contains the typed-out string. Each string contains no more than 80 characters which are either English letters [A-Z] (case insensitive), digital numbers [0-9], or “_” (representing the space). It is guaranteed that both strings are non-empty.

Output Specification:

For each test case, print in one line the keys that are worn out, in the order of being detected. The English letters must be capitalized. Each worn out key must be printed once only. It is guaranteed that there is at least one worn out key.

Sample Input:
7_This_is_a_test
hssaes
Sample Output:
7TI

#include <iostream>
using namespace std;
int main() {
    string a;
    cin >> a;
    int lena = a.length();
    string b;
    cin >> b;
    int lenb = b.length();
    char c[100];
    int i = 0, j = 0, t = 0;
    
    while (j <= lenb - 1) {
        if (b[j] != a[i]) {
            c[t++] = a[i];
            i++;
        } else {
            i++;
            j++;
        }
    }
    
    if (i != lena) {
        for (int k = i; k <= lena - 1; k++) {
            c[t++] = a[k];
        }
    }
    
    for (int k = 0; k < t; k++) { if (c[k] >= 'a' && c[k] <= 'z')
        c[k] = c[k] - 32;
    }
    
    for (int k = 0; k < t; k++) {
        for (int m = 0; m < k; m++) {
            if (c[m] == c[k]) {
                c[k] = '#';
            }
        }
    }
    
    for (int k = 0; k < t; k++) {
        if (c[k] != '#')
            cout << c[k];
    }
    return 0;
}