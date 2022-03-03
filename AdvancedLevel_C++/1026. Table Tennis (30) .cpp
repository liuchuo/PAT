#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct person {
    int arrive, start, time;
    bool vip;
}tempperson;
struct tablenode {
    int end = 8 * 3600, num;
    bool vip;
};
bool cmp1(person a, person b) {
    return a.arrive < b.arrive;
}
bool cmp2(person a, person b) {
    return a.start < b.start;
}
vector<person> player;
vector<tablenode> table;
void alloctable(int personid, int tableid) {
    if(player[personid].arrive <= table[tableid].end)
        player[personid].start = table[tableid].end;
    else
        player[personid].start = player[personid].arrive;
    table[tableid].end = player[personid].start + player[personid].time;
    table[tableid].num++;
}

// 找到第一个vip用户
int findnextvip(int vipid) {
    vipid++;
    while(vipid < player.size() && !player[vipid].vip) vipid++;
    return vipid;
}
int main() {
    int n, k, m, viptable;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int h, m, s, temptime, flag;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &temptime, &flag);
        tempperson.arrive = h * 3600 + m * 60 + s;
        tempperson.start = 21 * 3600;
        if(tempperson.arrive >= 21 * 3600) continue;
        tempperson.time = temptime <= 120 ? temptime * 60 : 7200;
        tempperson.vip = (flag == 1);
        player.push_back(tempperson);
    }
    scanf("%d%d", &k, &m);
    table.resize(k + 1);
    for(int i = 0; i < m; i++) {
        scanf("%d", &viptable);
        table[viptable].vip = true;
    }
    sort(player.begin(), player.end(), cmp1);
    int i = 0, vipid = -1;
    vipid = findnextvip(vipid);
    while(i < player.size()) {
        int index = -1, minendtime = 999999999;
        // 找到最早结束的桌子
        for(int j = 1; j <= k; j++) {
            if(table[j].end < minendtime) {
                minendtime = table[j].end;
                index = j;
            }
        }
        if(table[index].end >= 21 * 3600) break;
        // 这个vip已经被分配过了
        if(player[i].vip && i < vipid) {
            i++;
            continue;
        }
        // 第一个结束的桌子是vip桌
        if(table[index].vip) {
            // 下一个玩家刚好是vip
            if(player[i].vip) {
                alloctable(i, index);
                if(vipid == i) vipid = findnextvip(vipid);
                i++;
            } else {  //vip桌子空闲了但是下一个不是vip
                // 看看是否有空闲的非vip桌子
                bool flag = true;
                for (int j=1;j<=index;j++){
                    if(!table[j].vip && player[i].arrive >table[j].end){
                        // 分配给普通用户
                        alloctable(i, j);
                        i++;
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    // 最近的vip在桌子结束前到达
                    if(vipid < player.size() && player[vipid].arrive <= table[index].end) {
                        alloctable(vipid, index);
                        vipid = findnextvip(vipid);
                    } else {
                        // 分配给普通用户
                        alloctable(i, index);
                        i++;
                    }
                }

            }
        } else { // 第一个结束的桌子不是vip桌
            if(!player[i].vip) { // 最近到达的用户不是vip，就分配给他
                alloctable(i, index);
                i++;
            } else {//最近的用户是vip
                int vipindex = -1, minvipendtime = 999999999;
                // 看是最快的vip桌哪时候空闲下来
                for(int j = 1; j <= k; j++) {
                    if(table[j].vip && table[j].end < minvipendtime) {
                        minvipendtime = table[j].end;
                        vipindex = j;
                    }
                }
                // vip桌在vip玩家来之前就空闲下来就分配vip桌给vip用户
                if(vipindex != -1 && player[i].arrive >= table[vipindex].end) {
                    alloctable(i, vipindex);
                    if(vipid == i) vipid = findnextvip(vipid);
                    i++;
                } else {
                    alloctable(i, index);
                    if(vipid == i) vipid = findnextvip(vipid);
                    i++;
                }
            }
        }
    }
    sort(player.begin(), player.end(), cmp2);
    for(i = 0; i < player.size() && player[i].start < 21 * 3600; i++) {
        printf("%02d:%02d:%02d ", player[i].arrive / 3600, player[i].arrive % 3600 / 60, player[i].arrive % 60);
        printf("%02d:%02d:%02d ", player[i].start / 3600, player[i].start % 3600 / 60, player[i].start % 60);
        printf("%.0f\n", round((player[i].start - player[i].arrive) / 60.0));
    }
    for(int i = 1; i <= k; i++) {
        if(i != 1) printf(" ");
        printf("%d", table[i].num);
    }
    return 0;
}