1080 Graduate Admission（30 分）
It is said that in 2011, there are about 100 graduate schools ready to proceed over 40,000 applications in Zhejiang Province. It would help a lot if you could write a program to automate the admission procedure.

Each applicant will have to provide two grades: the national entrance exam grade G
​E
​​ , and the interview grade G
​I
​​ . The final grade of an applicant is (G
​E
​​ +G
​I
​​ )/2. The admission rules are:

The applicants are ranked according to their final grades, and will be admitted one by one from the top of the rank list.

If there is a tied final grade, the applicants will be ranked according to their national entrance exam grade G
​E
​​ . If still tied, their ranks must be the same.

Each applicant may have K choices and the admission will be done according to his/her choices: if according to the rank list, it is one’s turn to be admitted; and if the quota of one's most preferred shcool is not exceeded, then one will be admitted to this school, or one's other choices will be considered one by one in order. If one gets rejected by all of preferred schools, then this unfortunate applicant will be rejected.

If there is a tied rank, and if the corresponding applicants are applying to the same school, then that school must admit all the applicants with the same rank, even if its quota will be exceeded.

Input Specification:
Each input file contains one test case.

Each case starts with a line containing three positive integers: N (≤40,000), the total number of applicants; M (≤100), the total number of graduate schools; and K (≤5), the number of choices an applicant may have.

In the next line, separated by a space, there are M positive integers. The i-th integer is the quota of the i-th graduate school respectively.

Then N lines follow, each contains 2+K integers separated by a space. The first 2 integers are the applicant’s G
​E
​​  and G
​I
​​ , respectively. The next K integers represent the preferred schools. For the sake of simplicity, we assume that the schools are numbered from 0 to M−1, and the applicants are numbered from 0 to N−1.

Output Specification:
For each test case you should output the admission results for all the graduate schools. The results of each school must occupy a line, which contains the applicants’ numbers that school admits. The numbers must be in increasing order and be separated by a space. There must be no extra space at the end of each line. If no applicant is admitted by a school, you must output an empty line correspondingly.

Sample Input:
11 6 3
2 1 2 2 2 3
100 100 0 1 2
60 60 2 3 5
100 90 0 3 4
90 100 1 2 0
90 90 5 1 3
80 90 1 0 2
80 80 0 1 2
80 80 0 1 2
80 70 1 3 2
70 80 1 2 3
100 100 0 2 4
Sample Output:
0 10
3
5 6 7
2 8

1 4

分析：
1.stu容器里放学生{id, ge, gi, fin, choice(容器里放学生报考学校的id)}, quota数组放招生计划的数量，cnt数组存放当前学校已经招收的学生数，sch数组里放的容器，容器里是学校已经招的学生的id～
2.对学生按照分数排序，依次学生遍历，分数最高的学生先挑学校～
3.对于每个学生录取到哪里：依次遍历学生的报考志愿，如果（没招满 || 他与已经招的学生的最后一名成绩并列）就把他招进去，该学生录取结果即可确定，更新该学校已经招生的人数，并把次学生加入该学校录取容器中～
4.输出学校录取情况时学生id顺序是乱的，要先从小到大排序，然后输出。每个学校占一行～
5.排序函数要用 & 引用传参，不然会超时～
6.因为分数 fin = ge + gi 不会超出int, fin / 2 和fin排名效果一样， 不除2不会影响结果，而且还可以巧妙躲避除2后double不能精确表示的问题～

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct peo{
    int id, ge, gi, fin;
    vector<int> choice;
};
bool cmp(peo& a, peo& b) {
    if (a.fin != b.fin) return a.fin > b.fin;
    return a.ge > b.ge;
}
bool cmp2(peo& a, peo& b) {
  return a.id < b.id;
}
int main(){
    int n, m, k, quota[110], cnt[110] = {0};
    scanf("%d%d%d", &n, &m, &k);
    vector<peo> stu(n), sch[110];
    for(int i = 0; i < m; i++)
        scanf("%d",&quota[i]);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &stu[i].ge, &stu[i].gi);
        stu[i].id = i;
        stu[i].fin = stu[i].ge + stu[i].gi;
        stu[i].choice.resize(k);
        for(int j = 0; j < k; j++)
            scanf("%d", &stu[i].choice[j]);
    }
    sort(stu.begin(), stu.end(), cmp);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            int schid = stu[i].choice[j];
            int lastindex = cnt[schid] - 1;
            if(cnt[schid] < quota[schid] || (stu[i].fin == sch[schid][lastindex].fin) && stu[i].ge == sch[schid][lastindex].ge) {
                sch[schid].push_back(stu[i]);
                cnt[schid]++;
                break;
            }
        }
    }
    for(int i = 0; i < m; i++) {
        sort(sch[i].begin(), sch[i].end(), cmp2);
        for(int j = 0; j < cnt[i]; j++) {
            if(j != 0) printf(" ");
            printf("%d", sch[i][j].id);
        }
        printf("\n");
    }
    return 0;
}
