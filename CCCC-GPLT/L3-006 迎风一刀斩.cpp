#include <bits/stdc++.h>
using namespace std;
int n, k1, k2, SLength, LLength, SWidth, LWidth, res, dif, D1, D2, a, b;
vector<pair<int, int>> A(10), B(10);
void deal(const vector<pair<int, int>> &C, const int &l) {
    res = SLength = LLength = SWidth = LWidth = 0;
    for (int i = 0; i < l; i++) {
        if (C[i].first == C[(i + 1) % l].first) {
            res++;
            dif = abs(C[i].second - C[(i + 1) % l].second);
            if (dif > LLength) SLength = LLength, LLength = dif;
            else SLength = dif;
        } else if (C[i].second == C[(i + 1) % l].second) {
            res++;
            dif = abs(C[i].first - C[(i + 1) % l].first);
            if (dif > LWidth) SWidth = LWidth, LWidth = dif;
            else SWidth = dif;
        }
    }
}
string judge() {
    if (k1 > 5 || k2 > 5) return "NO";
    if (k1 == 4 && k2 == 4) {
        deal(A, k1);
        if (res == 4) {
            D1 = LLength, D2 = LWidth;
            deal(B, k2);
            if (res != 4) return "NO";
            if (D1 == LLength || D2 == LWidth || D2 == LLength || D1 == LWidth) return "YES";
        } else if (res == 3) {
            if (SWidth == 0) D1 = LWidth, D2 = LLength - SLength;
            else  D1 = LLength, D2 = LWidth - SWidth;
            deal(B, k2);
            if (res != 3) return "NO";
            if (SWidth == 0 && D1 == LWidth && D2 == LLength - SLength) return "YES";
            else if (SLength == 0 && D1 == LLength && D2 == LWidth - SWidth) return "YES";

        }
        return "NO";
    }
    if (k2 > k1) swap(k1, k2), swap(A, B);
    deal(A, k1);
    if (res != k1 - 1) return "NO";
    D1 = LLength - SLength, D2 = LWidth - SWidth;
    deal(B, k2);
    if (res != k2 - 1) return "NO";
    if ((D1 == LLength  && D2 == LWidth) || (D2 == LLength && D1 == LWidth)) return "YES";
    return "NO";
}
int main() {
    cin >> n;
    while (n--) {
        cin >> k1;
        for (int i = 0; i < k1; i++) cin >> A[i].first >> A[i].second;
        cin >> k2;
        for (int i = 0; i < k2; i++) cin >> B[i].first >> B[i].second;
        cout << judge() << '\n';
    }
    return 0;
}