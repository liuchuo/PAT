#include <iostream>
#include <map>
#include <set>
using namespace std;
int main() {
    int N, M, sum = 0, cnt, flag = 0;
    string str;
    cin >> N;
    set<string> s;
    for (int i = 0; i < N; i++) {
        cin >> str;
        s.insert(str);
    }
    cin >> M;
    map<string, int> m;
    for (int i = 0; i < M; i++) {
        cin >> str >> cnt;
        m[str] = cnt;
        sum += cnt;
    }
    sum /= M;
    for (auto it : m) {
        if (it.second > sum && s.find(it.first) == s.end()) {
            cout << it.first << endl;
            flag = 1;
        }
    }
    if (flag == 0) cout << "Bing Mei You";
    return 0;
}