#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int n;
    cin >> n;
    int id, h, m, cnt = 0, sum = 0,  isborr[1010] = {0}, time[1010] = {0};
    char type, temp;
    for(int day = 0; day < n; ) {
        cin >> id >> type >> h >> temp >> m;
        if(id == 0) {
            if(cnt == 0)
                printf("0 0\n");
            else
                printf("%d %d\n", cnt, (int)(1.0 * sum / cnt + 0.5));
            day++;
            cnt = sum = 0;
            memset(isborr, 0, sizeof(isborr));
        }else if(type == 'S') {
            isborr[id] = 1;
            time[id] = h * 60 + m;
        }else if(type == 'E' && isborr[id] == 1) {
            isborr[id] = 0;
            sum += h * 60 + m - time[id];
            cnt++;
        }
    }
    return 0;
}