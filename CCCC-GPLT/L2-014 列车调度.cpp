#include <iostream>
#include <set>
using namespace std;
int main() {
    int n, t;
    cin >> n;
    set<int> s;
    s.insert(0);
    for(int i = 0; i < n; i++) {
        cin >> t;
        if(t < *s.rbegin()) {
            s.erase(*(s.upper_bound(t)));
        }
        s.insert(t);
    }
    cout << s.size() - 1;
    return 0;
}