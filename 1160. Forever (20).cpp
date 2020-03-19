#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int getSum(int n) {
	int sum = 0;
	do {
		sum += n % 10;
		n /= 10;
	} while (n != 0);
	return sum;
}
bool isprime(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}
int gcd(int a, int b) {
	return !b ? a: gcd(b, a % b);
}
bool cmp(pair<int, int> &a, pair<int, int> &b) {
	return a.first != b.first ? a.first < b.first : a.second < b.second;
}
int main() {
	int N, k, m;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &k, &m);
		vector<pair<int, int>> ans;
		int begin = pow(10, k-1), end = pow(10, k);
		for (int j = begin + 99; j < end; j += 100) {
			if (getSum(j) != m) continue;
			int n = getSum(j + 1);
			int d = gcd(m, n);
			if (d > 2 && isprime(d)) ans.push_back({n, j});
		}
		sort(ans.begin(), ans.end(), cmp);
		printf("Case %d\n", i);
		if (ans.empty()) printf("No Solution\n");
		for (auto it : ans) printf("%d %d\n", it.first, it.second);
	}
	return 0;
}
