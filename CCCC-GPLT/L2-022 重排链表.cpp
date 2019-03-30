#include <iostream>
#include <vector>
using namespace std;
struct node{
    int id, data, next;
};
int main() {
    int begin, n;
    cin >> begin >> n;
    node a[100010];
    vector<node> v, ans;
    for(int i = 0; i < n; i++) {
        int tbegin, tdata, tnext;
        cin >> tbegin >> tdata >> tnext;
        a[tbegin] = {tbegin, tdata, tnext};
    }
    while(begin != -1) {
        v.push_back(a[begin]);
        begin = a[begin].next;
    }
    int l = 0, r = v.size() - 1;
    while(1) {
        ans.push_back(v[r]);
        r--;
        if((r + 1) - (l - 1) == 1) break;
        ans.push_back(v[l]);
        l++;
        if((r + 1) - (l - 1) == 1) break;
    }
    for(int i = 0; i < ans.size(); i++) {
        if(i != ans.size() - 1)
            printf("%05d %d %05d\n", ans[i].id, ans[i].data, ans[i+1].id);
        else
            printf("%05d %d -1\n", ans[i].id, ans[i].data);
    }
    return 0;
}

