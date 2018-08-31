#include <iostream>
#include <vector>
using namespace std;
struct node {
    int id, data, next;
};
int main() {
    int begin, n, k, s, d, e;
    scanf("%d%d%d", &begin, &n, &k);
    node a[100010];
    vector<node> v, ans;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &s, &d, &e);
        a[s] = {s, d, e};
    }
    for (; begin != -1; begin = a[begin].next)
        v.push_back(a[begin]);
    for (int i = 0; i < v.size(); i++)
        if (v[i].data < 0) ans.push_back(v[i]);
    for (int i = 0; i < v.size(); i++)
        if (v[i].data >= 0 && v[i].data <= k) ans.push_back(v[i]);
    for (int i = 0; i < v.size(); i++)
        if (v[i].data > k) ans.push_back(v[i]);
    for (int i = 0; i < ans.size() - 1; i++)
        printf("%05d %d %05d\n", ans[i].id, ans[i].data, ans[i + 1].id);
    printf("%05d %d -1\n", ans[ans.size() - 1].id, ans[ans.size() - 1].data);
    return 0;
}