#include <iostream>
using namespace std;
bool isprime(int a) {
    for (int i = 2; i * i <= a; i++)
        if(a % i == 0) return false;
    return true;
}
int main() {
    int M, N, num = 2, cnt = 0, tab=0;
    cin >> M >> N;
    while (cnt < N) {
        if (isprime(num)) {
            cnt++;
            if (cnt >= M) {
                tab++;
                if(tab != 1) cout << ' ';
                cout << num;
                if(tab == 10) {
                    cout << '\n';
                    tab = 0;
                }
            }
        }
        num++;
    }
    return 0;
}
