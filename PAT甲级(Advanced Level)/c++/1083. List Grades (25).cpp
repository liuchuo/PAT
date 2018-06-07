1083. List Grades (25)
Given a list of N student records with name, ID and grade. You are supposed to sort the records with respect to the grade in non-increasing order, and output those student records of which the grades are in a given interval.
Input Specification:
Each input file contains one test case. Each case is given in the following format:
N
name[1] ID[1] grade[1]
name[2] ID[2] grade[2]
... ...
name[N] ID[N] grade[N]
grade1 grade2
where name[i] and ID[i] are strings of no more than 10 characters with no space, grade[i] is an integer in [0, 100], grade1 and grade2 are the boundaries of the grade's interval. It is guaranteed that all the grades are distinct.
Output Specification:
For each test case you should output the student records of which the grades are in the given interval [grade1, grade2] and are in non-increasing order. Each student record occupies a line with the student's name and ID, separated by one space. If there is no student's grade in that interval, output "NONE" instead.
Sample Input 1:
4
Tom CS000001 59
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
60 100
Sample Output 1:
Mike CS991301
Mary EE990830
Joe Math990112
Sample Input 2:
2
Jean AA980920 60
Ann CS01 80
90 95
Sample Output 2:
NONE

题目大意：给出n个考生的信息，按照分数从高到低排序，并且输出给定区间的考生信息。如果不存在满足条件的考生就输出NONE。
分析：建立结构体数组，将不满足条件的学生grade改为-1，并统计满足条件的学生的个数cnt，然后进行排序，输出前cnt个考生的信息
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct stu {
    char name[12];
    char id[12];
    int grade;
};
bool cmp1(stu a, stu b) {
    return a.grade > b.grade;
}
int main() {
    int n, low, high, cnt = 0;
    scanf("%d", &n);
    vector<stu> v(n);
    for(int i = 0; i < n; i++) {
        scanf("%s %s %d", v[i].name, v[i].id, &v[i].grade);
    }
    scanf("%d %d", &low, &high);
    for(int i = 0; i < n; i++) {
        if(v[i].grade < low || v[i].grade > high) {
            v[i].grade = -1;
        } else {
            cnt++;
        }
    }
    sort(v.begin(), v.end(), cmp1);
    for(int i = 0; i < cnt; i++) {
        printf("%s %s\n", v[i].name, v[i].id);
    }
    if(cnt == 0)
        printf("NONE");
    return 0;
}