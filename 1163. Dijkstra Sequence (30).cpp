#include <iostream>
#include <vector>
using namespace std;
const int inf = 0x2fffffff;
int e[1010][1010], dis[1010];
bool vis[1010];
int main() {
	fill(e[0], e[0] + 1010 * 1010, inf);
	int nv, ne, k, a, b, w;
	cin >> nv >> ne;
	for (int i = 0; i < ne; i++) {
		scanf("%d%d%d", &a, &b, &w);
		e[a][b] = e[b][a] = w;
	}
	cin >> k;
	vector<int> seq(nv);
	while (k--) {
		fill(dis, dis+1010, inf);
		fill(vis, vis+1010, false);
		for (int i = 0; i < nv; i++) scanf("%d", &seq[i]);
		dis[seq[0]] = 0;
		for (int i = 1; i <= nv; i++) {
			int minn = inf, u = -1;
			for (int j = 1; j <= nv; j++)
				if (!vis[j] && dis[j] < minn) {
					minn = dis[j];
					u = j;
				}
			if (u == -1) break;
			vis[u] = true;
			for (int v = 1; v <= nv; v++)
				if (!vis[v] && e[u][v] != inf && dis[v] > dis[u] + e[u][v])
					dis[v] = dis[u] + e[u][v];
		}
		int flag = 0;
		for (int i = 1; i < nv; i++)
			if (dis[seq[i]] < dis[seq[i-1]]) {
				flag = 1;
				break;
			}
		if (flag == 1) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
