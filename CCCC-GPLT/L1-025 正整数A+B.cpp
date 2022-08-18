#include <iostream>
#include <cctype>
using namespace std;
bool islegal(string s) {
    if(s.length() == 0)
        return false;
    for(int i = 0; i < s.length(); i++) {
        if(!isdigit(s[i])) return false;
    }
    int temp = stoi(s);
    if(temp < 1 || temp > 1000) return false;
    return true;
}
int main() {
    string a, b;
    string t;
    getline(cin, t);
    for(int i = 0; i < t.length(); i++) {
        if(t[i] == ' ') {
            a = t.substr(0, i);
            b = t.substr(i + 1, t.size()- i - 1);
            break;
        }
    }
    if(!islegal(a)) a = "?";
    if(!islegal(b)) b = "?";
    cout << a << " + " << b << " = ";
    if(a != "?" && b != "?") {
        int atemp = stoi(a), btemp = stoi(b);
        cout << atemp + btemp;
    } else {
        cout << "?";
    }
    return 0;
}