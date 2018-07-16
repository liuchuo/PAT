1058. 选择题(20)
批改多选题是比较麻烦的事情，本题就请你写个程序帮助老师批改多选题，并且指出哪道题错的人最多。
输入格式：
输入在第一行给出两个正整数N（<=1000）和M（<=100），分别是学生人数和多选题的个数。随后M行，每行顺次给出一道题的满分值（不超过5的正整数）、选项个数（不少于2且不超过5的正整数）、正确选项个数（不超过选项个数的正整数）、所有正确选项。注意每题的选项从小写英文字母a开始顺次排列。各项间以1个空格分隔。最后N行，每行给出一个学生的答题情况，其每题答案格式为“(选中的选项个数 选项1 ……)”，按题目顺序给出。注意：题目保证学生的答题情况是合法的，即不存在选中的选项数超过实际选项数的情况。
输出格式：
按照输入的顺序给出每个学生的得分，每个分数占一行。注意判题时只有选择全部正确才能得到该题的分数。最后一行输出错得最多的题目的错误次数和编号（题目按照输入的顺序从1开始编号）。如果有并列，则按编号递增顺序输出。数字间用空格分隔，行首尾不得有多余空格。如果所有题目都没有人错，则在最后一行输出“Too simple”。
输入样例：
3 4
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (2 b d) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (2 b c) (4 a b c d)
输出样例：
3
6
5
2 2 3 4

分析：n个学生，m道题目。对于每一道题目，将题目的总分存储在total[i]数组里面，将题目的选项插入存储在right[i]（为集合类型）里面。wrongCnt[i]存储第i道题错误的人数，对于n个学生，每一个学生的答案插入一个集合st里面，比较st与right[i]是否相等，如果相等说明该生答对了，他的score += total[i]（加上当前题目的总分），如果该生答错了，wrongCnt[i]++，表示第i道题新增一个错误的人。输出每一个学生的得分；遍历wrongCnt数组，求wrongCnt的最大值maxWrongCnt。如果maxWrongCnt == 0说明没有一个人做错题目，则输出“Too simple”，否则输出maxWrongCnt的值，和wrongCnt数组中wrongCnt[i] == maxWrongCnt的那些题号~~
注意：scanf中的%d和%c之间一定要有分隔符的主动scanf输入，否则可能接收成空格或者空值~~

#include <cstdio>
#include <vector>
#include <set>
using namespace std;
int main() {
    int n, m, temp, k;
    scanf("%d%d", &n, &m);
    vector<set<char>> right(m);
    vector<int> total(m), wrongCnt(m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &total[i], &temp, &k);
        for(int j = 0; j < k; j++) {
            char c;
            scanf(" %c", &c);
            right[i].insert(c);
        }
    }
    for(int i = 0; i < n; i++) {
        int score = 0;
        scanf("\n");
        for(int j = 0; j < m; j++) {
            if(j != 0) scanf(" ");
            scanf("(%d", &k);
            set<char> st;
            char c;
            for(int l = 0; l < k; l++) {
                scanf(" %c", &c);
                st.insert(c);
            }
            scanf(")");
            if(st == right[j]) {
                score += total[j];
            } else {
                wrongCnt[j]++;
            }
        }
        printf("%d\n", score);
    }
    int maxWrongCnt = 0;
    for(int i = 0; i < m; i++) {
        if(wrongCnt[i] > maxWrongCnt) {
            maxWrongCnt = wrongCnt[i];
        }
    }
    if(maxWrongCnt == 0)
        printf("Too simple");
    else {
        printf("%d", maxWrongCnt);
        for(int i = 0; i < m; i++) {
            if(wrongCnt[i] == maxWrongCnt) {
                printf(" %d", i + 1);
            }
        }
    }
    return 0;
}