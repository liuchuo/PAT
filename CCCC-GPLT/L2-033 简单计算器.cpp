#include <bits/stdc++.h>
using namespace std;
int n, In[1000], Sum;
char oper, Record[100];
int main() {
    cin >> n;
    for (int i = n - 1; i >= 0; i--) cin >> In[i];
    for (int i = n - 1; i > 0; i--) cin >> Record[i];
    Sum = In[0];
    for (int i = 1; i < n; i++) {
        oper = Record[i];
        if (oper == '+') Sum = In[i] + Sum;
        else if (oper == '-') Sum = In[i] - Sum; 
        else if (oper == '*') Sum = In[i] * Sum;
        else {
            if (Sum == 0) {
                cout << "ERROR: " << In[i] << "/0";
                return 0;
            }
            Sum = In[i] / Sum;
        }
    }
    cout << (int)Sum;
    return 0;
}