#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
    getline(cin, s);
    while (getline(cin, s)) {
        cout << s << '\n' << "AI: ";
        s = regex_replace(s, regex(R"(\s+)"), " ");
        s = regex_replace(s, regex(R"(^\s+|\s+$|\s+(?=\W))"), "");
        s = regex_replace(s, regex(R"(\bI\b)"), "mark_mark");
        for (int i = 0; i < (int)s.size(); i++) if (s[i] != 'I') s[i] = tolower(s[i]);
        s = regex_replace(s, regex(R"(\bcan you\b)"), "I can");
        s = regex_replace(s, regex(R"(\bcould you\b)"), "I could");
        s = regex_replace(s, regex(R"(mark_mark|\bme\b)"), "you");
        s = regex_replace(s, regex(R"(\?)"), "!");
        cout << s << '\n';
    }
    return 0;
}