#include <bits/stdc++.h>
using namespace std;
int n, m, t;
vector<int> temp;
map<vector<int>, int> A;
multimap<int, vector<int>, greater<int> > B;
int main() {
    scanf("%d%d", &n, &m);
    temp.resize(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) scanf("%d", &temp[j]);
        A[temp]++;
    }
    for (auto it : A) B.insert({it.second, it.first});
    printf("%d\n", A.size());
    for (auto it : B) {
        printf("%d", it.first);
        for (auto it2 : it.second) printf(" %d", it2);
        printf("\n");
    }
    return 0;
}