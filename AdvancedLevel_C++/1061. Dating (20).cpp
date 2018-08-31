#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    int min1 = min(a.length(), b.length());
    int min2 = min(c.length(), d.length());
    string weekday[7] = {"MON ", "TUE ", "WED ", "THU ", "FRI ", "SAT ", "SUN "};
    char t[2];
    int pos, j;
    for (int i = 0; i < min1; i++) {
        if (a[i] == b[i] && (a[i] >= 'A' && a[i] <= 'G')) {
            t[0] = a[i];
            j = i;
            break;
        }
    }
    for (int i = j + 1; i < min1; i++) {
        if (a[i] == b[i] && ((a[i] >= 'A' && a[i] <= 'N') || isdigit(a[i]))) {
            t[1] = a[i];
            break;
        }
    }
    for (int i = 0; i < min2; i++) {
        if (c[i] == d[i] && isalpha(c[i])) {
            pos = i;
            break;
        }
    }
    int m = t[1] - '0';
    if (!isdigit(t[1])) m = t[1] - 'A' + 10;
    cout << weekday[t[0] - 'A'];
    printf("%02d:%02d", m, pos);
    return 0;
}