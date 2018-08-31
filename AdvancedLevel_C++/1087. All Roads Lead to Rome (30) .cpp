#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
const int inf = 999999999;
int e[205][205], weight[205], dis[205];
bool visit[205];
vector<int> pre[205], temppath, path;
map<string, int> m;
map<int, string> m2;
int maxvalue = 0, mindepth, cntpath = 0;
double maxavg;
void dfs(int v) {
    temppath.push_back(v);
    if(v == 1) {
        int value = 0;
        for(int i = 0; i < temppath.size(); i++) {
            value += weight[temppath[i]];
        }
        double tempavg = 1.0 * value / (temppath.size() - 1);
        if(value > maxvalue) {
            maxvalue = value;
            maxavg = tempavg;
            path = temppath;
        } else if(value == maxvalue && tempavg > maxavg) {
            maxavg = tempavg;
            path = temppath;
        }
        temppath.pop_back();
        cntpath++;
        return ;
    }
    for(int i = 0; i < pre[v].size(); i++) {
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}
int main() {
    fill(e[0], e[0] + 205 * 205, inf);
    fill(dis, dis + 205, inf);
    scanf("%d %d", &n, &k);
    string s;
    cin >> s;
    m[s] = 1;
    m2[1] = s;
    for(int i = 1; i < n; i++) {
        cin >> s >> weight[i+1];
        m[s] = i+1;
        m2[i+1] = s;
    }
    string sa, sb;
    int temp;
    for(int i = 0; i < k; i++) {
        cin >> sa >> sb >> temp;
        e[m[sa]][m[sb]] = temp;
        e[m[sb]][m[sa]] = temp;
    }
    dis[1] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 1; j <= n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 1; v <= n; v++) {
            if(visit[v] == false && e[u][v] != inf) {
                if(dis[u] + e[u][v] < dis[v]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(dis[v] == dis[u] + e[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
    int rom = m["ROM"];
    dfs(rom);
    printf("%d %d %d %d\n", cntpath, dis[rom], maxvalue, (int)maxavg);
    for(int i = path.size() - 1; i >= 1; i--) {
        cout << m2[path[i]] << "->";
    }
    cout << "ROM";
    return 0;
}