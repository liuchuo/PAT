//1038. 统计同成绩学生(20)

时间限制
250 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
本题要求读入N名学生的成绩，将获得某一给定分数的学生人数输出。

输入格式：

输入在第1行给出不超过 10^5 的正整数N，即学生总人数。随后1行给出N名
学生的百分制整数成绩，中间以空格分隔。最后1行给出要查询的分数个数K
（不超过N的正整数），随后是K个分数，中间以空格分隔。

输出格式：

在一行中按查询顺序给出得分等于指定分数的学生人数，中间以空格分隔，
但行末不得有多余空格。

输入样例：
10
60 75 90 55 75 99 82 90 75 50
3 75 90 88
输出样例：
3 2 0

#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m, temp;
    cin >> n;
    vector<int> b(101);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        b[a]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        if (i != 0) cout << " ";
        cout << b[temp];
    }
    return 0;
}
