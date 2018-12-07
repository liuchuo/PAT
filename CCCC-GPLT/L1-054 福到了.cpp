#include <iostream>
#include <vector>
using namespace std;
int main() {
    char c;
    int n, flag = 0;
    scanf("%c%d",&c, &n);
    getchar();
    vector<string> a(n);
    for(int i = 0; i < n; i++)
        getline(cin,a[i]);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] != a[n-1-i][n-1-j])
                flag = 1;
    if(flag == 0) cout << "bu yong dao le\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[n-1-i][n-1-j] == '@')
                cout << c;
            else
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}

