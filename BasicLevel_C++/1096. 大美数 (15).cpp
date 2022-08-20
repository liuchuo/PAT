#include <iostream>
using namespace std;
int k, num, flag;
int main() {
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> num;
        flag = 0;
        for (int a = 1; a < num; a++) {
            if (flag == 1) break;
            if (num % a != 0) continue;
            for (int b = a + 1; b < num; b++) {
                if (flag == 1) break;
                if (num % b != 0) continue;
                for (int c = b + 1; c < num; c++) {
                    if (flag == 1) break;
                    if (num % c != 0) continue;
                    for (int d = c + 1; d <= num; d++) {
                        if (num % d != 0) continue;
                        if ((a + b + c + d) % num == 0) {
                            flag = 1;
                            break;
                        }
                    }
                }
            }
        }
        cout << (flag ? "Yes\n" : "No\n");
    }
    return 0;
}