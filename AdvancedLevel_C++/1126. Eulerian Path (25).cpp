1126. Eulerian Path (25)
In graph theory, an Eulerian path is a path in a graph which visits every edge exactly once. Similarly, an Eulerian circuit is an Eulerian path which starts and ends on the same vertex. They were first discussed by Leonhard Euler while solving the famous Seven Bridges of Konigsberg problem in 1736. It has been proven that connected graphs with all vertices of even degree have an Eulerian circuit, and such graphs are called Eulerian. If there are exactly two vertices of odd degree, all Eulerian paths start at one of them and end at the other. A graph that has an Eulerian path but not an Eulerian circuit is called semi-Eulerian. (Cited from https://en.wikipedia.org/wiki/Eulerian_path)
Given an undirected graph, you are supposed to tell if it is Eulerian, semi-Eulerian, or non-Eulerian.
Input Specification:
Each input file contains one test case. Each case starts with a line containing 2 numbers N (<= 500), and M, which are the total number of vertices, and the number of edges, respectively. Then M lines follow, each describes an edge by giving the two ends of the edge (the vertices are numbered from 1 to N).
Output Specification:
For each test case, first print in a line the degrees of the vertices in ascending order of their indices. Then in the next line print your conclusion about the graph -- either "Eulerian", "Semi-Eulerian", or "Non-Eulerian". Note that all the numbers in the first line must be separated by exactly 1 space, and there must be no extra space at the beginning or the end of the line.
Sample Input 1:
7 12
5 7
1 2
1 3
2 3
2 4
3 4
5 2
7 6
6 3
4 5
6 4
5 6
Sample Output 1:
2 4 4 4 4 4 2
Eulerian
Sample Input 2:
6 10
1 2
1 3
2 3
2 4
3 4
5 2
6 3
4 5
6 4
5 6
Sample Output 2:
2 4 4 4 3 3
Semi-Eulerian
Sample Input 3:
5 8
1 2
2 5
5 4
4 1
1 3
3 2
3 4
5 3
Sample Output 3:
3 3 4 3 3
Non-Eulerian

题目大意：如果一个连通图的所有结点的度都是偶数，那么它就是Eulerian，如果除了两个结点的度是奇数其他都是偶数，那么它就是Semi-Eulerian，否则就是Non-Eulerian～
分析：用邻接表存储图，判断每个结点的度是多少即可得到最终结果～注意：图必须是连通图，所以要用一个深搜判断一下连通性，从结点1开始深搜，如果最后发现统计的连通结点个数cnt != n说明是不是连通图，要输出Non-Eulerian～

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > v;
vector<bool> visit;
int cnt = 0;
void dfs(int index) {
    visit[index] = true;
    cnt++;
    for (int i = 0; i < v[index].size(); i++)
        if (visit[v[index][i]] == false)
            dfs(v[index][i]);
}
int main() {
    int n, m, a, b, even = 0;
    scanf("%d%d", &n, &m);
    v.resize(n + 1);
    visit.resize(n + 1);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) printf(" ");
        printf("%d", v[i].size());
        if (v[i].size() % 2 == 0) even++;
    }
    printf("\n");
    dfs(1);
    if (even == n && cnt == n)
        printf("Eulerian");
    else if(even == n - 2 && cnt == n)
        printf("Semi-Eulerian");
    else
        printf("Non-Eulerian");
    return 0;
}