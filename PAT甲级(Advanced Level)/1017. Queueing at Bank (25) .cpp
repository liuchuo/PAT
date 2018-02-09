1017. Queueing at Bank (25)
Suppose a bank has K windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. All the customers have to wait in line behind the yellow line, until it is his/her turn to be served and there is a window available. It is assumed that no window can be occupied by a single customer for more than 1 hour.
Now given the arriving time T and the processing time P of each customer, you are supposed to tell the average waiting time of all the customers.
Input Specification:
Each input file contains one test case. For each case, the first line contains 2 numbers: N (<=10000) - the total number of customers, and K (<=100) - the number of windows. Then N lines follow, each contains 2 times: HH:MM:SS - the arriving time, and P - the processing time in minutes of a customer. Here HH is in the range [00, 23], MM and SS are both in [00, 59]. It is assumed that no two customers arrives at the same time.
Notice that the bank opens from 08:00 to 17:00. Anyone arrives early will have to wait in line till 08:00, and anyone comes too late (at or after 17:00:01) will not be served nor counted into the average.
Output Specification:
For each test case, print in one line the average waiting time of all the customers, in minutes and accurate up to 1 decimal place.
Sample Input:
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10
Sample Output:
8.2

题目大意：有n个客户，k个窗口。已知每个客户的到达时间和需要的时长（不超过60min，超过的会被压缩成60min），如果有窗口就依次过去，如果没有窗口就在黄线外等候（黄线外只有一个队伍，先来先服务），求客户的平均等待时长。银行开放时间为8点到17点，再8点之前不开门，8点之前来的人都要等待，在17点后来的人不被服务。
分析：客户结构体node，里面有come为到达时间和time为需要服务的时长。先将所有满足条件的（到来时间点在17点之前的）客户放入数组中，数组的长度就是需要服务的客户的个数。window数组表示某个窗口的结束时间，每一个客户到来的时候，选择最早结束时间的窗口，如果最早结束时间比他还早，那么他一来就能被服务，更新window的值；如果最早结束时间比他晚，他需要等待，累加等待的时间，然后更新window的值。
一开始所有窗口的值都为8点整。对所有客户要先进行排序，按来的时间的早晚排序，之后再先来先服务。因为涉及分钟和秒数，可以把所有时间暂时先化解成秒数的形式，便于计算。如果一个可以被服务的客户都没有，需要直接输出0.0，因为任何数除以0都没有意义。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int come, time;
} tempcustomer;
bool cmp1(node a, node b) {
    return a.come < b.come;
}
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<node> custom;
    for(int i = 0; i < n; i++) {
        int hh, mm, ss, time;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &time);
        if(time > 60)
            time = 60;
        int cometime = hh * 3600 + mm * 60 + ss;
        if(cometime > 61200)
            continue;
        tempcustomer.come = cometime;
        tempcustomer.time = time * 60;
        custom.push_back(tempcustomer);
    }
    sort(custom.begin(), custom.end(), cmp1);
    vector<int> window(k, 28800);
    double result = 0.0;
    for(int i = 0; i < custom.size(); i++) {
        int tempindex = 0, minfinish = window[0];
        for(int j = 1; j < k; j++) {
            if(minfinish > window[j]) {
                minfinish = window[j];
                tempindex = j;
            }
        }
        if(window[tempindex] <= custom[i].come) {
            window[tempindex] = custom[i].come + custom[i].time;
        } else {
            result += (window[tempindex] - custom[i].come);
            window[tempindex] += custom[i].time;
        }
    }
    if(custom.size() == 0)
        printf("0.0");
    else
        printf("%.1f", result / 60.0 / custom.size());
    return 0;
}