1142. Maximal Clique (25)
A clique is a subset of vertices of an undirected graph such that every two distinct vertices in the clique are adjacent. A maximal clique is a clique that cannot be extended by including one more adjacent vertex. (Quoted from https://en.wikipedia.org/wiki/Clique_(graph_theory))
Now it is your job to judge if a given subset of vertices can form a maximal clique.
Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers Nv (<= 200), the number of vertices in the graph, and Ne, the number of undirected edges. Then Ne lines follow, each gives a pair of vertices of an edge. The vertices are numbered from 1 to Nv.
After the graph, there is another positive integer M (<= 100). Then M lines of query follow, each first gives a positive number K (<= Nv), then followed by a sequence of K distinct vertices. All the numbers in a line are separated by a space.
Output Specification:
For each of the M queries, print in a line "Yes" if the given subset of vertices can form a maximal clique; or if it is a clique but not a maximal clique, print "Not Maximal"; or if it is not a clique at all, print "Not a Clique".
Sample Input:
8 10
5 6
7 8
6 4
3 6
4 5
2 3
8 2
2 7
5 3
3 4
6
4 5 4 3 6
3 2 8 7
2 2 3
1 1
3 4 3 6
3 3 2 1
Sample Output:
Yes
Yes
Yes
Yes
Not Maximal
Not a Clique

题目大意：clique是一个点集，在一个无向图中，这个点集中任意两个不同的点之间都是相连的。maximal clique是一个clique，这个clique不可以再加入任何一个新的结点构成新的clique。点编号从1～nv，给出ne条边，以一对结点编号的方式给出。然后给出m条询问，每个询问是一个点集合，问这个点集合是否是maximal clique、是否是clique～
分析：先判断是否是clique，即判断是否任意两边都相连；之后判断是否是maximal，即遍历所有不在集合中的剩余的点，看是否存在一个点满足和集合中所有的结点相连，最后如果都满足，那就输出Yes表示是Maximal clique～

#include <iostream>
#include <vector>
using namespace std;
int e[210][210];
int main() {
    int nv, ne, m, ta, tb, k;
    scanf("%d %d", &nv, &ne);
    for (int i = 0; i < ne; i++) {
        scanf("%d %d", &ta, &tb);
        e[ta][tb] = e[tb][ta] = 1;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        vector<int> v(k);
        int hash[210] = {0}, isclique = 1, isMaximal = 1;
        for (int j = 0; j < k; j++) {
            scanf("%d", &v[j]);
            hash[v[j]] = 1;
        }
        for (int j = 0; j < k; j++) {
            if (isclique == 0) break;
            for (int l = j + 1; l < k; l++) {
                if (e[v[j]][v[l]] == 0) {
                    isclique = 0;
                    printf("Not a Clique\n");
                    break;
                }
            }
        }
        if (isclique == 0) continue;
        for (int j = 1; j <= nv; j++) {
            if (hash[j] == 0) {
                for (int l = 0; l < k; l++) {
                    if (e[v[l]][j] == 0) break;
                    if (l == k - 1) isMaximal = 0;
                }
            }
            if (isMaximal == 0) {
                printf("Not Maximal\n");
                break;
            }
        }
        if (isMaximal == 1) printf("Yes\n");
    }
    return 0;
}