#include <iostream>
#include <cctype>

using namespace std;

int charToDigit(char ch) { return isdigit(ch) ? ch - '0' : 10 + ch - 'a'; }

long long toDecimal(string str, int radix) {
    long long decimal = 0;
    for (int i = 0; i < str.length(); i++)
        decimal = decimal * radix + charToDigit(str[i]);
    return decimal;
}

int minRadix(string str) {
    int radix = 0;
    for (int i = 0; i < str.length(); i++)
        radix = max(radix, charToDigit(str[i]) + 1);
    return radix;
}

string x, y;
int tag, radix;

int main() {
    cin >> x >> y >> tag >> radix;
    if (tag == 2) swap(x, y);
    long long valX = toDecimal(x, radix);
    long long low = minRadix(y);
    // 注意进制上限不是 35，不妨进制将上限定为 valX（但是至少是 low），y 为 0 不管如何增大进制都没用了
    long long high = max(valX, low);
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long valY = toDecimal(y, mid);
        if (valY == valX) {
            cout << mid << endl;
            return 0;
        }
        // 注意因为进制太大而溢出的情况
        if (valY > valX || valY < 0) high = mid - 1;
        else low = mid + 1;
    }
    cout << "Impossible" << endl;
    return 0;
}