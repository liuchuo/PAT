#include <iostream>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
struct Bike {
    int need, collect;
    Bike adjust(int adjust, int perfect)
    {
        int c = collect + adjust - perfect;
        if (c < 0) {
            return { need - c, 0 };
        }
        return { need, c };
    };
};
int main()
{
    int maxCap, station, target, edge, src = 0;
    cin >> maxCap >> station >> target >> edge;
    int node = station + 1, perfectCap = maxCap / 2;
    /* 建立Ci~n */
    vector<int> caps(node, 0);
    for (int i = 1; i < node; i++) {
        cin >> caps[i];
    }
    /* 构造图 */
    vector<vector<int>> figure(node, vector<int>(node, INF));
    for (int a, b, w, i = 0; i < edge; i++) {
        cin >> a >> b >> w;
        figure[a][b] = figure[b][a] = w;
    }
    /* dijkstr */
    vector<bool> visited(node, false);
    vector<int> distance(node, INF);
    distance[src] = 0;
    vector<int> path(node, -1);
    vector<Bike> bike(node);
    bike[src] = { 0, 0 };
    while (1) {
        int toVis = -1, closest = INF;
        for (int i = 0; i < node; i++) {
            if (!visited[i] && closest > distance[i]) {
                closest = distance[i];
                toVis = i;
            }
        }
        if (toVis == -1 || toVis == target) { /* 结束以及提前剪枝 */
            break;
        }
        visited[toVis] = true;
        for (int i = 0; i < node; i++) {
            if (!visited[i] && distance[i] > figure[toVis][i] + closest) {
                distance[i] = figure[toVis][i] + closest;
                path[i] = toVis;
                bike[i] = bike[toVis].adjust(caps[i], perfectCap);
            } else if (!visited[i] && distance[i] == figure[toVis][i] + closest) { /* 两条相同长度的路径会合在 i */
                Bike b = bike[toVis].adjust(caps[i], perfectCap);
                if (i == target) { /* i 是终点时 比较两条路来此点调整后的数字 */
                    if (b.need < bike[i].need || (b.need == bike[i].need && b.collect < bike[i].collect)) {
                        bike[i] = b;
                        path[i] = toVis;
                    }
                } else if (i != target) { /* i 不是终点时，比较两条路来此点 再到终点调整后的数字 */
                    Bike l = b.adjust(caps[target], perfectCap);
                    Bike r = bike[i].adjust(caps[target], perfectCap);
                    if (l.need < r.need || (l.need == r.need && l.collect < r.collect)) {
                        bike[i] = b;
                        path[i] = toVis;
                    }
                }
            }
        }
    }
    vector<int> r; /* 整理路径 */
    for (int i = path[target]; i != -1; i = path[i]) {
        r.push_back(i);
    }
    /* 输出 */
    cout << bike[target].need << " ";
    for (auto it = r.rbegin(); it != r.rend(); it++) {
        cout << *it << "->";
    }
    cout << target << " " << bike[target].collect;
    return 0;
}
