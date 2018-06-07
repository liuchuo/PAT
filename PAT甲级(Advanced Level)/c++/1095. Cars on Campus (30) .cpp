1095. Cars on Campus (30)
Zhejiang University has 6 campuses and a lot of gates. From each gate we can collect the in/out times and the plate numbers of the cars crossing the gate. Now with all the information available, you are supposed to tell, at any specific time point, the number of cars parking on campus, and at the end of the day find the cars that have parked for the longest time period.
Input Specification:
Each input file contains one test case. Each case starts with two positive integers N (<= 10000), the number of records, and K (<= 80000) the number of queries. Then N lines follow, each gives a record in the format
plate_number hh:mm:ss status
where plate_number is a string of 7 English capital letters or 1-digit numbers; hh:mm:ss represents the time point in a day by hour:minute:second, with the earliest time being 00:00:00 and the latest 23:59:59; and status is either in or out.
Note that all times will be within a single day. Each "in" record is paired with the chronologically next record for the same car provided it is an "out" record. Any "in" records that are not paired with an "out" record are ignored, as are "out" records not paired with an "in" record. It is guaranteed that at least one car is well paired in the input, and no car is both "in" and "out" at the same moment. Times are recorded using a 24-hour clock.
Then K lines of queries follow, each gives a time point in the format hh:mm:ss. Note: the queries are given in ascending order of the times.
Output Specification:
For each query, output in a line the total number of cars parking on campus. The last line of output is supposed to give the plate number of the car that has parked for the longest time period, and the corresponding time length. If such a car is not unique, then output all of their plate numbers in a line in alphabetical order, separated by a space.
Sample Input:
16 7
JH007BD 18:00:01 in
ZD00001 11:30:08 out
DB8888A 13:00:00 out
ZA3Q625 23:59:50 out
ZA133CH 10:23:00 in
ZD00001 04:09:59 in
JH007BD 05:09:59 in
ZA3Q625 11:42:01 out
JH007BD 05:10:33 in
ZA3Q625 06:30:50 in
JH007BD 12:23:42 out
ZA3Q625 23:55:00 in
JH007BD 12:24:23 out
ZA133CH 17:11:22 out
JH007BD 18:07:01 out
DB8888A 06:30:50 in
05:10:00
06:30:50
11:00:00
12:23:42
14:00:00
18:00:00
23:59:00
Sample Output:
1
4
5
2
1
0
1
JH007BD ZD00001 07:20:09


题目大意：给出n个车牌号、时间点、进出状态的记录，然后查询k个时间点这时校园内的车辆个数。最后还要输出在校园里面呆的时间最长的车的车牌号，以及呆了多久的时间。如果有多辆车就按照它的字母从小到大输出车牌。
配对要求是，如果一个车多次进入未出，取最后一个值；如果一个车多次out未进入，取第一个值。
注意：一个车可能出入校园好多次，停车的时间应该取之和。
分析：为了简便，应该把小时和分钟都化简成秒数计算比较方便。
一开始所有车辆的id、时间和是进还是出（进的flag是1，出的flag是-1），对他们排序，先按照车牌号排序，再按照来的时间先后排序。
此后就能根据这样的排序后的顺序将所有满足条件（合法）的车辆进出记录保存到另一个数组里面。这个数组再按照时间先后排序。
因为多次询问值，为了避免超时，可以把他们的车辆数cnt数组先算出来。到时候直接取值就会比较快速。cnt[i]表示在i下标的记录的时间点的时候车辆的数量。数量可以由前一个数量+当前车辆的flag得到。
因为问询的时候是多个时间点按照从小到大的顺序，利用好这点能避免超时。如果上一个查询的index已经被记住，那么下一次就只需要从这个index开始找就可以了，避免重复寻找，浪费时间。

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;
struct node {
    char id[10];
    int time;
    int flag = 0;
};
bool cmp1(node a, node b) {
    if(strcmp(a.id, b.id) != 0)
        return strcmp(a.id, b.id) < 0;
    else
        return a.time < b.time;
}
bool cmp2(node a, node b) {
    return a.time < b.time;
}
int main() {
    int n, k, maxtime = -1, tempindex = 0;
    scanf("%d%d\n", &n, &k);
    vector<node> record(n), car;
    for(int i = 0; i < n; i++) {
        char temp[5];
        int h, m, s;
        scanf("%s %d:%d:%d %s\n", record[i].id, &h, &m, &s, temp);
        int temptime = h * 3600 + m * 60 + s;
        record[i].time = temptime;
        record[i].flag = strcmp(temp, "in") == 0 ? 1 : -1;
    }
    sort(record.begin(), record.end(), cmp1);
    map<string, int> mapp;
    for(int i = 0; i < n - 1; i++) {
        if(strcmp(record[i].id, record[i+1].id) == 0 && record[i].flag == 1 && record[i+1].flag == -1) {
            car.push_back(record[i]);
            car.push_back(record[i+1]);
            mapp[record[i].id] += (record[i+1].time - record[i].time);
            if(maxtime < mapp[record[i].id]) {
                maxtime = mapp[record[i].id];
            }
        }
    }
    sort(car.begin(), car.end(), cmp2);
    vector<int> cnt(n);
    for(int i = 0; i < car.size(); i++) {
        if(i == 0)
            cnt[i] += car[i].flag;
         else
            cnt[i] = cnt[i - 1] + car[i].flag;
    }
    for(int i = 0; i < k; i++) {
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        int temptime = h * 3600 + m * 60 + s;
        int j;
        for(j = tempindex; j < car.size(); j++) {
            if(car[j].time > temptime) {
                printf("%d\n", cnt[j - 1]);
                break;
            } else if(j == car.size() - 1) {
                printf("%d\n", cnt[j]);
            }
        }
        tempindex = j;
    }
    for(map<string, int>::iterator it = mapp.begin(); it != mapp.end(); it++) {
        if(it->second == maxtime)
            printf("%s ", it->first.c_str());
    }
    printf("%02d:%02d:%02d", maxtime / 3600, (maxtime % 3600) / 60, maxtime % 60);
    return 0;
}
