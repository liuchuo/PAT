#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct peo{
    int id, level;
};
int main(){
    int n, temp, maxlevel = -1;
    queue<peo> q;
    vector<peo> ans;
    cin >> n;
    vector<vector<int>> v(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        if(temp == -1) temp = 0;
        v[temp].push_back(i);
    }
    q.push({0,0});
    while(!q.empty()) {
        peo p  = q.front();
        int id = p.id, level = p.level;
        if(p.level > maxlevel) maxlevel = p.level;
        ans.push_back(p);
        q.pop();
        for(int i = 0; i < v[id].size(); i++)
            q.push({v[id][i], level + 1});
    }
    cout << maxlevel << endl;
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i].level == maxlevel) {
            cout << ans[i].id;
            if(i != ans.size() - 1) cout << " ";
        }
    }
    return 0;
}
