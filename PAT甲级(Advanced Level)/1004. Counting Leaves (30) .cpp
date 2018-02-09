1004. Counting Leaves (30)
A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.
Input
Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:
ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.
Output
For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.
The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output "0 1" in a line.
Sample Input
2 1
01 1 02
Sample Output
0 1
题目大意：给出一棵树，问每一层各有多少个叶子结点。
分析：可以用dfs也可以用bfs。
dfs的话，用二维数组保存每一个有孩子结点的结点以及他们的孩子结点，从根结点开始遍历，直到遇到叶子结点，就将当前层数depth的book[depth]++; 标记第depth层拥有的叶子结点数，最后输出
如果用bfs，设立两个数组，第一个level，保存i结点的层数，为了bfs的时候可以让当前结点的层数是它的父结点层数+1，第二个数组book，保存i层所拥有的叶子结点的个数。变量maxlevel保存最大的层数~~

dfs:
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[100];
int book[100], maxdepth = -1;
void dfs(int index, int depth) {
    if(v[index].size() == 0) {
        book[depth]++;
        maxdepth = max(maxdepth, depth);
        return ;
    }
    for(int i = 0; i < v[index].size(); i++)
        dfs(v[index][i], depth + 1);
}
int main() {
    int n, m, k, node, c;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d",&node, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[node].push_back(c);
        }
    }
    dfs(1, 0);
    printf("%d", book[0]);
    for(int i = 1; i <= maxdepth; i++)
        printf(" %d", book[i]);
    return 0;
}


bfs:

#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int level[100], book[100], maxlevel = -1;
vector<int> v[100];
void bfs() {
    queue<int> q;
    q.push(1);
    level[1] = 0;
    while(!q.empty()) {
        int index = q.front();
        q.pop();
        maxlevel = max(level[index], maxlevel);
        if(v[index].size() == 0)
            book[level[index]]++;
        for(int i = 0; i < v[index].size(); i++) {
            q.push(v[index][i]);
            level[v[index][i]] = level[index] + 1;
        }
    }
}
int main() {
    int n, m, k, node, c;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d",&node, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[node].push_back(c);
        }
    }
    bfs();
    printf("%d", book[0]);
    for(int i = 1; i <= maxlevel; i++)
        printf(" %d", book[i]);
    return 0;
}