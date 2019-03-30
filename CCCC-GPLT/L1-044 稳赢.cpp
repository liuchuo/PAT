#include <iostream>
#include <map>
using namespace std;
int main() {
    map<string,string> m;
    m["Bu"] = "JianDao";
    m["JianDao"] = "ChuiZi";
    m["ChuiZi"] = "Bu";
    int k, cnt = 0;
    string s;
    cin >> k;
    while(cin >> s) {
        if(s == "End") return 0;
        cnt++;
        if(cnt % (k + 1) == 0)
            cout << s << endl;
        else 
            cout << m[s] << endl;
    }
    return 0;
}
