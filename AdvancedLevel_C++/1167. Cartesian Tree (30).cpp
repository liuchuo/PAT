#include <iostream>
#include <map>
using namespace std;
int n, In[32];
map<int, int> ans;
void deal(int index, int L, int R) {
    if (L > R) return;
    int pos = L;
    for (int i = L + 1; i <= R; i++)
        if (In[i] < In[pos]) pos = i;
    ans[index] = In[pos];
    deal(index << 1, L, pos - 1);
    deal(index << 1 | 1, pos + 1, R);
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> In[i];
    deal(1, 0, n - 1);
    for (auto it : ans) {
        if (it.first != 1) cout << ' ';
        cout << it.second;
    }
    return 0;
}