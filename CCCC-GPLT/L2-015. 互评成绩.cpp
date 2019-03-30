#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int cmp1(double a, double b) {return a > b;}
int main() {
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    vector<double> total;
    for(int i = 0; i < n; i++) {
        vector<double> v(k);
        double maxn = -1, minn = 101, average = 0.0;
        for(int j = 0; j < k; j++) {
            scanf("%lf", v[j]);
            maxn = max(maxn, v[j]);
            minn = min(minn, v[j]);
            average += v[j];
        }
        average = average / (k - 2);
        total.push_back(average);
    }
    sort(total.begin(), total.end(), cmp1);
    if(m != 0)
        printf("%.3f", total[m - 1]);
    for(int i = m - 2; i >= 0; i--)
        printf(" %.3f", total[i]);
    return 0;
}