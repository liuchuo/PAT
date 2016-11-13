1069. The Black Hole of Numbers (20)
For any 4-digit integer except the ones with all the digits being the same, if we sort the digits in non-increasing order first, and then in non-decreasing order, a new number can be obtained by taking the second number from the first one. Repeat in this manner we will soon end up at the number 6174 -- the "black hole" of 4-digit numbers. This number is named Kaprekar Constant.

For example, start from 6767, we'll get:

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...

Given any 4-digit number, you are supposed to illustrate the way it gets into the black hole.

Input Specification:

Each input file contains one test case which gives a positive integer N in the range (0, 10000).

Output Specification:

If all the 4 digits of N are the same, print in one line the equation "N - N = 0000". Else print each step of calculation in a line until 6174 comes out as the difference. All the numbers must be printed as 4-digit numbers.

Sample Input 1:
6767
Sample Output 1:
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
Sample Input 2:
2222
Sample Output 2:
2222 - 2222 = 0000

#include <iostream>
#include <algorithm>
using namespace std;

int cmp1(int a, int b) {
    return a > b;
}
int cmp2(int a, int b) {
    return a < b;
}

int main() {
    int N;
    cin >> N;
    int a[4] = {0};
    int t = 3;
    while (N != 0 && t != -1) {
        a[t--] = N % 10;
        N = N / 10;
    }
    t = 3;
    if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) {
        cout << a[0] << a[0] << a[0] << a[0] << " - " << a[0] << a[0]
             << a[0] << a[0] << " = " << "0000";
        return 0;
    }
    int result = 0;
    int b[4];
    int temp;
    while (result != 6174) {
        for (int i = 0; i < 4; i++) {
            b[i] = a[i];
        }
        sort(a, a + 4, cmp1);
        sort(b, b + 4, cmp2);
        result = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3] -
        b[0] * 1000 - b[1] * 100 - b[2] * 10 - b[3];
        cout << a[0] << a[1] << a[2] << a[3] << " - " <<
                b[0] << b[1] << b[2] << b[3] << " = ";
        temp = result;
        for (int i = 0; i < 4; i++) {
            a[i] = 0;
        }
        while (temp != 0 && t != -1) {
            a[t--] = temp % 10;
            temp = temp / 10;
        }
        t = 3;
        cout << a[0] << a[1] << a[2] << a[3] << endl;
    }
    return 0;
}