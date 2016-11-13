L2-004. 这是二叉搜索树吗？
一棵二叉搜索树可被递归地定义为具有下列性质的二叉树：对于任一结点，

其左子树中所有结点的键值小于该结点的键值；
其右子树中所有结点的键值大于等于该结点的键值；
其左右子树都是二叉搜索树。
所谓二叉搜索树的“镜像”，即将所有结点的左右子树对换位置后所得到的树。

给定一个整数键值序列，现请你编写程序，判断这是否是对一棵二叉搜索树或其镜像进行前序遍历的结果。

输入格式：

输入的第一行给出正整数N（<=1000）。随后一行给出N个整数键值，其间以空格分隔。

输出格式：

如果输入序列是对一棵二叉搜索树或其镜像进行前序遍历的结果，则首先在一行中输出“YES”，然后在下一行输出该树后序遍历的结果。数字间有1个空格，一行的首尾不得有多余空格。若答案是否，则输出“NO”。

输入样例1：
7
8 6 5 7 10 8 11
输出样例1：
YES
5 7 6 8 11 10 8
输入样例2：
7
8 10 11 8 6 7 5
输出样例2：
YES
11 8 10 7 5 6 8
输入样例3：
7
8 6 8 5 10 9 11
输出样例3：
NO
分析：假设它是二叉搜索树，一开始isMirror为FALSE，根据二叉搜索树的性质将已知的前序转换为后序，转换过程中，如果发现最后输出的后序数组长度不为n，那就设isMirror为true，然后清空后序数组，重新再转换一次（根据镜面二叉搜索树的性质），如果依旧转换后数组大小不等于n，就输出no否则输出yes

#include <cstdio>
#include <vector>
using namespace std;
bool isMirror;
vector<int> pre;
vector<int> post;
void getpost(int root, int tail) {
    if(root > tail) return ;
    int i = root + 1, j = tail;
    if(!isMirror) {
        while(i <= tail && pre[root] > pre[i]) i++;
        while(j > root && pre[root] <= pre[j]) j--;
    } else {
        while(i <= tail && pre[root] <= pre[i]) i++;
        while(j > root && pre[root] > pre[j]) j--;
    }
    if(i - j != 1) return ;
    getpost(root + 1, j);
    getpost(i, tail);
    post.push_back(pre[root]);
}
int main() {
    int n;
    scanf("%d", &n);
    pre.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    getpost(0, n - 1);
    if(post.size() != n) {
        isMirror = true;
        post.clear();
        getpost(0, n - 1);
    }
    if(post.size() == n) {
        printf("YES\n%d", post[0]);
        for(int i = 1; i < n; i++)
            printf(" %d", post[i]);
    } else {
        printf("NO");
    }
    return 0;
}