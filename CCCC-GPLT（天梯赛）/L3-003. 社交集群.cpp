L3-003. 社交集群
在社交网络平台注册时，用户通常会输入自己的兴趣爱好，以便找到和自己兴趣相投的朋友。有部分兴趣相同的人们就形成了“社交集群”。现请你编写程序，找出所有的集群。
输入格式：
输入的第一行给出正整数N（<=1000），即社交网络中的用户总数（则用户从1到N编号）。随后N行，每行按下列格式列出每个人的兴趣爱好：
Ki: hi[1] hi[2] ... hi[Ki]
其中Ki（>0）是第i个人的兴趣的数量，hi[j]是第i个人的第j项兴趣的编号，编号范围为[1, 1000]内的整数。
输出格式：
首先在第一行输出整个网络中集群的数量，然后在第二行按非递增的顺序输出每个集群中用户的数量。数字间以1个空格分隔，行首尾不得有多余空格。
输入样例：
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
输出样例：
3
4 3 1

题目大意：有n个人，每个人喜欢k个活动，如果两个人有任意一个活动相同，就称为他们处于同一个社交网络。求这n个人一共形成了多少个社交网络。
分析：并查集。先写好init、findFather、Union。
0. 每个社交圈的结点号是人的编号，而不是课程。课程是用来判断是否处在一个社交圈的。
1. course[t]表示任意一个喜欢t活动的人的编号。如果当前的课程t，之前并没有人喜欢过，那么就course[t] = i，i为它自己的编号，表示i为喜欢course[t]的一个人的编号
2. course[t]是喜欢t活动的人的编号，那么findFather(course[t])就是喜欢这个活动的人所处的社交圈子的根结点，合并根结点和当前人的编号的结点i。即Union(i, findFather(course[t]))，把它们处在同一个社交圈子里面
3. isRoot[i]表示编号i的人是不是它自己社交圈子的根结点，如果等于0表示不是根结点，如果不等于0，每次标记isRoot[findFather(i)]++，那么isRoot保存的就是如果当前是根结点，那么这个社交圈里面的总人数
4. isRoot中不为0的编号的个数cnt就是社交圈圈子的个数
5. 把isRoot从大到小排列，输出前cnt个，就是社交圈人数的从大到小的输出顺序

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> father, isRoot;
int cmp1(int a, int b){
    return a > b;
}
int findFather(int x) {
    int a = x;
    while(x != father[x])
        x = father[x];
    while(a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB)
        father[faA] = faB;
}
int main() {
    int n, k, t, cnt = 0;
    int course[1001] = {0};
    scanf("%d", &n);
    father.resize(n + 1);
    isRoot.resize(n + 1);
    for(int i = 1; i <= n; i++)
        father[i] = i;
    for(int i = 1; i <= n; i++) {
        scanf("%d:", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &t);
            if(course[t] == 0)
                course[t] = i;
            Union(i, findFather(course[t]));
        }
    }
    for(int i = 1; i <= n; i++)
        isRoot[findFather(i)]++;
    for(int i = 1; i <= n; i++) {
        if(isRoot[i] != 0)
            cnt++;
    }
    printf("%d\n", cnt);
    sort(isRoot.begin(), isRoot.end(), cmp1);
    for(int i = 0; i < cnt; i++) {
        printf("%d", isRoot[i]);
        if(i != cnt - 1) printf(" ");
    }
    return 0;
}




