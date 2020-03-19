#include <iostream>
using namespace std;
struct node {
	string s;
	int l, r;
} a[25];
string dfs(int root) {
	if (root == -1) return "";
	int cnt = (a[root].l == -1) + (a[root].r == -1);
	if (cnt == 1) return "(" + a[root].s + dfs(a[root].l) + dfs(a[root].r) + ")";
	else return "(" + dfs(a[root].l) + dfs(a[root].r) + a[root].s + ")";
}
int main() {
	int h[25] = {0}, n, root = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].s >> a[i].l >> a[i].r;
		if (a[i].l != -1) h[a[i].l] = 1;
		if (a[i].r != -1) h[a[i].r] = 1;
	}
	while (root <= n && h[root] == 1) root++;
	string ans = dfs(root);
	printf("%s", ans.c_str());
	return 0;
}
