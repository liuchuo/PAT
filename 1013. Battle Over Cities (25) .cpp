1013. Battle Over Cities (25)
It is vitally important to have all the cities connected by highways in a war. If a city is occupied by the enemy, all the highways from/toward that city are closed. We must know immediately if we need to repair any other highways to keep the rest of the cities connected. Given the map of cities which have all the remaining highways marked, you are supposed to tell the number of highways need to be repaired, quickly.

For example, if we have 3 cities and 2 highways connecting city1-city2 and city1-city3. Then if city1 is occupied by the enemy, we must have 1 highway repaired, that is the highway city2-city3.

Input

Each input file contains one test case. Each case starts with a line containing 3 numbers N (<1000), M and K, which are the total number of cities, the number of remaining highways, and the number of cities to be checked, respectively. Then M lines follow, each describes a highway by 2 integers, which are the numbers of the cities the highway connects. The cities are numbered from 1 to N. Finally there is a line containing K numbers, which represent the cities we concern.

Output

For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.

Sample Input
3 2 3
1 2
1 3
1 2 3
Sample Output
1
0
0

题目大意：给出n个城市之间有相互连接的m条道路，当删除一个城市和其连接的道路的时候，问其他几个剩余的城市至少要添加多少个路线才能让它们重新变为连通图
分析：添加的最少的路线，就是他们的连通分量数-1，因为当a个互相分立的连通分量需要变为连通图的时候，只需要添加a-1个路线，就能让他们相连。所以这道题就是求去除了某个结点之后其他的图所拥有的连通分量数
使用邻接矩阵存储，对于每一个被占领的城市，去除这个城市结点，就是把它标记为已经访问过，这样在深度优先遍历的时候，对于所有未访问的结点进行遍历，就能求到所有的连通分量的个数~~~记得因为有很多个要判断的数据，每一次输入被占领的城市之前要把visit数组置为false~~~~

#include <cstdio>
#include <algorithm>
using namespace std;
int v[1010][1010];
bool visit[1010];
int n;
void dfs(int node) {
    visit[node] = true;
    for(int i = 1; i <= n; i++) {
        if(visit[i] == false && v[node][i] == 1)
            dfs(i);
    }
}
int main() {
    int m, k, a, b;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        v[a][b] = v[b][a] = 1;
    }
    for(int i = 0; i < k; i++) {
        fill(visit, visit + 1010, false);
        scanf("%d", &a);
        int cnt = 0;
        visit[a] = true;
        for(int j = 1; j <= n; j++) {
            if(visit[j] == false) {
                dfs(j);
                cnt++;
            }
        }
        printf("%d\n", cnt - 1);
    }
    return 0;
}