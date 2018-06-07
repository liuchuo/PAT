1128. N Queens Puzzle (20)
The "eight queens puzzle" is the problem of placing eight chess queens on an 8×8 chessboard so that no two queens threaten each other. Thus, a solution requires that no two queens share the same row, column, or diagonal. The eight queens puzzle is an example of the more general N queens problem of placing N non-attacking queens on an N×N chessboard. (From Wikipedia - "Eight queens puzzle".)
Here you are NOT asked to solve the puzzles. Instead, you are supposed to judge whether or not a given configuration of the chessboard is a solution. To simplify the representation of a chessboard, let us assume that no two queens will be placed in the same column. Then a configuration can be represented by a simple integer sequence (Q1, Q2, ..., QN), where Qi is the row number of the queen in the i-th column. For example, Figure 1 can be represented by (4, 6, 8, 2, 7, 1, 3, 5) and it is indeed a solution to the 8 queens puzzle; while Figure 2 can be represented by (4, 6, 7, 2, 8, 1, 9, 5, 3) and is NOT a 9 queens' solution.
Input Specification:
Each input file contains several test cases. The first line gives an integer K (1 < K <= 200). Then K lines follow, each gives a configuration in the format "N Q1 Q2 ... QN", where 4 <= N <= 1000 and it is guaranteed that 1 <= Qi <= N for all i=1, ..., N. The numbers are separated by spaces.
Output Specification:
For each configuration, if it is a solution to the N queens problem, print "YES" in a line; or "NO" if not.
Sample Input:
4
8 4 6 8 2 7 1 3 5
9 4 6 7 2 8 1 9 5 3
6 1 5 2 6 4 3
5 1 3 5 2 4
Sample Output:
YES
NO
NO
YES

题目大意：给出一个皇后图，以这样的方式给出：一个数组包含n个数字，每个数字表示该列的皇后所在的行数～判断给出的皇后图是否满足不会互相攻击（任意两个皇后都要不在同一行或者同一列，且不在斜对角线上～）
分析：用v[n]存储一张图给出的数字～对于第j个数字，判断前0～j-1个数字中是否有在同一行的（v[j] == v[t])和在斜对角线上的（abs(v[j]-v[t]) == abs(j-t)）【因为已经告诉肯定不在同一列了，所以不需要判断是否在同一列啦～】如果发现了不满足的情况，就将result由true标记为false～最后根据result是true还是false输出对应的YES还是NO即可～

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int k, n;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> n;
        vector<int> v(n);
        bool result = true;
        for (int j = 0; j < n; j++) {
            cin >> v[j];
            for (int t = 0; t < j; t++) {
                if (v[j] == v[t] || abs(v[j]-v[t]) == abs(j-t)) {
                    result = false;
                    break;
                }
            }
        }
        cout << (result == true ? "YES\n" : "NO\n");
    }
    return 0;
}