L2-006. 树的遍历
给定一棵二叉树的后序遍历和中序遍历，请你输出其层序遍历的序列。这里假设键值都是互不相等的正整数。

输入格式：

输入第一行给出一个正整数N（<=30），是二叉树中结点的个数。第二行给出其后序遍历序列。第三行给出其中序遍历序列。数字间以空格分隔。

输出格式：

在一行中输出该树的层序遍历的序列。数字间以1个空格分隔，行首尾不得有多余空格。

输入样例：
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
输出样例：
4 1 6 3 5 7 2
分析：与后序中序转换为前序的代码相仿（无须构造二叉树再进行广度优先搜索~~），只不过加一个变量index，表示当前的根结点在二叉树中所对应的下标（从0开始），所以进行一次输出先序的递归的时候，就可以把根结点下标所对应的值存储在level数组中（一开始把level都置为-1表示此处没有结点），这样在递归完成后level数组中非-1的数就是按照下标排列的层序遍历的顺序~~~

#include <cstdio>
#include <vector>
using namespace std;
vector<int> post, in, level(100000, -1);
void pre(int root, int start, int end, int index) {
    if(start > end) return ;
    int i = start;
    while(i < end && in[i] != post[root]) i++;
    level[index] = post[root];
    pre(root - 1 - end + i, start, i - 1, 2 * index + 1);
    pre(root - 1, i + 1, end, 2 * index + 2);
}
int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    post.resize(n);
    in.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &post[i]);
    for(int i = 0; i < n; i++) scanf("%d", &in[i]);
    pre(n-1, 0, n-1, 0);
    for(int i = 0; i < level.size(); i++) {
        if(level[i] != -1 && cnt != n - 1) {
            printf("%d ", level[i]);
            cnt++;
        } else if(level[i] != -1){
            printf("%d", level[i]);
            break;
        }
    }
    return 0;
}