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
#include <vector>
#include <algorithm>
using namespace std;
int func(int N) {
    int i = sqrt((double)N);
    while(i >= 1) {
        if(N % i == 0)
            return i;
        i--;
    }
    return 1;
}

int cmp(int a, int b) {return a > b;}

int main() {
    int N, m, n, t = 0;
    scanf("%d", &N);
    n = func(N);
    m = N / n;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    sort(a.begin(), a.end(), cmp);
    vector<vector<int> > b(m, vector<int>(n));
    int level = m / 2 + m % 2;
    for (int i = 0; i < level; i++) {
        for (int j = i; j <= n - 1 - i && t <= N - 1; j++) {
            b[i][j] = a[t++];
        }
        for (int j = i + 1; j <= m - 2 - i && t <= N - 1; j++) {
            b[j][n - 1 - i] = a[t++];
        }
        for (int j = n - i - 1; j >= i && t <= N - 1; j--) {
            b[m - 1 - i][j] = a[t++];
        }
        for (int j = m - 2 - i; j >= i + 1 && t <= N - 1; j--) {
            b[j][i] = a[t++];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0 ; j < n; j++) {
            printf("%d", b[i][j]);
            if (j != n - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}