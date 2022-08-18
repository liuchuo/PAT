#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int n, m, k, H, M, S, t, table, vtable, cnt, now, nowt, T[100000], V[100000], num[10001], AnsI[10001], AnsO[10001], vip[10001];
map<int, int> Table;
queue<int> Wait, vWait;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d:%d:%d", &H, &M, &S);
        t = H * 3600 + M * 60 + S;
        scanf("%d %d", &T[t], &V[t]);
        T[t] = min(T[t], 120) * 60;
    }
    scanf("%d %d", &m, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &t);
        vip[t] = 1;
    }
    for (int Time = 28800; Time < 75600; Time++, table = vtable = now = 0) {
        if (T[Time] && V[Time]) vWait.push(Time);
        else if (T[Time]) Wait.push(Time);
        for (int i = 1; i <= m; i++) {
            if (Table[i] > 0) Table[i]--;
            if (Table[i] == 0 && vip[i] && vtable == 0) vtable = i;
            if (Table [i] == 0 && table == 0) table = i;
        }
        if (!vWait.empty() && (table || vtable)) {
            now = vWait.front();
            nowt = vtable;
            if (vtable != 0) vWait.pop();
            else {
                nowt = table;
                if (!Wait.empty() && Wait.front() < vWait.front()) {
                    now = Wait.front();
                    Wait.pop();
                } else vWait.pop();
            }
        } else if (!Wait.empty() && (table || vtable)) {
            if (table != 0) nowt = table;
            else nowt = vtable;
            now = Wait.front();
            Wait.pop();
        }
        if (now == 0) continue;
        Table[nowt] = T[now];
        AnsI[cnt] = now;
        AnsO[cnt++] = Time;
        num[nowt]++;
    }
    for (int i = 0; i < cnt; i++)
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", AnsI[i] / 3600, AnsI[i] % 3600 / 60, AnsI[i] % 60, AnsO[i] / 3600, AnsO[i] % 3600 / 60, AnsO[i] % 60, (AnsO[i] - AnsI[i] + 30) / 60);
    for (int i = 1; i <= m; i++) {
        if (i != 1) printf(" ");
        printf("%d", num[i]);
    }
    return 0;
}