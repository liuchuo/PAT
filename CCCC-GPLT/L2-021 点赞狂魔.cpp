#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
struct stu{
    string name;
    int sum, cnt;
};
bool cmp(stu a, stu b){
    if(a.cnt != b.cnt)  return a.cnt > b.cnt;
    return 1.0 * a.sum / a.cnt < 1.0 * b.sum / b.cnt;
}
bool a[10000010];
int main() {
    int n;
    cin >> n;
    vector<stu> ans(n);
    for(int i = 0; i < n; i++) {
        memset(a, false, sizeof(a));
        int m, t, cnt = 0;
        string name;
        cin >> name >> m;
        for(int j = 0; j < m; j++) {
            cin >> t;
            if(a[t] == false) {
                a[t] = true;
                cnt++;
            }
        }
        ans[i] = {name, m, cnt};
    }
    int nn = min(n, 3);
    partial_sort(ans.begin(),ans.begin() + nn, ans.end(), cmp);
    for(int i = 0; i < nn; i++) {
        if(i != 0) cout << " ";
             cout << ans[i].name;
    }
    for(int i = 0; i < 3 - n; i++)
        cout << " " <<  "-";
    return 0;
}
