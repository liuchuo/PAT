L2-026. 小字辈
本题给定一个庞大家族的家谱，要请你给出最小一辈的名单。
输入格式：
输入在第一行给出家族人口总数 N（不超过 100 000 的正整数） —— 简单起见，我们把家族成员从 1 到 N 编号。随后第二行给出 N 个编号，其中第 i 个编号对应第 i 位成员的父/母。家谱中辈分最高的老祖宗对应的父/母编号为 -1。一行中的数字间以空格分隔。
输出格式：
首先输出最小的辈分（老祖宗的辈分为 1，以下逐级递增）。然后在第二行按递增顺序输出辈分最小的成员的编号。编号间以一个空格分隔，行首尾不得有多余空格。
输入样例：
9
2 6 5 5 -1 5 6 4 7
输出样例：
4
1 9

分析：v[i]中保存i的所有孩子结点，root为家谱中最高辈分的老祖宗，从root开始向下深度优先搜索，求得maxlevel和最后一层的结点编号，保存在set里，最后输出maxlevel和set中所有数字～

#include <iostream>
#include <vector>
#include <set>
using namespace std;
int maxlevel = 1;
vector<vector<int>> v;
set<int> s;
void dfs(int node, int level) {
    if (level > maxlevel) {
        maxlevel = level;
        s.clear();
        s.insert(node);
    } else if (level == maxlevel) {
        s.insert(node);
    }
    for (int i = 0; i < v[node].size(); i++)
        dfs(v[node][i], level+1);
}
int main() {
    int n, num, root = 0;
    cin >> n;
    v.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> num;
        if (num == -1) {
            root = i;
            continue;
        }
        v[num].push_back(i);
    }
    dfs(root, 1);
    cout << maxlevel << endl;
    for (auto it = s.begin(); it != s.end(); it++) {
        if (it != s.begin()) cout << " ";
        cout << *it;
    }
    return 0;
}
