#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int temp = a, sum = 0;
    while(temp <= b) {
        for(int j = 0; j < 5 && temp <= b; j++) {
            printf("%5d", temp);
            sum += temp;
            temp++;
        }
        cout << endl;
    }
    cout << "Sum = " << sum;
    return 0;
}