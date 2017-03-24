L2-002. 链表去重
给定一个带整数键值的单链表L，本题要求你编写程序，删除那些键值的绝对值有重复的结点。即对任意键值K，只有键值或其绝对值等于K的第一个结点可以被保留。同时，所有被删除的结点必须被保存在另外一个链表中。例如：另L为21→-15→-15→-7→15，则你必须输出去重后的链表21→-15→-7、以及被删除的链表-15→15。

输入格式：

输入第一行包含链表第一个结点的地址、以及结点个数N（<= 105 的正整数）。结点地址是一个非负的5位整数，NULL指针用-1表示。

随后N行，每行按下列格式给出一个结点的信息：

Address Key Next

其中Address是结点的地址，Key是绝对值不超过104的整数，Next是下一个结点的地址。

输出格式：

首先输出去重后的链表，然后输出被删除结点组成的链表。每个结点占一行，按输入的格式输出。

输入样例：
00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854
输出样例：
00100 21 23854
23854 -15 99999
99999 -7 -1
00000 -15 87654
87654 15 -1

题目大意：给一个链表，去重（去掉值或者绝对值相等的），先输出删除后的链表，再输出删除了的链表。
分析：用结构体数组存储这个链表，大小为maxn = 100000，node[i]表示地址为i的结点。在结构体中定义一个num变量，将num变量先初始化为2 * maxn。通过改变num变量的值最后sort排序来改变链表的顺序。
将没有删除的结点的num标记为cnt1，cnt1为当前没有删除的结点的个数；将需要删除的结点的num标记为maxn + cnt2，cnt2表示当前删除了的结点的个数，因为一开始初始化为了2 * maxn，所以我们可以通过对num排序达到：num = 0~maxn为不删除结点，num = maxn~2maxn为删除结点，num = 2maxn为无效结点
这样sort后就会按照需要输出的顺序将结点排序，我们只需要输出前cnt1+cnt2个结点即可~~~~

#include <cstdio>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn = 100000;
struct NODE {
    int address;
    int key;
    int next;
    int num;
}node[maxn];
bool exist[maxn];
int cmp1(NODE a, NODE b){
    return a.num < b.num;
}
int main() {
    int begin, n, cnt1 = 0, cnt2 = 0, a;
    scanf("%d%d", &begin, &n);
    for(int i = 0; i < maxn; i++) {
        node[i].num = 2 * maxn;
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        scanf("%d%d", &node[a].key, &node[a].next);
        node[a].address = a;
    }
    for(int i = begin; i != -1; i = node[i].next) {
        if(exist[abs(node[i].key)] == false) {
            exist[abs(node[i].key)] = true;
            node[i].num = cnt1;
            cnt1++;
        }
        else {
            node[i].num = maxn + cnt2;
            cnt2++;
        }
    }
    sort(node, node + maxn, cmp1);
    int cnt = cnt1 + cnt2;
    for(int i = 0; i < cnt; i++) {
        if(i != cnt1 - 1 && i != cnt - 1) {
            printf("%05d %d %05d\n", node[i].address, node[i].key, node[i+1].address);
        } else {
            printf("%05d %d -1\n", node[i].address, node[i].key);
        }
    }
    return 0;
}