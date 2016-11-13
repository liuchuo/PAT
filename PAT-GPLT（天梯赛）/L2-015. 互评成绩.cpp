L2-015. 互评成绩
学生互评作业的简单规则是这样定的：每个人的作业会被k个同学评审，得到k个成绩。系统需要去掉一个最高分和一个最低分，将剩下的分数取平均，就得到这个学生的最后成绩。本题就要求你编写这个互评系统的算分模块。
输入格式：
输入第一行给出3个正整数N（3< N <= 104，学生总数）、k（3<= k <= 10，每份作业的评审数）、M（<= 20，需要输出的学生数）。随后N行，每行给出一份作业得到的k个评审成绩（在区间[0, 100]内），其间以空格分隔。
输出格式：
按非递减顺序输出最后得分最高的M个成绩，保留小数点后3位。分数间有1个空格，行首尾不得有多余空格。
输入样例：
6 5 3
88 90 85 99 60
67 60 80 76 70
90 93 96 99 99
78 65 77 70 72
88 88 88 88 88
55 55 55 55 55
输出样例：
87.667 88.000 96.000

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int cmp1(double a, double b) {return a > b;}
int main() {
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    vector<double> total;
    for(int i = 0; i < n; i++) {
        vector<double> v(k);
        double maxn = -1, minn = 101, average = 0.0;
        for(int j = 0; j < k; j++) {
            scanf("%lf", v[j]);
            maxn = max(maxn, v[j]);
            minn = min(minn, v[j]);
            average += v[j];
        }
        average = average / (k - 2);
        total.push_back(average);
    }
    sort(total.begin(), total.end(), cmp1);
    if(m != 0)
        printf("%.3f", total[m - 1]);
    for(int i = m - 2; i >= 0; i--)
        printf(" %.3f", total[i]);
    return 0;
}