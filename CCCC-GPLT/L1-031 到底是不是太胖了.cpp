#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        float height, weight;
        cin >> height >> weight;
        float stan = (height - 100) * 0.9 * 2;
        if(abs(stan - weight) < stan * 0.1) {
            cout << "You are wan mei!" << endl;
        } else if(stan > weight) {
            cout << "You are tai shou le!" << endl;
        } else {
            cout << "You are tai pang le!" << endl;
        }
    }
    return 0;
}