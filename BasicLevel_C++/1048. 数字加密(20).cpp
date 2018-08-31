#include <iostream>
using namespace std;
int main() {
    string a, b, c;
    cin >> a >> b;
    int lena = a.length(), lenb = b.length();
    for (int i = 0; i <= lena / 2 - 1; i++)
        swap(a[i], a[lena-1-i]);
    for (int i = 0; i <= lenb / 2 - 1; i++)
        swap(b[i], b[lenb-1-i]);
    if (lena > lenb)
        b.append(lena - lenb, '0');
    else
        a.append(lenb - lena, '0');
    char str[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
    for (int i = 0; i < a.length(); i++) {
        if (i % 2 == 0) {
            c += str[(a[i] - '0' + b[i] - '0') % 13];
        } else {
            int temp = b[i] - a[i];
            if (temp < 0) temp = temp + 10;
            c += str[temp];
        }
    }
    for (int i = c.length() - 1; i >= 0; i--)
        cout << c[i];
    return 0;
}