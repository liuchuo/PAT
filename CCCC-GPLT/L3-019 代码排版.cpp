#include <bits/stdc++.h>
using namespace std;
int point, space = 2, mark, tp, cnt, use, temp;
string s;
int Function(int c) {
    if (c == 0) while (s[point] == ' ') point++;
    else if (c == 1) for (int i = 0; i < space; i++) cout << ' ';
    else if (c == 2) {
        if (s.substr(point, 2) == "if" && (s[point + 2] == '(' || s[point + 2] == ' ')) return 2;
        else if (s.substr(point, 3) == "for" && (s[point + 3] == '(' || s[point + 3] == ' ')) return 3;
        else if (s.substr(point, 4) == "else" && (s[point + 4] == '(' || s[point + 4] == ' ')) return 4;
        else if (s.substr(point, 5) == "while" && (s[point + 5] == '(' || s[point + 5] == ' ')) return 5;
    } else if (c == 3) {
        Function(0);
        if (Function(2) == 4) return 0;
        while (mark) {
            space -= 2;
            Function(1);
            cout << "}\n";
            mark--;
        } 
    }
    return 0;
}
int main() {
    getline(cin, s);
    Function(0);
    for (int i = point; s[i] != ')'; i++) cout << s[i];
    cout << ")\n{\n";
    point = s.find('{') + 1;
    while (1) {
        Function(0);
        temp = Function(2);
        if (s[point] == '{') {
            Function(1);
            cout << "{\n";
            space += 2;
            point++;
        } else if (s[point] == '}') {
            space -= 2;
            Function(1);
            cout << "}\n";
            if (space == 0) return 0;
            Function(3);
            point++;
        } else if (temp) {
            Function(1);
            cout << s.substr(point, temp);
            point += temp;
            if (temp != 4) {
                Function(0);
                tp = point;
                cnt = 0;
                while(tp < s.size()) {
                    if (s[tp] == '(') cnt++;
                    else if (s[tp] == ')') cnt--;
                    tp++;
                    if (cnt == 0) break;
                }
                cout << ' ' << s.substr(point, tp - point);
                point = tp;
            }
            cout <<  " {\n";
            space += 2;
            Function(0);
            if (s[point] != '{') {
                use = 1;
                mark++;
            } else {
                use = 0;
                point++;
            }
        } else {
            Function(1);
            cnt = s.find(';', point);
            cout << s.substr(point, cnt - point + 1) << '\n';
            point = cnt + 1;
            if (use && mark) {
                space -= 2;
                Function(1);
                cout << "}\n";
                mark--;
                Function(3);
            }
        }
    }
    return 0;
}