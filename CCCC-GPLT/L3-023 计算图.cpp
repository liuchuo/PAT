#include <bits/stdc++.h>
using namespace std;
struct node {
    int which, op1, op2;
    double value;
}A[50001];
int N, start = -1, cnt, de[50001];
map<bool, map<int, map<int, double>>> Record;
double deal(int c, int index, int to) {
    if (Record[c][index][to]) return Record[c][index][to];
    if (A[index].which == 0) return Record[c][index][to] = c ? (index == to ? 1.0 : 0.0) : A[index].value;
    else if (A[index].which == 1) return Record[c][index][to] = deal(c, A[index].op1, to) + deal(c, A[index].op2, to);
    else if (A[index].which == 2) return Record[c][index][to] = deal(c, A[index].op1, to) - deal(c, A[index].op2, to);
    else if (A[index].which == 3) return Record[c][index][to] = c ? (deal(1, A[index].op1, to) * deal(0, A[index].op2, to) + deal(0, A[index].op1, to) * deal(1, A[index].op2, to)) : (deal(0, A[index].op1, to) * deal(0, A[index].op2, to));
    else if (A[index].which == 4) return Record[c][index][to] = c ? exp(deal(0, A[index].op1, to)) * deal(1, A[index].op1, to) : exp(deal(0, A[index].op1, to));
    else if (A[index].which == 5) return Record[c][index][to] = c ? 1.0 / deal(0, A[index].op1, to) * deal(1, A[index].op1, to) : log(deal(0, A[index].op1, to));
    else  return Record[c][index][to] = c ? cos(deal(0, A[index].op1, to)) * deal(1, A[index].op1, to) : sin(deal(0, A[index].op1, to));
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i].which);
        if (A[i].which == 0) {
            ++cnt;
            scanf("%lf", &A[i].value);
        } else if (A[i].which < 4) {
            scanf("%d%d", &A[i].op1, &A[i].op2);
            de[A[i].op1] = de[A[i].op2] = 1;
        } else {
            scanf("%d", &A[i].op1);
            de[A[i].op1] = 1;
        }
    }
    while(de[++start]);
    printf("%.3lf\n", deal(0, start, N));
    for (int i = 0; i < N; i++) {
        if (A[i].which == 0) printf("%.3lf%c", deal(1, start, i), --cnt ? ' ' : '\n');
    }
    return 0;
}