#include <cstdio>
#include <set>
using namespace std;
int main() {
    int y, n;
    scanf("%d%d", &y, &n);
    for (int i = y; i <= 3012; i++) {
        set<int> s;
        int num = i;
        for (int j = 0; j < 4; j++) {
            s.insert(num % 10);
            num /= 10;
        }
        if (s.size() == n) {
            printf("%d %04d", i - y, i);
            break;
        }
    }
    return 0;
}