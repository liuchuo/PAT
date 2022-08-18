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




