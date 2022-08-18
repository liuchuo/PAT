#include <bits/stdc++.h>
using namespace std;
#define pis pair<int, string>
int N, M;
string fName, sName, temp;
map<string, pis> Record;
string check(string a, string b) {
    int cnt1 = 0, cnt2;
    while (a != "") {
        cnt2 = 0;
        string b2 = b;
        while (b2 != "") {
            if (a == b2 && (cnt1 < 4 || cnt2 < 4)) return "No\n";
            if (cnt1 >= 4 && cnt2 >= 4) return "Yes\n";
            b2 = Record[b2].second;
            cnt2++;
        }
        a = Record[a].second;
        cnt1++;
    }
    return "Yes\n";
}
int main() {
    cin >> N;
    while(N--){
        cin >> fName >> sName;
        if (sName.back() == 'n') Record[fName] = {1, sName.substr(0, sName.length() - 4)};
        else if (sName.back() == 'r') Record[fName] = {0, sName.substr(0, sName.length() - 7)};
        else if (sName.back() == 'm') Record[fName].first = 1;
        else Record[fName].first = 0;
    }
    cin >> M;
    while(M--){
        cin >> fName >> temp >> sName >> temp;
        if (!Record.count(fName) || !Record.count(sName)) cout << "NA\n";
        else if(Record[fName].first == Record[sName].first) cout << "Whatever\n";
        else cout << check(fName, sName);
    }
    return 0;
}