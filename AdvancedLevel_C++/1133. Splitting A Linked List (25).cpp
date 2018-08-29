1133. Splitting A Linked List (25)
Given a singly linked list, you are supposed to rearrange its elements so that all the negative values appear before all of the non-negatives, and all the values in [0, K] appear before all those greater than K. The order of the elements inside each class must not be changed. For example, given the list being 18→7→-4→0→5→-6→10→11→-2 and K being 10, you must output -4→-6→-2→7→0→5→10→18→11.
Input Specification:
Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (<= 105) which is the total number of nodes, and a positive K (<=1000). The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.
Then N lines follow, each describes a node in the format:
Address Data Next
where Address is the position of the node, Data is an integer in [-105, 105], and Next is the position of the next node. It is guaranteed that the list is not empty.
Output Specification:
For each case, output in order (from beginning to the end of the list) the resulting linked list. Each node occupies a line, and is printed in the same format as in the input.
Sample Input:
00100 9 10
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218
Sample Output:
33218 -4 68237
68237 -6 48652
48652 -2 12309
12309 7 00000
00000 0 99999
99999 5 23333
23333 10 00100
00100 18 27777
27777 11 -1

题目大意：给一个链表和K，遍历链表后将<0的结点先输出，再将0～k区间的结点输出，最后输出>k的结点

分析：1.所有节点用结构体｛id, data, next｝存储
2.遍历链表，找出在此链表中的节点，放入容器v中
3.把节点分三类｛（-无穷，0）, [0,k], (k,+无穷) ｝,把他们按段，按先后顺序依次放进
容器ans中，最后输出即可～

#include <iostream>
#include <vector>
using namespace std;
struct node {
    int id, data, next;
};
int main() {
    int begin, n, k, s, d, e;
    scanf("%d%d%d", &begin, &n, &k);
    node a[100010];
    vector<node> v, ans;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &s, &d, &e);
        a[s] = {s, d, e};
    }
    for (; begin != -1; begin = a[begin].next)
        v.push_back(a[begin]);
    for (int i = 0; i < v.size(); i++)
        if (v[i].data < 0) ans.push_back(v[i]);
    for (int i = 0; i < v.size(); i++)
        if (v[i].data >= 0 && v[i].data <= k) ans.push_back(v[i]);
    for (int i = 0; i < v.size(); i++)
        if (v[i].data > k) ans.push_back(v[i]);
    for (int i = 0; i < ans.size() - 1; i++)
        printf("%05d %d %05d\n", ans[i].id, ans[i].data, ans[i + 1].id);
    printf("%05d %d -1\n", ans[ans.size() - 1].id, ans[ans.size() - 1].data);
    return 0;
}