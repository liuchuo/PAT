#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, sum = 0, cnt = 1, num[110] = {0}, id_school[100001] = {0};
    cin >> n;
    vector<vector<int>> v(n+1);
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    while(1) {
        bool flag = true;
        for(int i = 1; i < v.size(); i++) {
            if(v[i].size() < num[i] * 10) {
                if(id_school[cnt-1] != i) {
                    id_school[cnt] = i;
                    v[i].push_back(cnt);
                    cnt++;
                } else {
                    id_school[cnt+1] = i;
                    v[i].push_back(cnt+1);
                    cnt = cnt + 2;
                }
                flag = false;
            }
        }
        if(flag) break;
    }
    for(int i = 1; i < v.size(); i++) {
        cout << "#" << i << endl;
        for(int j = 0; j < v[i].size(); j++) {
            if(j != 0 && j % 10 != 0) cout << " ";
            if(j != 0 && j % 10 == 0) cout << endl;
            cout << v[i][j];
        }
        cout << endl;
    }
    return 0;
}