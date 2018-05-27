1085. PAT单位排行 (25)
每次 PAT 考试结束后，考试中心都会发布一个考生单位排行榜。本题就请你实现这个功能。
输入格式：
输入第一行给出一个正整数N（<=105），即考生人数。随后N行，每行按下列格式给出一个考生的信息：
准考证号 得分 学校
其中“准考证号”是由6个字符组成的字符串，其首字母表示考试的级别：“B”代表乙级，“A”代表甲级，“T”代表顶级；“得分”是 [0,100] 区间内的整数；“学校”是由不超过6个英文字母组成的单位码（大小写无关）。注意：题目保证每个考生的准考证号是不同的。
输出格式：
首先在一行中输出单位个数。随后按以下格式非降序输出单位的排行榜：
排名 学校 加权总分 考生人数
其中“排名”是该单位的排名（从1开始）；“学校”是全部按小写字母输出的单位码；“加权总分”定义为“乙级总分/1.5 + 甲级总分 + 顶级总分*1.5”的整数部分；“考生人数”是该属于单位的考生的总人数。
学校首先按加权总分排行。如有并列，则应对应相同的排名，并按考生人数升序输出。如果仍然并列，则按单位码的字典序输出。
输入样例：
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu
输出样例：
5
1 cmu 192 2
1 au 192 3
3 pku 100 1
4 hypu 81 2
4 lanx 81 2

分析：两个map，一个cnt用来存储某学校名称对应的参赛人数，另一个sum计算某学校名称对应的总加权成绩。每次学校名称string school都要转化为全小写，将map中所有学校都保存在vector ans中，类型为node，node中包括学校姓名、加权总分、参赛人数。对ans数组排序，根据题目要求写好cmp函数，最后按要求输出。对于排名的处理：设立pres表示前一个学校的加权总分，如果pres和当前学校的加权总分不同，说明rank等于数组下标+1，否则rank不变～
注意：总加权分数取整数部分是要对最后的总和取整数部分，不能每次都直接用int存储，不然会有一个3分测试点不通过～

#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <unordered_map>
using namespace std;
struct node {
    string school;
    int tws, ns;
};
bool cmp(node a, node b) {
    if (a.tws != b.tws)
        return a.tws > b.tws;
    else if (a.ns != b.ns)
        return a.ns < b.ns;
    else
        return a.school < b.school;
}
int main() {
    int n;
    scanf("%d", &n);
    unordered_map<string, int> cnt;
    unordered_map<string, double> sum;
    for (int i = 0; i < n; i++) {
        string id, school;
        cin >> id;
        double score;
        scanf("%lf", &score);
        cin >> school;
        for (int j = 0; j < school.length(); j++)
            school[j] = tolower(school[j]);
        if (id[0] == 'B')
            score = score / 1.5;
        else if (id[0] == 'T')
            score = score * 1.5;
        sum[school] += score;
        cnt[school]++;
    }
    vector<node> ans;
    for (auto it = cnt.begin(); it != cnt.end(); it++)
        ans.push_back(node{it->first, (int)sum[it->first], cnt[it->first]});
    sort(ans.begin(), ans.end(), cmp);
    int rank = 0, pres = -1;
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) {
        if (pres != ans[i].tws) rank = i + 1;
        pres = ans[i].tws;
        printf("%d ", rank);
        cout << ans[i].school;
        printf(" %d %d\n", ans[i].tws, ans[i].ns);
    }
    return 0;
}