#include <iostream>
#include <string>
using namespace std;
string a, b;
int d;
int main() {
    cin >> a >> d;
    b = a.substr(a.size() - d) + a.substr(0, a.size() - d);
    double ans = stod(b) / stod(a);
    printf("%.2f", ans);
    return 0;
}