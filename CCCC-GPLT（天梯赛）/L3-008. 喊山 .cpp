L3-008. 喊山
喊山，是人双手围在嘴边成喇叭状，对着远方高山发出“喂—喂喂—喂喂喂……”的呼唤。呼唤声通过空气的传递，回荡于深谷之间，传送到人们耳中，发出约定俗成的“讯号”，达到声讯传递交流的目的。原来它是彝族先民用来求援呼救的“讯号”，慢慢地人们在生活实践中发现了它的实用价值，便把它作为一种交流工具世代传袭使用。
一个山头呼喊的声音可以被临近的山头同时听到。题目假设每个山头最多有两个能听到它的临近山头。给定任意一个发出原始信号的山头，本题请你找出这个信号最远能传达到的地方。

输入格式：

输入第一行给出3个正整数n、m和k，其中n（<=10000）是总的山头数（于是假设每个山头从1到n编号）。接下来的m行，每行给出2个不超过n的正整数，数字间用空格分开，分别代表可以听到彼此的两个山头的编号。这里保证每一对山头只被输入一次，不会有重复的关系输入。最后一行给出k（<=10）个不超过n的正整数，数字间用空格分开，代表需要查询的山头的编号。

输出格式：

依次对于输入中的每个被查询的山头，在一行中输出其发出的呼喊能够连锁传达到的最远的那个山头。注意：被输出的首先必须是被查询的个山头能连锁传到的。若这样的山头不只一个，则输出编号最小的那个。若此山头的呼喊无法传到任何其他山头，则输出0。

输入样例：
7 5 4
1 2
2 3
3 1
4 5
5 6
1 4 5 7
输出样例：
2
6
4
0

分析：用二维数组，结点push_back的方式存储，因为每次都从1遍历到n会超时，而只要遍历到v[top].size()就不会超时。
用广度优先搜索，level记录当前结点的层数，level为自己的上一层结点的level+1，遇到更大层数的时候就令ans又为最大值，让ans取当层的最小值（在不等于被搜索结点本身的时候）。book记录当前结点有没有被访问过，如果没有被访问过就压入队列中，因为可能重复然后导致无限循环，无法输出~~~


#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> v(10010);
int book[10010];
int main() {
    int n, m, k, a, b;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 0; i < k; i++) {
        scanf("%d", &a);
        queue<int> q;
        fill(book, book + 10010, 0);
        q.push(a);
        int level[10010];
        int ans = 10010, maxlevel = 0;
        book[a] = 1;
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            if(level[top] > maxlevel) {
                maxlevel = level[top];
                ans = 10010;
            }
            if(top != a)
                ans = min(ans, top);
            for(int j = 0; j < v[top].size(); j++) {
                if(book[v[top][j]] == 0) {
                    q.push(v[top][j]);
                    book[v[top][j]] = 1;
                    level[v[top][j]] = level[top] + 1;
                }
            }
        }
        if(ans != 10010) printf("%d\n", ans);
        else printf("0\n");
    }
    return 0;
}