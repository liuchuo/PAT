1073. 多选题常见计分法(20)
批改多选题是比较麻烦的事情，有很多不同的计分方法。有一种最常见的计分方法是：如果考生选择了部分正确选项，并且没有选择任何错误选项，则得到50%分数；如果考生选择了任何一个错误的选项，则不能得分。本题就请你写个程序帮助老师批改多选题，并且指出哪道题的哪个选项错的人最多。
输入格式：
输入在第一行给出两个正整数N（<=1000）和M（<=100），分别是学生人数和多选题的个数。随后M行，每行顺次给出一道题的满分值（不超过5的正整数）、选项个数（不少于2且不超过5的正整数）、正确选项个数（不超过选项个数的正整数）、所有正确选项。注意每题的选项从小写英文字母a开始顺次排列。各项间以1个空格分隔。最后N行，每行给出一个学生的答题情况，其每题答案格式为“(选中的选项个数 选项1 ……)”，按题目顺序给出。注意：题目保证学生的答题情况是合法的，即不存在选中的选项数超过实际选项数的情况。
输出格式：
按照输入的顺序给出每个学生的得分，每个分数占一行，输出小数点后1位。最后输出错得最多的题目选项的信息，格式为：“错误次数 题目编号（题目按照输入的顺序从1开始编号）-选项号”。如果有并列，则每行一个选项，按题目编号递增顺序输出；再并列则按选项号递增顺序输出。行首尾不得有多余空格。如果所有题目都没有人错，则在最后一行输出“Too simple”。
输入样例1：
3 4 
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (3 b d e) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (1 c) (4 a b c d)
输出样例1：
3.5
6.0
2.5
2 2-e
2 3-a
2 3-b
输入样例2：
2 2 
3 4 2 a c
2 5 1 b
(2 a c) (1 b)
(2 a c) (1 b)
输出样例2：
5.0
5.0
Too simple

分析：错误是指错选或者漏选。我用异或运算来判断一个选项和正确选项是否匹配，如果是匹配的，那么异或的结果应当是0；如果不匹配，那么这个选项就是存在错选或者漏选的情况的。例：设a为00001，b为00010，c为00100，d为01000，e为10000，如果给定的正确答案是ac，即10001，那么如果给出的选项也是10001，异或的结果就是0；如果给出的选项是a或者ab，即00001或00011，异或之后不为0，就是错选和漏选的。通过异或操作的结果，再用与运算就可以把错选和漏选的选项找出来，具体的看代码。
full_socre表示一道题满分的分值；true_opt表示正确的选项，存储的是正确选项二进制的值，二进制有hash给出分别是1,2,4,8,16；fre是错误的次数。

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int n = 0, m = 0, opt_num = 0, true_opt_num = 0, temp = 0, max_error_cnt = 0;
    int hash[] = {1, 2, 4, 8, 16}, opt[1010][110] = {0};
    char c;
    scanf("%d %d", &n, &m);
    vector<int> full_score(m), true_opt(m);
    vector<vector<int> > fre(m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &full_score[i], &opt_num, &true_opt_num);
        for (int j = 0; j < true_opt_num; j++) {
            scanf(" %c", &c);
            true_opt[i] += hash[c-'a'];
        }
        fre[i].resize(5);
    }
    for (int i = 0; i < n; i++) {
        double grade = 0;
        for (int j = 0; j < m; j++) {
            getchar();
            getchar(); // '('
            scanf("%d", &temp);
            for (int k = 0; k < temp; k++) {
                scanf(" %c", &c);
                opt[i][j] += hash[c-'a'];
            }
            getchar(); // ')'
            int el = opt[i][j] ^ true_opt[j];
            if (el) {
                if ((opt[i][j] | true_opt[j]) == true_opt[j]) {
                    grade += full_score[j] * 1.0 / 2;
                }
                if (el) {
                    if (el & hash[0]) fre[j][0]++; // a
                    if (el & hash[1]) fre[j][1]++; // b
                    if (el & hash[2]) fre[j][2]++; // c
                    if (el & hash[3]) fre[j][3]++; // d
                    if (el & hash[4]) fre[j][4]++; // e
                }
            } else
                grade += full_score[j];
        }
        printf("%.1f\n", grade);
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < 5; j++)
            max_error_cnt = max_error_cnt > fre[i][j] ? max_error_cnt : fre[i][j];
    
    if (max_error_cnt == 0) {
        printf("Too simple\n");
    } else {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < fre[i].size(); j++) {
                if (max_error_cnt == fre[i][j]) {
                    printf("%d %d-%c\n", max_error_cnt, i+1, 'a'+j);
                }
            }
        }
    }
    return 0;
}
