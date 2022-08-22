#include <iostream>
using namespace std;
char a[26][7][5], out[7][100];
string s;
int main() {
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 100; j++)
            out[i][j] = ' ';
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 7; j++)
            for (int k = 0; k < 5; k++)
                cin >> a[i][j][k];
    getchar();
    getline(cin, s);
    for (int i = 0, j, flag = 0; i < s.size(); i++) {
        j = i;
        while (j < s.size() && s[j] >= 'A' && s[j] <= 'Z') j++;
        if (i == j) continue;
        for (int k = i; k < j; k++)
            for (int l = 0; l < 7; l++)
                for (int m = 0; m < 5; m++)
                    out[l][m + (k - i) * 6] = a[s[k] - 'A'][l][m];
        if (flag) cout << '\n';
        for (int k = 0; k < 7; k++) {
            flag = 1;
            for (int l = 0; l < 6 * (j - i) - 1; l++) cout << out[k][l];
            cout << '\n';
        }
        i = j;
    }
    return 0;
}