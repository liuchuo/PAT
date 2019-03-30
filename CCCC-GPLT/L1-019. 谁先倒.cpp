#include <iostream>
using namespace std;
int main() {
    int jia, yi, n;
    cin >> jia >> yi >> n;
    int cnta = jia, cntb = yi;
    int jiahan, jiahua, yihan, yihua;
    for (int i = 0; i < n; i++) {
        cin >> jiahan >> jiahua >> yihan >> yihua;
        if (jiahan + yihan == jiahua && yihan + jiahan != yihua)
            cnta--;
        if (jiahan + yihan != jiahua && yihan + jiahan == yihua)
            cntb--;
        if(cnta == -1) {
            cout << "A" << endl << yi - cntb;
            break;
        }
        if(cntb == -1) {
            cout << "B" << endl << jia - cnta;
            break;
        }
    }
    return 0;
}