L2-007. 家庭房产
给定每个人的家庭成员和其自己名下的房产，请你统计出每个家庭的人口数、人均房产面积及房产套数。

输入格式：

输入第一行给出一个正整数N（<=1000），随后N行，每行按下列格式给出一个人的房产：

编号 父 母 k 孩子1 ... 孩子k 房产套数 总面积

其中 编号 是每个人独有的一个4位数的编号；父 和 母 分别是该编号对应的这个人的父母的编号（如果已经过世，则显示-1）；k（0<=k<=5）是该人的子女的个数；孩子i是其子女的编号。

输出格式：

首先在第一行输出家庭个数（所有有亲属关系的人都属于同一个家庭）。随后按下列格式输出每个家庭的信息：

家庭成员的最小编号 家庭人口数 人均房产套数 人均房产面积

其中人均值要求保留小数点后3位。家庭信息首先按人均面积降序输出，若有并列，则按成员编号的升序输出。

输入样例：
10
6666 5551 5552 1 7777 1 100
1234 5678 9012 1 0002 2 300
8888 -1 -1 0 1 1000
2468 0001 0004 1 2222 1 500
7777 6666 -1 0 2 300
3721 -1 -1 1 2333 2 150
9012 -1 -1 3 1236 1235 1234 1 100
1235 5678 9012 0 1 50
2222 1236 2468 2 6661 6662 1 300
2333 -1 3721 3 6661 6662 6663 1 100
输出样例：
3
8888 1 1.000 1000.000
0001 15 0.600 100.000
5551 4 0.750 100.000

分析：用并查集。分别用两个结构体数组，一个data用来接收数据，接收的时候顺便实现了并查集的操作union，另一个数组ans用来输出最后的答案，因为要计算家庭人数，所以用visit标记所有出现过的结点，对于每个结点的父结点，people++统计人数。标记flag == true，计算true的个数cnt就可以知道一共有多少个家庭。排序后输出前cnt个就是所求答案~~~~~

#include <cstdio>
#include <algorithm>
using namespace std;
struct DATA {
    int id, fid, mid, num, area;
    int cid[10];
}data[1005];
struct node {
    int id, people;
    double num, area;
    bool flag = false;
}ans[10000];
int father[10000];
bool visit[10000];
int find(int x) {
    while(x != father[x])
        x = father[x];
    return x;
}
void Union(int a, int b) {
    int faA = find(a);
    int faB = find(b);
    if(faA > faB)
        father[faA] = faB;
    else if(faA < faB)
        father[faB] = faA;
}
int cmp1(node a, node b) {
    if(a.area != b.area)
        return a.area > b.area;
    else
        return a.id < b.id;
}
int main() {
    int n, k, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < 10000; i++)
        father[i] = i;
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &data[i].id, &data[i].fid, &data[i].mid, &k);
        visit[data[i].id] = true;
        if(data[i].fid != -1) {
            visit[data[i].fid] = true;
            Union(data[i].fid, data[i].id);
        }
        if(data[i].mid != -1) {
            visit[data[i].mid] = true;
            Union(data[i].mid, data[i].id);
        }
        for(int j = 0; j < k; j++) {
            scanf("%d", &data[i].cid[j]);
            visit[data[i].cid[j]] = true;
            Union(data[i].cid[j], data[i].id);
        }
        scanf("%d %d", &data[i].num, &data[i].area);
    }
    for(int i = 0; i < n; i++) {
        int id = find(data[i].id);
        ans[id].id = id;
        ans[id].num += data[i].num;
        ans[id].area += data[i].area;
        ans[id].flag = true;
    }
    for(int i = 0; i < 10000; i++) {
        if(visit[i])
            ans[find(i)].people++;
        if(ans[i].flag)
            cnt++;
    }
    for(int i = 0; i < 10000; i++) {
        if(ans[i].flag) {
            ans[i].num = (double)(ans[i].num * 1.0 / ans[i].people);
            ans[i].area = (double)(ans[i].area * 1.0 / ans[i].people);
        }
    }
    sort(ans, ans + 10000, cmp1);
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++)
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people, ans[i].num, ans[i].area);
    return 0;
}
