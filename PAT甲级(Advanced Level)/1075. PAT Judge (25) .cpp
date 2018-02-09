1075. PAT Judge (25)
The ranklist of PAT is generated from the status list, which shows the scores of the submittions. This time you are supposed to generate the ranklist for PAT.
Input Specification:
Each input file contains one test case. For each case, the first line contains 3 positive integers, N (<=104), the total number of users, K (<=5), the total number of problems, and M (<=105), the total number of submittions. It is then assumed that the user id's are 5-digit numbers from 00001 to N, and the problem id's are from 1 to K. The next line contains K positive integers p[i] (i=1, ..., K), where p[i] corresponds to the full mark of the i-th problem. Then M lines follow, each gives the information of a submittion in the following format:
user_id problem_id partial_score_obtained
where partial_score_obtained is either -1 if the submittion cannot even pass the compiler, or is an integer in the range [0, p[problem_id]]. All the numbers in a line are separated by a space.
Output Specification:
For each test case, you are supposed to output the ranklist in the following format:
rank user_id total_score s[1] ... s[K]
where rank is calculated according to the total_score, and all the users with the same total_score obtain the same rank; and s[i] is the partial score obtained for the i-th problem. If a user has never submitted a solution for a problem, then "-" must be printed at the corresponding position. If a user has submitted several solutions to solve one problem, then the highest score will be counted.
The ranklist must be printed in non-decreasing order of the ranks. For those who have the same rank, users must be sorted in nonincreasing order according to the number of perfectly solved problems. And if there is still a tie, then they must be printed in increasing order of their id’s. For those who has never submitted any solution that can pass the compiler, or has never submitted any solution, they must NOT be shown on the ranklist. It is guaranteed that at least one user can be shown on the ranklist.
Sample Input:
7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0
Sample Output:
1 00002 63 20 25 - 18
2 00005 42 20 0 22 -
2 00007 42 - 25 - 17
2 00001 42 18 18 4 2
5 00004 40 15 0 25 -

分析：结构体数组中passnum统计完整通过的题目个数，isshown在用户有一题通过了编译器（不管得不得0分）的时候置为true。vector<int> score;记录每门课的最高分
因为没有通过编译器的分数为0，但是没有提交过的分数为“-”，所以把有一门课每次都是未通过编译器的那门课分数置为-2。初始化数组分数为-1，所以可以根据-1和-2判断当前分数是提交过了没通过编译器的，还是没提交过的题目。
注意：因为最后一个测试样例是有一个人一开始得到了分数，后来提交了一次没有通过编译器的，所以要判断在分数每次更新最大值之后if(v[id].score[num] == -1)，说明最好成绩只是-1（也就是没通过编译器或者没有提交过），这个时候再置v[id].score[num] = -2，否则会误操作把已经提交过很好分数的人的成绩抹掉成了-2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int rank, id, total = 0;
    vector<int> score;
    int passnum = 0;
    bool isshown = false;
};
bool cmp1(node a, node b) {
    if(a.total != b.total)
        return a.total > b.total;
    else if(a.passnum != b.passnum)
        return a.passnum > b.passnum;
    else
        return a.id < b.id;
}

int main() {
    int n, k, m, id, num, score;
    scanf("%d %d %d", &n, &k, &m);
    vector<node> v(n + 1);
    for(int i = 1; i <= n; i++)
        v[i].score.resize(k + 1, -1);
    vector<int> full(k + 1);
    for(int i = 1; i <= k; i++)
        scanf("%d", &full[i]);
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &id, &num, &score);
        v[id].id = id;
        v[id].score[num] = max(v[id].score[num], score);
        if(score != -1)
            v[id].isshown = true;
        else if(v[id].score[num] == -1)
            v[id].score[num] = -2;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(v[i].score[j] != -1 && v[i].score[j] != -2)
                v[i].total += v[i].score[j];
            if(v[i].score[j] == full[j])
                v[i].passnum++;
        }
    }
    sort(v.begin() + 1, v.end(), cmp1);
    for(int i = 1; i <= n; i++) {
        v[i].rank = i;
        if(i != 1 && v[i].total == v[i - 1].total)
            v[i].rank = v[i - 1].rank;
    }
    for(int i = 1; i <= n; i++) {
        if(v[i].isshown == true) {
            printf("%d %05d %d", v[i].rank, v[i].id, v[i].total);
            for(int j = 1; j <= k; j++) {
                if(v[i].score[j] != -1 && v[i].score[j] != -2)
                    printf(" %d", v[i].score[j]);
                else if(v[i].score[j] == -1)
                    printf(" -");
                else
                    printf(" 0");
            }
            printf("\n");
        }
    }
    return 0;
}