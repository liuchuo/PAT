#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct peo{
    string name;
    int sco;
};
bool cmp(peo a, peo b) {
    if(a.sco != b.sco) return a.sco > b.sco;
    return a.name < b.name;
}
int main(){
    int n, g, k, sum = 0, rank[10001] = {0};
    cin >> n >> g >> k;
    vector<peo> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].name >> v[i].sco;
        if(v[i].sco >= 60) sum += 20;
        if(v[i].sco >= g) sum += 30;
    }
    sort(v.begin(), v.end(), cmp);
    rank[0] = 1;
    for(int i = 1; i < n; i++) {
        if(v[i].sco == v[i-1].sco)
            rank[i] = rank[i-1];
        else
            rank[i] = i + 1;
    }
    cout << sum << endl;
    for(int i = 0; rank[i] <= k && i < n; i++)
        printf("%d %s %d\n", rank[i], v[i].name.c_str(), v[i].sco);
    return 0;
}
