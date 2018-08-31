include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    char c;
    cin >> c;
    //计算行数row，只计算一半的行数，不包括最中间的那个一个符号
    int row = 0;
    for (int i = 1; i < N; i++) {
        if ((2 * i * (i + 2) + 1) > N) {
            row = i - 1;
            break;
        }
    }
    // 打印上半部分
    for (int i = row; i >= 1; i--) {
        for (int k = row - i; k >= 1; k--) {
            cout << " ";
        }
        for (int j = i * 2 + 1; j >= 1; j--) {
            cout << c;
        }
        cout << endl;
    }
    // 打印中间的那个符号
    for (int i = 0; i < row; i++) {
        cout << " ";
    }
    cout << c << endl;
    // 打印下半部分
    for (int i = 1; i <= row; i++) {
        for (int k = row - i; k >= 1; k--) {
            cout << " ";
        }
        for (int j = i * 2 + 1; j >= 1; j--) {
            cout << c;
        }
        cout << endl;
    }
    // 输出还剩下几个符号没有用
        cout << (N - (2 * row * (row + 2) + 1));
    return 0;
}