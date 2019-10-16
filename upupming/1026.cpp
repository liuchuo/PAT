// 时间的表示方式：一律转换为秒
// 21 点后还没开始玩的人，就不再玩，无需输出
// 排序，根据最早的桌子是不是 VIP 桌进行分类讨论
// 是 VIP 桌，寻找等待队列的第一个 VIP 球员
// 不是 VIP 桌，如果队首的球员是 VIP 球员，找到最早空闲的 VIP 桌子的 vipindex，根据 VIP 球员的到达时间和 vipindex 桌子的空闲时间继续分类讨论

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Person {
    int arrive, start, time;
    bool vip;
} tempPerson;
struct TableNode {
    int end = 8 * 3600, servedNum;
    bool vip;
};

vector<Person> players;
vector<TableNode> tables;

bool cmp1(Person a, Person b) {
    return a.arrive < b.arrive;
}
bool cmp2(Person a, Person b) {
    return a.start < b.start;
}

// 下一个 vip 客户
int findNextVip(int vipid) {
    vipid++;
    while (vipid < players.size() && players[vipid].vip == false) vipid++;
    return vipid;
}
// 将 table 分配给 person
void allocTable(int personId, int tableId) {
    players[personId].start = max(players[personId].arrive, tables[tableId].end);
    tables[tableId].end = players[personId].start + players[personId].time;
    tables[tableId].servedNum++;
}

int main() {
    int n, k, m, viptable;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int h, m, s, tempTime, flag;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &tempTime, &flag);
        tempPerson.arrive = h * 3600 + m * 60 + s;
        tempPerson.start = 21 * 3600;
        // 打烊之后到达，直接舍弃
        if (tempPerson.arrive >= 21 * 3600) continue;
        // 最多玩 2 小时
        tempPerson.time = tempTime <= 120 ? tempTime * 60 : 7200;
        tempPerson.vip = (flag == 1);
        players.push_back(tempPerson);
    }
    cin >> k >> m;
    tables.resize(k + 1);
    for (int i = 0; i < m; i++) {
        cin >> viptable;
        tables[viptable].vip = true;
    }
    // 只能到达时间排序
    sort(players.begin(), players.end(), cmp1);
    int i = 0, vipid = -1;
    vipid = findNextVip(vipid);
    while(i < players.size()) {
        int index = -1, minEndtime = 999999999;
        // 找到最早结束的 table
        for (int j = 1; j <= k; j++) {
            if (tables[j].end < minEndtime) {
                minEndtime = tables[j].end;
                index = j;
            }
        }
        // 打烊之后，直接结束后面的所有操作，因为再没有在 21 点之前空闲的 table 了
        if (minEndtime >= 21 * 3600) break;
        // 已经被满足过的 vip ，忽略
        if (players[i].vip && i < vipid) {
            i++;
            continue;
        }
        // 分类讨论最早空闲的桌子是否是 vip 桌
        if (tables[index].vip) {
            if (players[i].vip) {
                // vip 桌给 vip 客户
                allocTable(i, index);
                if (vipid == i) vipid = findNextVip(vipid);
                i++;
            } else {
                // 下一个 vip 客户在桌子空出来之前到达了
                if (vipid < players.size() && players[vipid].arrive <= tables[index].end) {
                    // vip 桌给下一个 vip 客户
                    allocTable(vipid, index);
                    vipid = findNextVip(vipid);
                } else {
                    // vip 客户没来得及到达，vip 桌给普通用户
                    allocTable(i, index);
                    i++;
                }
            }
        } else {
        // 不是 vip 桌
            // 不是 vip 客户
            if (!players[i].vip) {
                allocTable(i, index);
                i++;
            } else {
            // 是 vip 客户
                int vipindex = -1, minVipEndTime = 999999999;
                // 寻找最早结束的 vip 桌
                for (int j = 1; j <= k; j++) {
                    if (tables[j].vip && tables[j].end < minVipEndTime) {
                        minVipEndTime = tables[j].end;
                        vipindex = j;
                    }
                }
                // 将会有一个 vip table 空出来给他用
                if (vipindex != -1 && players[i].arrive >= minVipEndTime) {
                    allocTable(i, vipindex);
                } else {
                // 只能将这个非 vip 桌给他用了
                    allocTable(i, index);
                }
                if (vipid == i) vipid = findNextVip(vipid);
                i++;
            }
        }
    }

    sort(players.begin(), players.end(), cmp2);
    for(i = 0; i < players.size() && players[i].start < 21 * 3600; i++) {
        printf("%02d:%02d:%02d ", players[i].arrive / 3600, players[i].arrive % 3600 / 60, players[i].arrive % 60);
        printf("%02d:%02d:%02d ", players[i].start / 3600, players[i].start % 3600 / 60, players[i].start % 60);
        printf("%.0f\n", round((players[i].start - players[i].arrive) / 60.0));
    }
    for(int i = 1; i <= k; i++) {
        if(i != 1) printf(" ");
        printf("%d", tables[i].servedNum);
    }
}
