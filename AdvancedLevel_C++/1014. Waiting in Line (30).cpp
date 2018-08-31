#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node {
    int poptime, endtime;
    queue<int> q;
};
int main() {
    int n, m, k, q, index = 1;
    scanf("%d%d%d%d", &n, &m, &k, &q);
    vector<int> time(k + 1), result(k + 1);
    for(int i = 1; i <= k; i++) {
        scanf("%d", &time[i]);
    }
    vector<node> window(n + 1);
    vector<bool> sorry(k + 1, false);
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(index <= k) {
                window[j].q.push(time[index]);
                if(window[j].endtime >= 540)
                    sorry[index] = true;
                window[j].endtime += time[index];
                if(i == 1)
                    window[j].poptime = window[j].endtime;
                result[index] = window[j].endtime;
                index++;
            }
            
        }
    }
    while(index <= k) {
        int tempmin = window[1].poptime, tempwindow = 1;
        for(int i = 2; i <= n; i++) {
            if(window[i].poptime < tempmin) {
                tempwindow = i;
                tempmin = window[i].poptime;
            }
        }
        window[tempwindow].q.pop();
        window[tempwindow].q.push(time[index]);
        window[tempwindow].poptime +=  window[tempwindow].q.front();
        if(window[tempwindow].endtime >= 540)
            sorry[index] = true;
        window[tempwindow].endtime += time[index];
        result[index] = window[tempwindow].endtime;
        index++;
    }
    for(int i = 1; i <= q; i++) {
        int query, minute;
        scanf("%d", &query);
        minute = result[query];
        if(sorry[query] == true) {
            printf("Sorry\n");
        } else {
            printf("%02d:%02d\n",(minute + 480) / 60, (minute + 480) % 60);
        }
    }
    return 0;
}