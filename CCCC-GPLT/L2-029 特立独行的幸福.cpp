#include <bits/stdc++.h>
using namespace std;
int A, B, flag, num[10001], notIndep[10001];
bool isPrime(int a) {
    if (a == 1) return false;
    for (int i = 2; i <= sqrt(a); i++)
        if (a % i == 0) return false;
    return true;
}
bool isIndep(int x) {
    set<int> mark;
    int X = x, temp1, temp2;
    while (X != 1) {
        mark.insert(X);
        temp1 = 0;
        while (X) {
            temp2 = X % 10;
            X /= 10;
            temp1 += temp2 * temp2;
        }
        num[x]++;
        notIndep[temp1] = 1;
        X = temp1;
        if (mark.count(X)) return false;
    } 
    return true;
}
int main() {
    cin >> A >> B;
    vector<int> ans;
    for (int i = A; i <= B; i++)
        if (isIndep(i)) ans.push_back(i);
    for (int i = 0; i < ans.size(); i++) {
        if (isPrime(ans[i])) num[ans[i]] <<= 1;
        if (!notIndep[ans[i]]) {
            cout << ans[i] << ' ' << num[ans[i]] << endl;
            flag = 1;
        }
    }
    if (!flag) cout << "SAD"; 
    return 0;
}