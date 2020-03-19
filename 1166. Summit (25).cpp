#include <iostream>
#include <set>
#include <vector>
using namespace std;
int e[210][210];
int main() {
	int n, m, k;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		e[a][b] = e[b][a] = 1;
	}
	cin >> k;
	for (int i = 1; i <= k; i++) {
		int l, fir, tmp;
		scanf("%d%d", &l, &fir);
		set<int> st;
		vector<bool> vis(n+1, false);
		st.insert(fir);
		vis[fir] = true;
		bool help = false;
		for (int j = 0; j < l-1; j++) {
			scanf("%d", &tmp);
			vis[tmp] = true;
			int flag = 1;
			for (auto it = st.begin(); it != st.end(); it++)
				if (e[*it][tmp] == 0) {
					flag = 0;
					break;
				}
			if (flag == 1) st.insert(tmp);
			else help = true;
		}
		if (help == true) {
			printf("Area %d needs help.\n", i);
			continue;
		}
		int invite = -1;
		for (int j = 1; j <= n; j++)
			if (!vis[j]) {
				int flag = 1;
				for (auto it : st)
					if (e[it][j] == 0) {
						flag=0;
						break;
					}
				if (flag == 1) {
					invite = j;
					break;
				}
			}
		if (invite == -1) printf("Area %d is OK.\n", i);
		else printf("Area %d may invite more people, such as %d.\n", i, invite);
	}
	return 0;
}
