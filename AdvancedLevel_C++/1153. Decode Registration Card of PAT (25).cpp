#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct stu {
    string id;
    int sco;
};
struct site {
    string siteId;
    int cnt;
};
bool cmp1(const stu &a, const stu &b) {
    return a.sco == b.sco ? a.id < b.id : a.sco > b.sco;
}
bool cmp2(const site &a, const site &b) {
    return a.cnt == b.cnt ? a.siteId < b.siteId : a.cnt > b.cnt;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<stu> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].id >> v[i].sco;
    for (int i = 1; i <= k; i++) {
        int num;
        scanf("%d", &num);
        if (num == 1) {
            string level;
            cin >> level;
            printf("Case %d: %d %s\n", i, num, level.c_str());
            vector<stu> ans;
            for (int i = 0; i < n; i++) {
                if (v[i].id[0] == level[0])
                    ans.push_back(v[i]);
            }
            sort(ans.begin(), ans.end(),cmp1);
            for (int i = 0; i < ans.size(); i++)
                printf("%s %d\n", ans[i].id.c_str(), ans[i].sco);
            if (ans.size() == 0) printf("NA\n");
        } else if (num == 2) {
            int cnt = 0, sum = 0;
            int siteId;
            cin >> siteId;
            printf("Case %d: %d %d\n", i, num, siteId);
            vector<stu> ans;
            for (int i = 0; i < n; i++) {
                if (v[i].id.substr(1, 3) == to_string(siteId)) {
                    cnt++;
                    sum += v[i].sco;
                }
            }
            if (cnt != 0) printf("%d %d\n", cnt, sum);
            else printf("NA\n");
        } else if (num == 3) {
            string date;
            cin >> date;
            printf("Case %d: %d %s\n", i, num, date.c_str());
            vector<site> ans;
            unordered_map<string, int> m;
            for (int i = 0; i < n; i++) {
                if (v[i].id.substr(4, 6) == date) {
                    string tt = v[i].id.substr(1, 3);
                    m[tt]++;
                }
            }
            for (auto it : m)
                ans.push_back({it.first, it.second});
            sort(ans.begin(), ans.end(),cmp2);
            for (int i = 0; i < ans.size(); i++)
                printf("%s %d\n", ans[i].siteId.c_str(), ans[i].cnt);
            if (ans.size() == 0) printf("NA\n");
        }
    }
    return 0;
}