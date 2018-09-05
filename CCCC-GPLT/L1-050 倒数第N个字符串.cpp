#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    int l, n, num;
    cin >> l >> n;
    vector<int> v;
    num = pow(26,l) - n ;
    while(num) {
        v.push_back(num % 26);
        num /= 26;
    }
    for(int i = 0; i < l - v.size(); i++)
        cout << 'a';
    for(int i = v.size() - 1; i >= 0; i--)
        cout << (char)('a' + v[i]);
    return 0;
}