1032. Sharing (25)
To store English words, one method is to use linked lists and store a word letter by letter. To save some space, we may let the words share the same sublist if they share the same suffix. For example, "loading" and "being" are stored as showed in Figure 1.
You are supposed to find the starting position of the common suffix (e.g. the position of "i" in Figure 1).
Input Specification:
Each input file contains one test case. For each case, the first line contains two addresses of nodes and a positive N (<= 105), where the two addresses are the addresses of the first nodes of the two words, and N is the total number of nodes. The address of a node is a 5-digit positive integer, and NULL is represented by -1.
Then N lines follow, each describes a node in the format:
Address Data Next
where Address is the position of the node, Data is the letter contained by this node which is an English letter chosen from {a-z, A-Z}, and Next is the position of the next node.
Output Specification:
For each case, simply output the 5-digit starting position of the common suffix. If the two words have no common suffix, output "-1" instead.
Sample Input 1:
11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010
Sample Output 1:
67890
Sample Input 2:
00001 00002 4
00001 a 10001
10001 s -1
00002 a 10002
10002 t -1
Sample Output 2:
-1

题目大意：求两个链表的首个共同结点的地址。如果没有，就输出-1
分析：用结构体数组存储，node[i]表示地址为i的结点，key表示值，next为下一个结点的地址，flag表示第一条链表有没有该结点
遍历第一条链表，将访问过的结点的flag都标记为true，当遍历第二条结点的时候，如果遇到了true的结点就输出并结束程序，没有遇到就输出-1

#include <iostream>
using namespace std;
struct NODE {
    char key;
    int next;
    bool flag;
}node[100000];
int main() {
    int s1, s2, n, a, b;
    scanf("%d%d%d", &s1, &s2, &n);
    char data;
    for(int i = 0; i < n; i++) {
        scanf("%d %c %d", &a, &data, &b);
        node[a].key = data;
        node[a].next = b;
    }
    for(int i = s1; i != -1; i = node[i].next) {
        node[i].flag = true;
    }
    for(int i = s2; i != -1; i = node[i].next) {
        if(node[i].flag == true) {
            printf("%05d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}