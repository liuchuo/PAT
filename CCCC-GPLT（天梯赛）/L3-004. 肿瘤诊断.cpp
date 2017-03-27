L3-004. 肿瘤诊断
在诊断肿瘤疾病时，计算肿瘤体积是很重要的一环。给定病灶扫描切片中标注出的疑似肿瘤区域，请你计算肿瘤的体积。

输入格式：

输入第一行给出4个正整数：M、N、L、T，其中M和N是每张切片的尺寸（即每张切片是一个M×N的像素矩阵。最大分辨率是1286×128）；L（<=60）是切片的张数；T是一个整数阈值（若疑似肿瘤的连通体体积小于T，则该小块忽略不计）。

最后给出L张切片。每张用一个由0和1组成的M×N的矩阵表示，其中1表示疑似肿瘤的像素，0表示正常像素。由于切片厚度可以认为是一个常数，于是我们只要数连通体中1的个数就可以得到体积了。麻烦的是，可能存在多个肿瘤，这时我们只统计那些体积不小于T的。两个像素被认为是“连通的”，如果它们有一个共同的切面，如下图所示，所有6个红色的像素都与蓝色的像素连通。


Figure 1
输出格式：

在一行中输出肿瘤的总体积。

输入样例：
3 4 5 2
1 1 1 1
1 1 1 1
1 1 1 1
0 0 1 1
0 0 1 1
0 0 1 1
1 0 1 1
0 1 0 0
0 0 0 0
1 0 1 1
0 0 0 0
0 0 0 0
0 0 0 1
0 0 0 1
1 0 0 0
输出样例：
26

分析：三维的广度优先搜索~~XYZ三个数组判断方向，对每一个点广度优先累计肿瘤块的大小，如果大于等于t就把结果累加。用visit数组标记当前的点有没有被访问过，被访问过的结点是不会再访问的。。judge判断是否超过了边界，或者是否当前结点为0不是肿瘤~~~

#include <cstdio>
#include <queue>
using namespace std;
struct node {
    int x, y, z;
};
int m, n, l, t;
int X[6] = {1, 0, 0, -1, 0, 0};
int Y[6] = {0, 1, 0, 0, -1, 0};
int Z[6] = {0, 0, 1, 0, 0, -1};
int arr[1300][130][80];
bool visit[1300][130][80];
bool judge(int x, int y, int z) {
    if(x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l) return false;
    if(arr[x][y][z] == 0 || visit[x][y][z] == true) return false;
    return true;
}
int bfs(int x, int y, int z) {
    int cnt = 0;
    node temp;
    temp.x = x, temp.y = y, temp.z = z;
    queue<node> q;
    q.push(temp);
    visit[x][y][z] = true;
    while(!q.empty()) {
        node top = q.front();
        q.pop();
        cnt++;
        for(int i = 0; i < 6; i++) {
            int tx = top.x + X[i];
            int ty = top.y + Y[i];
            int tz = top.z + Z[i];
            if(judge(tx, ty, tz)) {
                visit[tx][ty][tz] = true;
                temp.x = tx, temp.y = ty, temp.z = tz;
                q.push(temp);
            }
        }
    }
    if(cnt >= t)
        return cnt;
    else
        return 0;
    
}
int main() {
    scanf("%d %d %d %d", &m, &n, &l, &t);
    for(int i = 0; i < l; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < n; k++)
                scanf("%d", &arr[j][k][i]);
    int ans = 0;
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < n; k++) {
                if(arr[j][k][i] == 1 && visit[j][k][i] == false)
                    ans += bfs(j, k, i);
            }
        }
    }
    printf("%d", ans);
    return 0;
}