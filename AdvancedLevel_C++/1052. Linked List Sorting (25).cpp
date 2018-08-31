#include <iostream>
#include <algorithm>
using namespace std;
struct NODE {
    int address, key, next;
    bool flag;
}node[100000];
int cmp1(NODE a, NODE b) {
    return !a.flag || !b.flag ? a.flag > b.flag : a.key < b.key;
}
int main() {
    int n, cnt = 0, s, a, b, c;
    scanf("%d%d", &n, &s);
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d", &a, &b, &c);
        node[a] = {a, b, c, false};
    }
    for(int i = s; i != -1; i = node[i].next) {
        node[i].flag = true;
        cnt++;
    }
    if(cnt == 0) {
        printf("0 -1");
    } else {
        sort(node, node + 100000, cmp1);
        printf("%d %05d\n", cnt, node[0].address);
        for(int i = 0; i < cnt; i++) {
            printf("%05d %d ", node[i].address, node[i].key);
            if(i != cnt - 1)
                printf("%05d\n", node[i + 1].address);
            else
                printf("-1\n");
        }
    }
    return 0;
}