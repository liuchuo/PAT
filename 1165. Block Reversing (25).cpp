#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	int addr, data, next, flag, order;
};
int num = 0;
vector<node> v(100000), v2;
bool cmp(node &a, node &b) {
	return a.flag != b.flag ? a.flag > b.flag : a.order < b.order;
}
int main() {
	int fir, n, k, addr, data, next;
	cin >> fir >> n >> k;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &addr, &data, &next);
		v[addr] = node{addr, data, next};
	}
	vector<int> head;
	int p = fir;
	while (p != -1) {
		v[p].flag = 1;
		v[p].order = num++;
		if (v[p].order % k == 0) head.push_back(v[p].order);
		p = v[p].next;
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = head.size()-1; i >= 0; i--)
		for (int j = head[i]; j < num && j < head[i] + k; j++)
			v2.push_back(node{v[j].addr, v[j].data});
	for (int i = 0; i < num; i++)
		if (i != num - 1) printf("%05d %d %05d\n", v2[i].addr, v2[i].data, v2[i+1].addr);
		else printf("%05d %d -1", v2[i].addr, v2[i].data);
	return 0;
}
