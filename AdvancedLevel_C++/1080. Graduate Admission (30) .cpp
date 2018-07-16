1080. Graduate Admission (30)
It is said that in 2013, there were about 100 graduate schools ready to proceed over 40,000 applications in Zhejiang Province. It would help a lot if you could write a program to automate the admission procedure.
Each applicant will have to provide two grades: the national entrance exam grade GE, and the interview grade GI. The final grade of an applicant is (GE + GI) / 2. The admission rules are:
The applicants are ranked according to their final grades, and will be admitted one by one from the top of the rank list.
If there is a tied final grade, the applicants will be ranked according to their national entrance exam grade GE. If still tied, their ranks must be the same.
Each applicant may have K choices and the admission will be done according to his/her choices: if according to the rank list, it is one's turn to be admitted; and if the quota of one's most preferred shcool is not exceeded, then one will be admitted to this school, or one's other choices will be considered one by one in order. If one gets rejected by all of preferred schools, then this unfortunate applicant will be rejected.
If there is a tied rank, and if the corresponding applicants are applying to the same school, then that school must admit all the applicants with the same rank, even if its quota will be exceeded.
Input Specification:
Each input file contains one test case. Each case starts with a line containing three positive integers: N (<=40,000), the total number of applicants; M (<=100), the total number of graduate schools; and K (<=5), the number of choices an applicant may have.
In the next line, separated by a space, there are M positive integers. The i-th integer is the quota of the i-th graduate school respectively.
Then N lines follow, each contains 2+K integers separated by a space. The first 2 integers are the applicant's GE and GI, respectively. The next K integers represent the preferred schools. For the sake of simplicity, we assume that the schools are numbered from 0 to M-1, and the applicants are numbered from 0 to N-1.
Output Specification:
For each test case you should output the admission results for all the graduate schools. The results of each school must occupy a line, which contains the applicants' numbers that school admits. The numbers must be in increasing order and be separated by a space. There must be no extra space at the end of each line. If no applicant is admitted by a school, you must output an empty line correspondingly.

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
1.设立stu结构体，存储学生的id（防止排序后id打乱了顺序），GE和GI的成绩，总评成绩，排名，志愿学校的列表数组。
2.设立sch结构体，存储school[i]招生的名额限制maxNum，现在已经招收了的学生个数nowNum，招收的学生的id列表stuID，以及当前已经招收了的学生的排名的最后一名lastRank。
3.把学生按照成绩进行排序，并赋值排名。如果GE一样且Grade一样，他们的名次就是一样的。
4.从第一个学生开始，根据他的志愿，来尝试被学校录取。如果当前学校名额未满。那么就录取进去，并且让学校的nowNum加1.并且更新lastRank为这个学生的rank。如果当前学校的lastRank等于自己的rank，那么不管名额满不满都录取。而且记得把学生的id添加到学校的stuID列表中。
5.输出的时候因为id顺序是乱的，要先从小到大排序，然后输出。每个学校占一行、

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, k;
struct stu {
    int id;
    int GE, GI, Grade, rank;
    vector<int> vSchool;
};

struct sch {
    int nowNum;
    int maxNum;
    vector<int> stuID;
    int lastRank;
};

bool cmp1(stu a, stu b) {
    if(a.Grade != b.Grade) {
        return a.Grade > b.Grade;
    } else {
        return a.GE > b.GE;
    }

}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    vector<stu> student(n);
    vector<sch> school(m);
    for(int i = 0; i < m; i++) {
        int temp;
        scanf("%d", &temp);
        school[i].maxNum = temp;
        school[i].nowNum = 0;
        school[i].lastRank = -1;
    }
    for(int i = 0; i < n; i++) {
        student[i].vSchool.resize(k);
        student[i].id = i;
        scanf("%d%d", &student[i].GE, &student[i].GI);
        student[i].Grade = (student[i].GE + student[i].GI) / 2;
        for(int j = 0; j < k; j++) {
            int temp;
            scanf("%d", &temp);
            student[i].vSchool[j] = temp;
        }
    }
    sort(student.begin(), student.end(), cmp1);
    student[0].rank = 1;
    for(int i = 1; i < n; i++) {
        if(student[i].Grade == student[i - 1].Grade && student[i].GE == student[i - 1].GE) {
            student[i].rank = student[i-1].rank;
        } else {
            student[i].rank = student[i-1].rank + 1;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            int schoolID = student[i].vSchool[j];
            int myRank = student[i].rank;
            int myID = student[i].id;
            if(school[schoolID].nowNum < school[schoolID].maxNum || school[schoolID].lastRank == myRank) {
                school[schoolID].nowNum++;
                school[schoolID].lastRank = myRank;
                school[schoolID].stuID.push_back(myID);
                break;
            }
        }
    }
    for(int i = 0; i < m; i++) {
        sort(school[i].stuID.begin(), school[i].stuID.end());
        for(int j = 0; j < school[i].stuID.size(); j++) {
            if(j != 0) printf(" ");
            printf("%d", school[i].stuID[j]);
        }
        printf("\n");
    }
    return 0;
}