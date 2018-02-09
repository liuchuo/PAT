1118. Birds in Forest (25)
Some scientists took pictures of thousands of birds in a forest. Assume that all the birds appear in the same picture belong to the same tree. You are supposed to help the scientists to count the maximum number of trees in the forest, and for any pair of birds, tell if they are on the same tree.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive number N (<= 104) which is the number of pictures. Then N lines follow, each describes a picture in the format:
K B1 B2 ... BK
where K is the number of birds in this picture, and Bi's are the indices of birds. It is guaranteed that the birds in all the pictures are numbered continuously from 1 to some number that is no more than 104.
After the pictures there is a positive number Q (<= 104) which is the number of queries. Then Q lines follow, each contains the indices of two birds.
Output Specification:
For each test case, first output in a line the maximum possible number of trees and the number of birds. Then for each query, print in a line "Yes" if the two birds belong to the same tree, or "No" if not.
Sample Input:
4
3 10 1 2
2 3 4
4 1 5 7 8
3 9 6 4
2
10 5
3 7
Sample Output:
2 10
Yes
No

题目大意：一幅画里面的鸟为同一棵树上的，问有多少棵树和多少只鸟，以及对于两只鸟判断是否在同一个树上~
分析：使用并查集就可以啦~将一幅画中鸟使用Union函数合并在同一个集合里面，cnt[i]数组保存以i为FindFather结点的集合里面的鸟的个数，exist[i]表示鸟的id——i在输入的鸟的序号里面是否出现过，遍历cnt数组并累加所有不为0的个数即可得知有多少棵树，累加所有出现过的鸟的id的cnt的值即可得知鸟的个数~~判断两只鸟是否在同一棵树，只需要知道这两只鸟的findFather是否相等即可~~


#include <iostream>
using namespace std;
int n, m, k;
const int maxn = 10010;
int fa[maxn] = {0}, cnt[maxn] = {0};
int findFather(int x) {
    int a = x;
    while(x != fa[x]) {
        x = fa[x];
    }
    while(a != fa[a]) {
        int z = a;
        a = fa[a];
        fa[z] = x;
    }
    return x;
}
void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) {
        fa[faA] = faB;
    }
}
bool exist[maxn];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= maxn; i++) {
        fa[i] = i;
    }
    int id, temp;
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &k, &id);
        exist[id] = true;
        for(int j = 0; j < k-1; j++) {
            scanf("%d", &temp);
            Union(id, temp);
            exist[temp] = true;
        }
    }
    for(int i = 1; i <= maxn; i++) {
        if(exist[i] == true) {
            int root = findFather(i);
            cnt[root]++;
        }

    }
    int numTrees = 0, numBirds = 0;
    for(int i = 1; i <= maxn; i++) {
        if(exist[i] == true && cnt[i] != 0) {
            numTrees++;
            numBirds += cnt[i];
        }
    }
    printf("%d %d\n", numTrees, numBirds);
    scanf("%d", &m);
    int ida, idb;
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &ida, &idb);
        if(findFather(ida) == findFather(idb)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
