#include <bits/stdc++.h>
using namespace std;
int n, sex, s, t;
int main() {
    cin >> n;
    while (n--) {
        cin >> sex >> s >> t;
        if (sex == 1) {
            if (s < 130) cout << "duo chi yu! ";
            else if (s == 130) cout << "wan mei! ";
            else cout << "ni li hai! ";
            if (t < 27) cout << "duo chi rou!\n";
            else if (t == 27) cout << "wan mei!\n";
            else cout << "shao chi rou!\n";
        } else {
            if (s < 129) cout << "duo chi yu! ";
            else if (s == 129) cout << "wan mei! ";
            else cout << "ni li hai! ";
            if (t < 25) cout << "duo chi rou!\n";
            else if (t == 25) cout << "wan mei!\n";
            else cout << "shao chi rou!\n";
        }
    }
    return 0;
}