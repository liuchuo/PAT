#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, cnt = 0;
// cbt is Complete Binary Search Tree
vector<int> in, cbt;
void inOrder(int index) {
    if (index >= n) return;
    inOrder(2 * index + 1);
    cbt[index] = in[cnt++];
    inOrder(2 * index + 2);
}
int main() {
    cin >> n;
    in.resize(n);
    cbt.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    sort(in.begin(), in.end());
    inOrder(0);
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", cbt[i]);
    }
    return 0;
}
