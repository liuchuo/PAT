#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn = 100001;
struct NODE {
    int no, score;
    char name[10];
}node[maxn];
int c;
int cmp1(NODE a, NODE b) {
    if(c == 1) {
        return a.no < b.no;
    } else if(c == 2) {
        if(strcmp(a.name, b.name) == 0) return a.no < b.no;
        return strcmp(a.name, b.name) <= 0;
    } else {
        if(a.score == b.score) return a.no < b.no;
        return a.score <= b.score;
    }
}
int main() {
    int n;
    scanf("%d%d", &n, &c);
    for(int i = 0; i < n; i++)
        scanf("%d %s %d", &node[i].no, node[i].name, &node[i].score);
    sort(node, node + n, cmp1);
    for(int i = 0; i < n; i++)
        printf("%06d %s %d\n", node[i].no, node[i].name, node[i].score);
    return 0;
}