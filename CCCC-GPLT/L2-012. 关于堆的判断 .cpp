L2-012. 关于堆的判断
将一系列给定数字顺序插入一个初始为空的小顶堆H[]。随后判断一系列相关命题是否为真。命题分下列几种：

“x is the root”：x是根结点；
“x and y are siblings”：x和y是兄弟结点；
“x is the parent of y”：x是y的父结点；
“x is a child of y”：x是y的一个子结点。
输入格式：

每组测试第1行包含2个正整数N（<= 1000）和M（<= 20），分别是插入元素的个数、以及需要判断的命题数。下一行给出区间[-10000, 10000]内的N个要被插入一个初始为空的小顶堆的整数。之后M行，每行给出一个命题。题目保证命题中的结点键值都是存在的。

输出格式：

对输入的每个命题，如果其为真，则在一行中输出“T”，否则输出“F”。

输入样例：
5 4
46 23 26 24 10
24 is the root
26 and 23 are siblings
46 is the parent of 23
23 is a child of 10
输出样例：
F
T
F
T

分析：必须注意，因为题目要求按照插入的顺序建立，所以是边插入边调整的，必须用向上调整，每次输入一个数之后就将它向上调整。（两者建立出来的二叉树不同）而不能采用先转换为二叉树的方式再向下调整。


#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector<int> v;
int n;
void upAdjust(int i) {
    if(i == 1) return ;
    while(i != 1) {
        if(v[i] < v[i / 2]) {
            swap(v[i], v[i / 2]);
            i = i / 2;
        } else {
            break;
        }
    }
}
void judge1(int a) {
    if(v[1] == a) printf("T\n");
    else printf("F\n");
}
void judge2(int a, int b) {
    int indexa = 0, indexb = 0;
    for(int i = 1; i <= n; i++) {
        if(v[i] == a) indexa = i;
        if(v[i] == b) indexb = i;
    }
    if(indexa > indexb) swap(indexa, indexb);
    if(indexa % 2 == 0 && indexb - indexa == 1) printf("T\n");
    else printf("F\n");
}
void judge3(int a, int b) {
    int indexa = 0, indexb = 0;
    for(int i = 1; i <= n; i++) {
        if(v[i] == a) indexa = i;
        if(v[i] == b) indexb = i;
    }
    if((2 * indexa) == indexb || (2 * indexa) + 1 == indexb) printf("T\n");
    else printf("F\n");
}
void judge4(int a, int b) {
    int indexa = 0, indexb = 0;
    for(int i = 1; i <= n; i++) {
        if(v[i] == a) indexa = i;
        if(v[i] == b) indexb = i;
    }
    if(indexa == indexb * 2 || indexa == 2 * indexb + 1) printf("T\n");
    else printf("F\n");
}
int main() {
    int k, a, b;
    char c[100];
    scanf("%d%d", &n, &k);
    v.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        upAdjust(i);
    }
    for(int i = 0; i < k; i++) {
        scanf("%d%s", &a, c);
        if(strcmp(c, "and") == 0) {
            scanf("%d%s%s", &b, c, c);
            judge2(a, b);
        } else {
            scanf("%s", c);
            if(strcmp(c, "a") == 0) {
                scanf("%s%s%d", c, c, &b);
                judge4(a, b);
            } else {
                scanf("%s", c);
                if(strcmp(c, "root") == 0) {
                    judge1(a);
                } else {
                    scanf("%s%d", c, &b);
                    judge3(a, b);
                }
            }
        }
    }
    return 0;
}