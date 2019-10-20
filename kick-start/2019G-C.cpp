#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

int t, n, h, a[50], b[50];

struct Pair {
    // pa, pb 分别表示 A, B 得到的 happiness
    long long pa, pb;
    Pair(const Pair & p) {
        this->pa = p.pa;
        this->pb = p.pb;
    }
    Pair() { this->pa = this->pb = 0;}
} pointPair;

int cmp(Pair a, Pair b) {
    if (a.pa != b.pa) return a.pa < b.pa;
    else return a.pb < b.pb;
}

// O(3^N)
void dfs(int shiftNo, int total, const Pair& tmpPair, vector<Pair>& pairs) {
    if (shiftNo == total) {
        pairs.push_back(tmpPair);
        return;
    }
    Pair p1(tmpPair), p2(tmpPair), p3(tmpPair);
    // A guards
    p1.pa += a[shiftNo];
    dfs(shiftNo+1, total, p1, pairs);
    // B guards
    p2.pb += b[shiftNo];
    dfs(shiftNo+1, total, p2, pairs);
    // A & B guard
    p3.pa += a[shiftNo];
    p3.pb += b[shiftNo];
    dfs(shiftNo+1, total, p3, pairs);
}

long long solve() {
    long long res = 0;

    vector<Pair> pairsA, pairsB;
    pointPair.pa = pointPair.pb = 0;
    // 关键思想在折半
    dfs(0, n / 2, pointPair, pairsA);
    dfs(n / 2, n, pointPair, pairsB);

    sort(pairsA.begin(), pairsA.end(), cmp);
    sort(pairsB.begin(), pairsB.end(), cmp);

    // O(3^{N/2})
    for (vector<Pair>::iterator it = pairsA.begin(); it != pairsA.end(); it++) {
        // cout << "(h1, h2) = (" << (it->pa) << ", " << (it->pb) << ")" << endl;
        // // 不能用 set，因为 set 不计算重复元素
        // priority_queue<long long> s;
        long long i = -1, low = 0, high = pairsB.size() - 1;
        // 这里必须使用二分查找
        while(low <= high) {
            long long mid = (low + high) / 2;
            if (pairsB[mid].pa < h - it->pa) {
                low = mid + 1;
            } else {
                i = mid;
                high = mid - 1;
            }
        }
        // cout << "i = " << i << endl;

        // O(3^{N/2})
        // for (i = 0; i < pairsB.size() && !(pairsB[i].pa >= h - it->pa); i++) ;

        for (; i < pairsB.size() && i >= 0; i++) {
            // cout << "(p1, p2) = (" << (pairsB[i].pa) << ", " << (pairsB[i].pb) << ")" << endl;
            // s.push(pairsB[i].pb);
            if (pairsB[i].pb >= (h - it->pb)) res++;
        }
        // cout << "distance(s.lower_bound(" << h - it->pb <<"), s.end()) = " << distance(s.lower_bound(h - it->pb), s.end()) << endl; 
        // while(!s.empty() && s.top() >= (h - it->pb)) {
        //     res++;
        //     s.pop();
        // }
        // res += distance(s.lower_bound(h - it->pb), s.end());
    }
    return res;
}

long long solve_old() {
    // return getChoices(a) * getChoices(b);
    long long maxVal = pow(2, n), res = 0;
    for (long long i = 0; i < maxVal; i++) {
        for (long long j = 0; j < maxVal; j++) {
            if ((i|j) != maxVal-1) continue;
            // cout << "i = " << i << ", j = " << j << endl;
            long long suma = 0, sumb = 0;
            for (int k = 0; k < n; k++) {
                int lastBit = (i >> k) & 1;
                suma += lastBit ? a[k] : 0;
                lastBit = (j >> k) & 1;
                sumb += lastBit ? b[k] : 0;
            }
            // cout << "suma = " << suma << ", sumb = " << sumb << endl;
            if (suma >= h && sumb >= h) res += 1;
        }
    }
    return res;
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n >> h;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        printf("Case #%d: %lld\n", i, solve());
    }
    return 0;
}

/**

1
1 0
3
2

1
2 0
3 3
2 4
*/
