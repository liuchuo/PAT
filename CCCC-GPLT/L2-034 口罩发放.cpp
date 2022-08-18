#include <bits/stdc++.h>
using namespace std;
struct node {
    string name, id, Time;
    int illness, order;
};
bool isIllegal(const string &ss) {
    if (ss.size() != 18) return true;
    for (char i:ss) if (i < '0' || i > '9') return true;
    return false;
}
bool cmp (const node &a,const node &b) {
    if (a.Time != b.Time) return a.Time < b.Time;
    return a.order < b.order;
}
vector<node> Record, ill;
int D, P, t, s, providedNum;
map<string, int> lastGet;
set<string> gotten;
int main() {
    cin >> D >> P;
    for (int i = 1; i <= D; i++) {
        cin >> t >> s;
        Record.resize(t);
        providedNum = 0;
        for (int j = 0; j < t; j++) {
            cin >> Record[j].name >> Record[j].id >> Record[j].illness >> Record[j].Time;
            Record[j].order = j;
            if (isIllegal(Record[j].id)) Record[j].name = "";
            else {
                if (!lastGet.count(Record[j].id)) lastGet[Record[j].id] = -30;
                if (Record[j].illness == 1 && !gotten.count(Record[j].id)) {
                    ill.push_back(Record[j]);
                    gotten.insert(Record[j].id);
                }
            }
        }
        sort(Record.begin(), Record.end(), cmp);
        for (int j = 0; j < t && providedNum < s; j++) {
            if (Record[j].name != "" && i - lastGet[Record[j].id] > P) {
                lastGet[Record[j].id] = i;
                providedNum++;
                cout << Record[j].name << ' ' << Record[j].id << endl;
            }
        }
    }
    for (node i:ill) cout << i.name << ' ' << i.id << '\n';
    return 0;
}