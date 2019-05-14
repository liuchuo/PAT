#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    string id, oldest = "999999999999999999";
    unordered_set<string> alumnus;
    int n, m, count = 0;
    cin >> n;
    while (n--) {
        cin >> id;
        alumnus.insert(id);
    }
    cin >> m;
    while (m--) {
        cin >> id;
        if (alumnus.count(id)) {
            count++;
            if (count == 0 || stoi(id.substr(6, 8)) < stoi(oldest.substr(6, 8)))
                oldest = id;
        } else {
            if (count == 0 && stoi(id.substr(6, 8)) < stoi(oldest.substr(6, 8)))
                oldest = id;
        }
    }
    cout << count << endl << oldest << endl;
    return 0;
}