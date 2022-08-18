#include <bits/stdc++.h>
using namespace std;
int wheel[4], maxn, low, dif, flag;
int main() {
    cin >> wheel[0] >> wheel[1] >> wheel[2] >> wheel[3] >> low >> dif;
    maxn = *max_element(wheel, wheel + 4);
    for (int i = 0; i < 4; i++) {
        if (wheel[i] < low || maxn - wheel[i] > dif) {
            if (!flag) flag = i + 1;
            else {
                cout << "Warning: please check all the tires!";
                return 0;
            }
        }
    }
    if (flag) cout << "Warning: please check #" << flag << "!";
    else cout << "Normal";
    return 0;
}