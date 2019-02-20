#include <iostream>
#include <set>
using namespace std;

int main() {
    int k;
    string str;
    cin >> k >> str;
    set<char> not_stuck;
    int i = 0;
    while (i < str.size()) {
        char c = str[i];
        int count = 0;
        while (str[i] == c && count < k) {
            count++;
            i++;
        }
        if (count != k) not_stuck.insert(c);
    }
    set<char> printed;
    for (auto c : str) {
        if (!not_stuck.count(c) && !printed.count(c)) {
            cout << c;
            printed.insert(c);
        }
    }
    cout << endl;
    for (int i = 0; i < str.size(); i++) {
        cout << str[i];
        if (!not_stuck.count(str[i])) i += k - 1;
    }
    cout << endl;
    return 0;
}