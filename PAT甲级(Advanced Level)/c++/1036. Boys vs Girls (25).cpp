1036. Boys vs Girls (25)
This time you are asked to tell the difference between the lowest grade of all the male students and the highest grade of all the female students.
Input Specification:
Each input file contains one test case. Each case contains a positive integer N, followed by N lines of student information. Each line contains a student's name, gender, ID and grade, separated by a space, where name and ID are strings of no more than 10 characters with no space, gender is either F (female) or M (male), and grade is an integer between 0 and 100. It is guaranteed that all the grades are distinct.
Output Specification:
For each test case, output in 3 lines. The first line gives the name and ID of the female student with the highest grade, and the second line gives that of the male student with the lowest grade. The third line gives the difference gradeF-gradeM. If one such kind of student is missing, output "Absent" in the corresponding line, and output "NA" in the third line instead.
Sample Input 1:
3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95
Sample Output 1:
Mary EE990830
Joe Math990112
6
Sample Input 2:
1
Jean M AA980920 60
Sample Output 2:
Absent
Jean AA980920
NA

题目大意：给出N个同学的信息，输出女生中的最高分获得者的信息与男生中最低分获得者的信息，并输出他们的分数差。如果不存在女生或者男生，则对应获得者信息处输出Absent，而且差值处输出NA。
分析：用string类型的female和male保存要求的学生的信息，femalescore和malescore处保存男生的最低分和女生的最高分
一开始设femalescore为最低值-1，malescore为最高值101，最后根据分值是否为-1或者101来判断是否有相应的女生或者男生。

#include <iostream>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    string female, male;
    int femalescore = -1, malescore = 101;
    for(int i = 0; i < n; i++) {
        string name, sex, num;
        int score;
        cin >> name >> sex >> num;
        scanf("%d", &score);
        if(sex == "F") {
            if(femalescore < score) {
                femalescore = score;
                female = name + " " + num;
            }
        } else if(malescore > score) {
                malescore = score;
                male = name + " " + num;
            }
    }
    if(femalescore != -1) {
        cout << female << endl;
    } else {
        printf("Absent\n");
    }
    if(malescore != 101) {
        cout << male << endl;
    } else {
        printf("Absent\n");
    }
    if(femalescore != -1 && malescore != 101) {
        printf("%d", femalescore - malescore);
    } else {
        printf("NA");
    }
    return 0;
}