#include <bits/stdc++.h>
#define Lx(a) (a << 1) + 1
#define Rx(a) (a << 1) + 2
using namespace std;
int n, m, Size;
long long ans, temp;
pair<int, int> B[100000];
struct segtree {
    vector<long long> values, mins;
    void init(int n) {
        Size = 1;
        while (Size < n) Size *= 2;
        values.assign(2 * Size, 0LL);
        mins.assign(2 * Size, 0LL);
        build(0, 0, Size, n);
    }
    void build(int x, int lx, int rx, int R) {
        if (rx - lx == 1) {
            if (lx < R) {
                cin >> mins[x];
                values[x] = mins[x];
            }
            return;
        }
        int mid = lx + rx >> 1;
        build(Lx(x), lx, mid, R);
        build(Rx(x), mid, rx, R);
        mins[x] = min(mins[Lx(x)], mins[Rx(x)]) + values[x];
    }
    void modify(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            mins[x] += v;
            values[x] += v;
            return;
        }
        int mid = lx + rx >> 1;
        modify(l, r, v, Lx(x), lx, mid);
        modify(l, r, v, Rx(x), mid, rx);
        mins[x] = min(mins[Lx(x)], mins[Rx(x)]) + values[x];
        return;
    }
    long long get_min(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return LLONG_MAX;
        if (lx >= l && rx <= r) return mins[x];
        int mid = lx + rx >> 1;
        long long s1 = get_min(l, r, Lx(x), lx, mid);
        long long s2 = get_min(l, r, Rx(x), mid, rx);
        return min(s1, s2) + values[x];
    }
}st;
bool cmp (const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}
int main() {
    cin >> n >> m;
    st.init(--n);
    for (int i = 0; i < m; i++) {
        cin >> B[i].first >> B[i].second;
        if (B[i].first > B[i].second) swap(B[i].first, B[i].second);
    }
    sort(B, B + m, cmp);
    for (int i = 0; i < m; i++) {
        temp = st.get_min(B[i].first, B[i].second, 0, 0, Size);
        ans += temp;
        st.modify(B[i].first, B[i].second, -temp, 0, 0, Size);
    }
    cout << ans;
    return 0;
}