#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct node {
    int n, num;
    friend bool operator < (node &a, node &b) {
        if (a.n != b.n) return a.n < b.n;
        return a.num < b.num;
    }
}T;
int N, K, m, temp, sum, sum2, I, II;
vector<node> A;
int is_prime(int x) {
    if (x <= 2) return 0;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return 0; 
    }
    return 1;
}
int main() {
    cin >> N;
    for (int i = 1 ; i <= N; i++) {
        A.clear();
        cout << "Case " << i << '\n';
        cin >> K >> m;
        if (K * 9 < m) cout << "No Solution\n";
        else {
            temp = pow(10, K - 2);
            for (int i = temp / 10; i < temp; i++) {
                sum = 18, sum2 = 0, I = i, II = i + 1;
                while (I) {
                    sum += I % 10;
                    I /= 10;
                    if (sum > m) break;
                }
                while (II) {
                    sum2 += II % 10;
                    II /= 10;
                }
                if (sum == m && is_prime(__gcd(m, sum2))) {
                    T.n = sum2, T.num = i;
                    A.push_back(T);
                }
            }
            sort(A.begin(), A.end());
            if (A.empty()) cout << "No Solution\n";
            for (auto &it : A) {
                cout << it.n << ' ' << it.num << "99\n";
            }
        }
        
    }
    return 0;
}