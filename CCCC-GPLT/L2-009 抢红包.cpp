#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int id, total, getnum;
};
bool cmp1(node a, node b) {
    if(a.total != b.total)
        return a.total > b.total;
    else if(a.getnum != b.getnum)
        return a.getnum > b.getnum;
    else
        return a.id < b.id;
}
int main() {
    int n, k, a, b;
    scanf("%d", &n);
    vector<node> v(n + 1);
    for(int i = 1; i <= n; i++) {
        v[i].id = i;
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d %d", &a, &b);
            v[a].total += b;
            v[a].getnum++;
            v[i].total -= b;
        }
    }
    sort(v.begin()+1, v.end(), cmp1);
    for(int i = 1; i <= n; i++) {
        double temp = (double)(v[i].total * 1.0 / 100);
        printf("%d %.2f\n", v[i].id, temp);
    }
    return 0;
}
