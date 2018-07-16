1005. Spell It Right (20)
Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Input Specification:

Each input file contains one test case. Each case occupies one line which contains an N (<= 10100).

Output Specification:

For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:
12345
Sample Output:
one five

#include <iostream>
#include <vector>
using namespace std;
int main() {
    string s[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string a;
    cin >> a;
    int sum = 0;
    for(int i = 0; i < a.length(); i++) {
        sum += (a[i] - '0');
    }
    vector<int> v;
    while(sum != 0) {
        v.push_back(sum % 10);
        sum = sum / 10;
    }
    int len = v.size();
    if(len == 0) { // if sum == 0 print zero else print s[v[len - 1]] 否则会段错误
        cout << s[0];
    } else {
        cout << s[v[len - 1]];
    }
    for(int i = len - 2; i >= 0; i--) {
        cout << " " << s[v[i]];
    }
    return 0;
}