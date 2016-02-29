1050. 螺旋矩阵(25)
本题要求将给定的N个正整数按非递增的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，是指从左上角第1个格子开始，按顺时针螺旋方向填充。要求矩阵的规模为m行n列，满足条件：m*n等于N；m>=n；且m-n取所有可能值中的最小值。
输入格式：
输入在第1行中给出一个正整数N，第2行给出N个待填充的正整数。所有数字不超过104，相邻数字以空格分隔。
输出格式：
输出螺旋矩阵。每行n个数字，共m行。相邻数字以1个空格分隔，行末不得有多余空格。
输入样例：
12
37 76 20 98 76 42 53 95 60 81 58 93
输出样例：
98 95 93
42 37 81
53 20 76
58 60 76

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int func(int N) {
	for (int i = sqrt((double)N); i >= 1; i--) {
		if (N % i == 0) {
			return i;
		}
	}
	return 1;
}

int cmp(int a, int b) {
	return a > b;
}

int main() {
	int N, m, n;
	cin >> N;
	n = func(N);
	m = N / n;
	int *a = new int [N];
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	sort(a, a + n, cmp);
	int **b = new int *[m];
	for (int i = 0; i < m; i++) 
		b[i] = new int [n];
	int level = m / 2;
	if (m % 2)
		level++;
	int t = 0;
	for (int i = 0; i < level; i++) {
		
		for (int j = i; j <= n - 1 - i; j++) {
			if (t <= N) {
				b[i][j] = t++;
			} else {
				break;
			}
		}

		for (int j = i + 1; j <= m - 2 - i; j++) {
			if (t <= N) {
				b[j][n - 1 - i] = t++;
			} else {
				break;
			}
		}

		for (int j = n - i - 1; j >= i; j--) {
			if (t <= N) {
				b[m - 1 - i][j] = t++;
			} else {
				break;
			}
		}

		for (int j = m - 2 - i; j >= i + 1; j--) {
			if (t <= N) {
				b[j][i] = t++;
			} else {
				break;
			}
		}

		if (t > N) 
			break;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0 ; j < n; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}

	delete [] a;
	for (int i = 0; i < m; i++)
		delete [] b[i];
	delete [] b;
	return 0;
}