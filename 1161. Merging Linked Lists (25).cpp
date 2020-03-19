#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	int addr, data, next, flag, order;
};
int num1 = 0, num2 = 0;
vector<node> v(100000), ans;
bool cmp(node &a, node &b) {
	return a.flag != b.flag ? a.flag > b.flag : a.order < b.order;
}
bool cmp2(node &a, node &b) {
	return a.order > b.order;
}
int main() {
	int fir1, fir2, n, addr, data, next;
	cin >> fir1 >> fir2 >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &addr, &data, &next);
		v[addr] = node{addr, data, next};
	}
	for (int p = fir1; p != -1; p = v[p].next) {
		v[p].flag = 1;
		v[p].order = num1++;
	}
	for (int p = fir2; p != -1; p = v[p].next) {
		v[p].flag = 2;
		v[p].order = num2++;
	}
	if (num1 < num2) {
		swap(num1, num2);
		swap(fir1, fir2);
	}
	for (int p = fir1; p != -1; p = v[p].next) v[p].flag = 1;
	for (int p = fir2; p != -1; p = v[p].next) v[p].flag = 2;
	sort(v.begin(), v.end(), cmp);
	sort(v.begin(), v.begin()+num2, cmp2);
	int cnt1 = num2, cnt2 = 0;
	while (cnt1 < num1+num2 || cnt2 < num2) {
		if (cnt1 < num1+num2) {
			for (int j = cnt1; j < cnt1+2 && cnt1 < num1+num2; j++)
				ans.push_back(node{v[j].addr, v[j].data});
			cnt1 += 2;
		}
		if (cnt2 < num2) {
			ans.push_back(node{v[cnt2].addr, v[cnt2].data});
			cnt2 += 1;
		}
	}
	for (int i = 0; i < num1+num2; i++)
		if (i != num1+num2-1) printf("%05d %d %05d\n", ans[i].addr, ans[i].data, ans[i+1].addr);
		else printf("%05d %d -1", ans[i].addr, ans[i].data);
	return 0;
}
