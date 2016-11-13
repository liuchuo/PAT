L2-013. 红色警报
战争中保持各个城市间的连通性非常重要。本题要求你编写一个报警程序，当失去一个城市导致国家被分裂为多个无法连通的区域时，就发出红色警报。注意：若该国本来就不完全连通，是分裂的k个区域，而失去一个城市并不改变其他城市之间的连通性，则不要发出警报。

输入格式：

输入在第一行给出两个整数N（0 < N <=500）和M（<=5000），分别为城市个数（于是默认城市从0到N-1编号）和连接两城市的通路条数。随后M行，每行给出一条通路所连接的两个城市的编号，其间以1个空格分隔。在城市信息之后给出被攻占的信息，即一个正整数K和随后的K个被攻占的城市的编号。

注意：输入保证给出的被攻占的城市编号都是合法的且无重复，但并不保证给出的通路没有重复。

输出格式：

对每个被攻占的城市，如果它会改变整个国家的连通性，则输出“Red Alert: City k is lost!”，其中k是该城市的编号；否则只输出“City k is lost.”即可。如果该国失去了最后一个城市，则增加一行输出“Game Over.”。

输入样例：
5 4
0 1
1 3
3 0
0 4
5
1 2 0 4 3
输出样例：
City 1 is lost.
City 2 is lost.
Red Alert: City 0 is lost!
City 4 is lost.
City 3 is lost.
Game Over.
分析：用图的深度优先遍历判断一个图内的连通分量有多少个，标记为cnt，之后对于每一个输入数据，因为城市a被攻占，所以把a的所有路径标注为不可达(0)，再统计连通分量的个数tempcnt，如果tempcnt > cnt + 1，也就是说当现在的连通分量多余以前的连通分量+1的时候，说明改变了图的连通性；（因为城市被攻占本身它城市自己就变成了一个单独的城市，多出来一个连通分量，只要tempcint <= cnt + 1都说明没有改变图的连通性），每一次tempcnt在用完之后把cnt的值更新为tempcnt，保证下一次的判断是建立再已经失去之前这么多城市的基础之上的。
因为题目中说输入保证给出的被攻占的城市编号都是合法的且无重复，所以如果城市失去了n个，就是当前输入的是从0开始的第n-1个数据的时候，就说明Game Over了，最后当if(i == n - 1) printf("Game Over.\n");

#include <cstdio>
#include <algorithm>
using namespace std;
bool visit[510];
int e[510][510], n, m, k;
void dfs(int node) {
    visit[node] = true;
    for(int i = 0; i < n; i++) {
        if(visit[i] == false && e[node][i] == 1)
            dfs(i);
    }
}
int countcnt() {
    int cnt = 0;
    fill(visit, visit + 510, false);
    for(int i = 0; i < n; i++) {
        if(visit[i] == false) {
            dfs(i);
            cnt++;
        }
    }
    return cnt;
}
int main() {
    scanf("%d%d", &n, &m);
    int a, b, city;
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        e[a][b] = e[b][a] = 1;
    }
    int cnt = countcnt();
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d", &city);
        for(int j = 0; j < n; j++) {
            if(e[city][j] == 1) {
                e[city][j] = 0;
                e[j][city] = 0;
            }
        }
        int tempcnt = countcnt();
        if(tempcnt > cnt + 1)
            printf("Red Alert: City %d is lost!\n", city);
        else
            printf("City %d is lost.\n", city);
        cnt = tempcnt;
        if(i == n - 1) printf("Game Over.\n");
    }
    return 0;
}