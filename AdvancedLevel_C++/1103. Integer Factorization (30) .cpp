1103. Integer Factorization (30)
The K-P factorization of a positive integer N is to write N as the sum of the P-th power of K positive integers. You are supposed to write a program to find the K-P factorization of N for any positive integers N, K and P.
Input Specification:
Each input file contains one test case which gives in a line the three positive integers N (<=400), K (<=N) and P (1<P<=7). The numbers in a line are separated by a space.
Output Specification:
For each case, if the solution exists, output in the format:
N = n1^P + ... nK^P
where ni (i=1, ... K) is the i-th factor. All the factors must be printed in non-increasing order.
Note: the solution may not be unique. For example, the 5-2 factorization of 169 has 9 solutions, such as 122 + 42 + 22 + 22 + 12, or 112 + 62 + 22 + 22 + 22, or more. You must output the one with the maximum sum of the factors. If there is a tie, the largest factor sequence must be chosen -- sequence { a1, a2, ... aK } is said to be larger than { b1, b2, ... bK } if there exists 1<=L<=K such that ai=bi for i<L and aL>bL
If there is no solution, simple output "Impossible".
Sample Input 1:
169 5 2
Sample Output 1:
169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2
Sample Input 2:
169 167 3
Sample Output 2:
Impossible

题目大意：给三个正整数N、K、P，将N表示成K个正整数（可以相同，递减排列）的P次方和，如果有多种方案，选择底数n1+...+nk最大的方案，如果还有多种方案，选择底数序列的字典序最大的方案～
分析：dfs深度优先搜索。先把i从0开始所有的i的p次方的值存储在v[i]中，直到v[i] > n为止。然后深度优先搜索，记录当前正在相加的index（即v[i]的i的值），当前的总和tempSum，当前K的总个数tempK，以及因为题目中要求输出因子的和最大的那个，所以保存一个facSum为当前因子的和，让它和maxFacSum比较，如果比maxFacSum大就更新maxFacSum和要求的ans数组的值。
在ans数组里面存储因子的序列，tempAns为当前深度优先遍历而来的序列，从v[i]的最后一个index开始一直到index == 1，因为这样才能保证ans和tempAns数组里面保存的是从大到小的因子的顺序。一开始maxFacSum == -1，如果dfs后maxFacSum并没有被更新，还是-1，那么就输出Impossible，否则输出答案。

（PS：感谢github用户littlesevenmo提供的更优解）
分析：这道题考的是DFS+剪枝，我认为主要剪枝的地方有三个：
1. tempK==K但是tempSum!=n的时候需要剪枝
2. 在枚举的时候，按顺序枚举，上界或者下界可进行剪枝
3. 当且仅当tempSum + v[index] <= n时，进行下一层的DFS，而不要进入下一层DFS发现不满足条件再返回，这样开销会比较大～

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, k, p, maxFacSum = -1;
vector<int> v, ans, tempAns;
void init() {
    int temp = 0, index = 1;
    while (temp <= n) {
        v.push_back(temp);
        temp = pow(index, p);
        index++;
    }
}
void dfs(int index, int tempSum, int tempK, int facSum) {
    if (tempK == k) {
        if (tempSum == n && facSum > maxFacSum) {
                ans = tempAns;
                maxFacSum = facSum;
        }
        return;
    }
    while(index >= 1) {
        if (tempSum + v[index] <= n) {
            tempAns[tempK] = index;
            dfs(index, tempSum + v[index], tempK + 1, facSum + index);
        }
        if (index == 1) return;
        index--;
    }
}
int main() {
    scanf("%d%d%d", &n, &k, &p);
    init(); 
    tempAns.resize(k);
    dfs(v.size() - 1, 0, 0, 0);
    if (maxFacSum == -1) {
        printf("Impossible");
        return 0;
    }
    printf("%d = ", n);
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) printf(" + ");
        printf("%d^%d", ans[i], p);
    }
    return 0;
}