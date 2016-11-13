L2-010. 排座位
布置宴席最微妙的事情，就是给前来参宴的各位宾客安排座位。无论如何，总不能把两个死对头排到同一张宴会桌旁！这个艰巨任务现在就交给你，对任何一对客人，请编写程序告诉主人他们是否能被安排同席。

输入格式：

输入第一行给出3个正整数：N（<= 100），即前来参宴的宾客总人数，则这些人从1到N编号；M为已知两两宾客之间的关系数；K为查询的条数。随后M行，每行给出一对宾客之间的关系，格式为：“宾客1 宾客2 关系”，其中“关系”为1表示是朋友，-1表示是死对头。注意两个人不可能既是朋友又是敌人。最后K行，每行给出一对需要查询的宾客编号。

这里假设朋友的朋友也是朋友。但敌人的敌人并不一定就是朋友，朋友的敌人也不一定是敌人。只有单纯直接的敌对关系才是绝对不能同席的。

输出格式：

对每个查询输出一行结果：如果两位宾客之间是朋友，且没有敌对关系，则输出“No problem”；如果他们之间并不是朋友，但也不敌对，则输出“OK”；如果他们之间有敌对，然而也有共同的朋友，则输出“OK but...”；如果他们之间只有敌对关系，则输出“No way”。

输入样例：
7 8 4
5 6 1
2 7 -1
1 3 1
3 4 1
6 7 -1
1 2 1
1 4 1
2 3 -1
3 4
5 7
2 3
7 2
输出样例：
No problem
OK
OK but...
No way
分析：朋友之间的关系用并查集解决，敌人之间的关系用enemy[a][b] = enemy[b][a] = 1解决，因为朋友之间的朋友也是朋友，是传递关系，而敌人的敌人不一定是敌人，所以只需要用一个二维数组即可标记。

#include <cstdio>
#include <vector>
using namespace std;
vector<int> fri;
int enemy[101][101];
int findfri(int x) {
    while(x != fri[x])
        x = fri[x];
    return x;
}
void Union(int a, int b) {
    int fria = findfri(a);
    int frib = findfri(b);
    if(fria != frib)
        fri[fria] = frib;
}
int main() {
    int n, m, k, a, b, c;
    scanf("%d %d %d", &n, &m, &k);
    fri.resize(n + 1);
    for(int i = 1; i <= n; i++)
        fri[i] = i;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if(c == 1)
            Union(a, b);
        else {
            enemy[a][b] = 1;
            enemy[b][a] = 1;
        }
    }
    for(int i = 0; i < k; i++) {
        scanf("%d %d", &a, &b);
        if(findfri(a) == findfri(b) && enemy[a][b] == 0)
            printf("No problem\n");
        else if(findfri(a) != findfri(b) && enemy[a][b] == 0)
            printf("OK\n");
        else if(findfri(a) == findfri(b) && enemy[a][b] == 1)
            printf("OK but...\n");
        else if(enemy[a][b] == 1)
            printf("No way\n");
    }
    return 0;
}