L2-011. 玩转二叉树
给定一棵二叉树的中序遍历和前序遍历，请你先将树做个镜面反转，再输出反转后的层序遍历的序列。所谓镜面反转，是指将所有非叶结点的左右孩子对换。这里假设键值都是互不相等的正整数。

输入格式：

输入第一行给出一个正整数N（<=30），是二叉树中结点的个数。第二行给出其中序遍历序列。第三行给出其前序遍历序列。数字间以空格分隔。

输出格式：

在一行中输出该树反转后的层序遍历的序列。数字间以1个空格分隔，行首尾不得有多余空格。

输入样例：
7
1 2 3 4 5 6 7
4 1 3 2 6 5 7
输出样例：
4 6 1 7 5 3 2

分析：与前序中序转换为后序的代码相仿（无须构造二叉树再进行广度优先搜索~~），只不过加一个变量index，表示当前的根结点在二叉树中所对应的下标（从0开始），所以进行一次输出先序的递归的时候，就可以把根结点下标所对应的值存储在level数组中（一开始把level都置为-1表示此处没有结点），镜面反转只需改变index的值，左孩子为2 * index + 2， 右孩子为2 * index + 1，这样在递归完成后level数组中非-1的数就是按照下标排列的层序遍历的顺序~~~

#include <cstdio>
#include <vector>
using namespace std;
vector<int> in, pre, level(100000, -1);
void post(int root, int start, int end, int index) {
    if(start > end) return ;
    int i = start;
    while(i < end && in[i] != pre[root]) i++;
    level[index] = pre[root];
    post(root + 1, start, i - 1, 2 * index + 2);
    post(root + 1 + i - start, i + 1, end, 2 * index + 1);
}
int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    in.resize(n);
    pre.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &in[i]);
    for(int i = 0; i < n; i++) scanf("%d", &pre[i]);
    post(0, 0, n-1, 0);
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