#include <iostream>
using namespace std;
int main() {
    int num, cnt = 0;
    while(cin >> num) {
        cnt++;
        if(num == 250) {
            cout << cnt;
            break;
       }
    }
    return 0;
}
