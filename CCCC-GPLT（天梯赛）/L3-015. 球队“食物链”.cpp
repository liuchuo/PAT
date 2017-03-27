L3-015. 球队“食物链”
某国的足球联赛中有N支参赛球队，编号从1至N。联赛采用主客场双循环赛制，参赛球队两两之间在双方主场各赛一场。
联赛战罢，结果已经尘埃落定。此时，联赛主席突发奇想，希望从中找出一条包含所有球队的“食物链”，来说明联赛的精彩程度。“食物链”为一个1至N的排列{ T1 T2 ... TN }，满足：球队T1战胜过球队T2，球队T2战胜过球队T3，……，球队T(N-1)战胜过球队TN，球队TN战胜过球队T1。
现在主席请你从联赛结果中找出“食物链”。若存在多条“食物链”，请找出字典序最小的。
注：排列{ a1 a2 ...aN }在字典序上小于排列{ b1 b2 ... bN }，当且仅当存在整数K（1 <= K <= N），满足：aK < bK且对于任意小于K的正整数i，ai=bi。

输入格式：
输入第一行给出一个整数N（2 <= N <= 20），为参赛球队数。随后N行，每行N个字符，给出了NxN的联赛结果表，其中第i行第j列的字符为球队i在主场对阵球队j的比赛结果：“W”表示球队i战胜球队j，“L”表示球队i负于球队j，“D”表示两队打平，“-”表示无效（当i=j时）。输入中无多余空格。

输出格式：
按题目要求找到“食物链”T1 T2 ... TN，将这N个数依次输出在一行上，数字间以1个空格分隔，行的首尾不得有多余空格。若不存在“食物链”，输出“No Solution”。

输入样例1：
5
-LWDW
W-LDW
WW-LW
DWW-W
DDLW-
输出样例1：
1 3 5 4 2
输入样例2：
5
-WDDW
D-DWL
DD-DW
DDW-D
DDDD-
输出样例2：
No Solution

分析：
0.既然是字典序最小的，而且必须包含所有的球队编号，那如果存在的话1肯定是结果数组的第一位～
1.接收数据：用v[21][21]存储比赛结果，如果是W就将v[i][j]置为1，表示i战胜过j，如果是L就将v[j][i]置为1，表示j战胜过i，其余的不用管～
2.dfs(int index, int num)：index从1到n用来表示当前即将写入的结果数组result的下标，num表示当前的球队的编号，从1开始。
3.flag用来标记是否已经找到一个这样的结果数组，如果已经找到了（flag == 1）就return; 否则将当前下标index的result写入num值。
当index等于n的时候，并且v[num][1]等于true，表示已经写到了n个球员，而且这个球队num也曾经战胜过球队1～如果仅仅是index == n，就直接return不用继续向下找了～
4.cut标记剪枝，首先cut等于false，当所有没有访问过的结点中没有一个结点的v[i][1] == true，即没有一个球队战胜过1，就直接return，因为这条路径肯定找不到回路啦～
5.然后将num球队编号标记为已经访问过【visit[num] = true;】遍历num所有打败过的球队，并将index + 1，直到dfs结束的最后将visit标记回false
6.最后根据flag的值输出结果，如果flag为0说明没有满足题意的球队，就输出No Solution，如果flag = 1就输出result数组中保存的结果～

#include <cstdio>
using namespace std;
int n, flag = 0;
int result[21];
bool v[21][21], visit[21];
void dfs(int index, int num) {
    if (flag == 1) return;
    result[index] = num;
    if (index == n && v[num][1] == true) {
        flag = 1;
        return;
    }
    if (index == n) return;
    bool cut = false;
    for (int i = 1; i <= n; i++) {
        if (visit[i] == false && v[i][1] == true)
            cut = true;
    }
    if (cut == false) return;
    visit[num] = true;
    for (int i = 1; i <= n; i++) {
        if (visit[i] == false && v[num][i] == true)
            dfs(index + 1, i);
    }
    visit[num] = false;
}
int main() {
    scanf("%d", &n);
    char s[21];
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= n; j++) {
            if (s[j] == 'W') v[i][j] = true;
            if (s[j] == 'L') v[j][i] = true;
        }
    }
    dfs(1, 1);
    if (flag == 1) {
        for (int i = 1; i <= n; i++)
            printf("%s%d", i == 1 ? "" : " ", result[i]);
    } else {
        printf("No Solution");
    }
    return 0;
}