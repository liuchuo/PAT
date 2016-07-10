1001. A+B Format (20)
Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input
Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

Output
For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input
-1000000 9
Sample Output
-999,991

#include <iostream>
using namespace std;
int main() {
    int a;
    int b;
    cin >> a >> b;
    int result = a + b;
    if (result < 0) {
        cout << "-";
        result = result * (-1);
    }
    int s[7];
    if (result == 0) {
        cout << 0;
        return 0;
    }
    int i = 0;
    while (result != 0) {
        s[i++] = result % 10;
        result = result / 10;
    }
    int count = i;
    for (int j = i - 1; j >= 0; j--) {
        cout << s[j];
        count--;
        if (count % 3 == 0 && count != 0)
            cout << ",";
    }
    return 0;
}
