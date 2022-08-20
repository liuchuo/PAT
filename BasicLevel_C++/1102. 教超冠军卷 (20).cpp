#include <iostream>
using namespace std;
int n, a, b, maxN = -1, maxS = -1;
string name, ansN, ansS; 
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name >> a >> b;
        if (b > maxN) {
            maxN = b;
            ansN = name;
        }
        if (a * b > maxS) {
            maxS = a * b;
            ansS = name;
        }
    }
    cout << ansN << ' ' << maxN << '\n' << ansS << ' ' << maxS;
    return 0;
}