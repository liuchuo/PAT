1130. Infix Expression (25)
Given a syntax tree (binary), you are supposed to output the corresponding infix expression, with parentheses reflecting the precedences of the operators.
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N ( <= 20 ) which is the total number of nodes in the syntax tree. Then N lines follow, each gives the information of a node (the i-th line corresponds to the i-th node) in the format:
data left_child right_child
where data is a string of no more than 10 characters, left_child and right_child are the indices of this nodes left and right children, respectively. The nodes are indexed from 1 to N. The NULL link is represented by -1. The figures 1 and 2 correspond to the samples 1 and 2, respectively.
Output Specification:
For each case, print in a line the infix expression, with parentheses reflecting the precedences of the operators. Note that there must be no extra parentheses for the final expression, as is shown by the samples. There must be no space between any symbols.
Sample Input 1:
8
* 8 7
a -1 -1
* 4 1
+ 2 5
b -1 -1
d -1 -1
- -1 6
c -1 -1
Sample Output 1:
(a+b)*(c*(-d))
Sample Input 2:
8
2.35 -1 -1
* 6 1
- -1 4
% 7 8
+ 2 3
a -1 -1
str -1 -1
871 -1 -1
Sample Output 2:
(a*2.35)+(-(str%871))

题目大意：给一个二叉树，输出中缀表达式，且加上括号表示运算的优先级～
分析：首先根据所有孩子结点编号寻找1～n中没有出现过的编号标记为root，即树的根结点～然后进行从root结点开始dfs～dfs递归拼接 "(" + 左子树 + 根 + 右子树 + ")"
递归有四种情况（有效的只有三种）：
1. 左右子树都空 返回 "(" + 根 + ")"
2. 左空右不空 返回 "(" + 根 + 右子树 + ")"
3. 左不空右空 这种情况不存在
4. 左右都不空 返回 "(" + 左子树 + 根 + 右子树 + ")"
最后递归返回的ans，最外层可能会被括号包起来，也可能不被包起来。要判断一下，如果被包起来，把最外层括号去掉即可～

#include <iostream>
using namespace std;
struct node {
    string data;
    int l, r;
}a[100];
string dfs(int root) {
    if(a[root].l == -1 && a[root].r == -1) return a[root].data;
    if(a[root].l == -1 && a[root].r != -1)  return "(" +  a[root].data + dfs(a[root].r) + ")";
    if(a[root].l != -1 && a[root].r != -1) return "(" +  dfs(a[root].l) + a[root].data + dfs(a[root].r) + ")";
}
int main() {
    int have[100] = {0}, n, root = 1;
    cin >> n;
    for(int i  = 1; i <= n; i++) {
        cin >> a[i].data >> a[i].l >> a[i].r;
        if(a[i].l != -1) have[a[i].l] = 1;
        if(a[i].r != -1) have[a[i].r] = 1;
    }
    while(have[root] == 1) root++;
    string ans = dfs(root);
    if(ans[0] == '(') ans = ans.substr(1,ans.size()-2);
    cout << ans;
    return 0;
}