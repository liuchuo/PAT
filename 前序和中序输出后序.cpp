已知前序（先序）与中序输出后序：
前序：1, 2, 3, 4, 5, 6（根左右）
中序：3, 2, 4, 1, 6, 5（左根右）
分析：因为前序（根左右）最先出现的总是根结点，所以令root为前序中当前的根结点下标（并且同时把一棵树分为左子树和右子树）。start为当前需要打印的子树在中序中的最左边的下标，end为当前需要打印的子树在中序中最右边的下标。递归打印这棵树的后序，递归出口为start > end。i为root所表示的值在中序中的下标，所以i即是分隔中序中对应root结点的左子树和右子树的下标。
先打印左子树，后打印右子树，最后输出当前根结点pre[root]的值。
输出的后序应该为：3, 4, 2, 6, 5, 1（左右根）

#include <cstdio>
using namespace std;
int pre[] = {1, 2, 3, 4, 5, 6};
int in[] = {3, 2, 4, 1, 6, 5};
void post(int root, int start, int end) {
    if(start > end) 
        return ;
    int i = start;
    while(i < end && in[i] != pre[root]) i++;
    post(root + 1, start, i - 1);
    post(root + 1 + i - start, i + 1, end);
    printf("%d ", pre[root]);
}

int main() {
    post(0, 0, 5);
    return 0;
}