#include <iostream>
using namespace std;
int main() {
    int n, jia = 0, yi = 0,jiahan, jiahua, yihan, yihua;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> jiahan >> jiahua >> yihan >> yihua;
        if (jiahan + yihan == jiahua && yihan + jiahan != yihua)
            yi++;
        if (jiahan + yihan != jiahua && yihan + jiahan == yihua)
            jia++;
    }
    cout << jia << " " << yi;
    return 0;
}