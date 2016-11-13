L3-010. 是否完全二叉搜索树
将一系列给定数字顺序插入一个初始为空的二叉搜索树（定义为左子树键值大，右子树键值小），你需要判断最后的树是否一棵完全二叉树，并且给出其层序遍历的结果。

输入格式：

输入第一行给出一个不超过20的正整数N；第二行给出N个互不相同的正整数，其间以空格分隔。

输出格式：

将输入的N个正整数顺序插入一个初始为空的二叉搜索树。在第一行中输出结果树的层序遍历结果，数字间以1个空格分隔，行的首尾不得有多余空格。第二行输出“YES”，如果该树是完全二叉树；否则输出“NO”。

输入样例1：
9
38 45 42 24 58 30 67 12 51
输出样例1：
38 45 24 58 42 30 12 67 51
YES
输入样例2：
8
38 24 12 45 58 67 42 51
输出样例2：
38 45 24 58 42 12 67 51
NO
分析：根据二叉树的性质，i结点的左孩子为root<<1，右孩子为root<<1|1.建造并用数组存储这个二叉搜索树，然后判断是否是完全二叉树。

#include <cstdio>
using namespace std;
int tree[1<<20];
int num;
void BST(int a) {
    if(tree[a] == 0)
        tree[a] = num;
    else if(tree[a] < num)
        BST(a<<1);
    else
        BST(a<<1|1);
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        BST(1);
    }
    bool flag = true;
        for(int cnt = 1, k = 1; cnt <= n; k++) {
            if(tree[k] == 0)
                flag = false;
            else {
                printf("%d", tree[k]);
                if(cnt++ != n) printf(" ");
            }
        }
    if(flag) printf("\nYES");
    else printf("\nNO");
    return 0;
}