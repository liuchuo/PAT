#include <bits/stdc++.h>
using namespace std;
int N, M, K, temp, need, num, Stack[1002];
int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        need = 1, num = 1;
        for (int j = 0; j < N; j++) {
            cin >> temp;
            if (temp == need) {
                need++;
                while (Stack[num - 1] == need) need++, num--;
            } else if (num <= M) Stack[num++] = temp;
        }
        printf("%s\n", num == 1 ? "YES" : "NO");
    }
    return 0;
}
