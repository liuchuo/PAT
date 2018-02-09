1055. The World's Richest (25)
Forbes magazine publishes every year its list of billionaires based on the annual ranking of the world's wealthiest people. Now you are supposed to simulate this job, but concentrate only on the people in a certain range of ages. That is, given the net worths of N people, you must find the M richest people in a given range of their ages.
Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=105) - the total number of people, and K (<=103) - the number of queries. Then N lines follow, each contains the name (string of no more than 8 characters without space), age (integer in (0, 200]), and the net worth (integer in [-106, 106]) of a person. Finally there are K lines of queries, each contains three positive integers: M (<= 100) - the maximum number of outputs, and [Amin, Amax] which are the range of ages. All the numbers in a line are separated by a space.
Output Specification:
For each query, first print in a line Case #X: where X is the query number starting from 1. Then output the M richest people with their ages in the range [Amin, Amax]. Each person’s information occupies a line, in the format
Name Age Net_Worth
The outputs must be in non-increasing order of the net worths. In case there are equal worths, it must be in non-decreasing order of the ages. If both worths and ages are the same, then the output must be in non-decreasing alphabetical order of the names. It is guaranteed that there is no two persons share all the same of the three pieces of information. In case no one is found, output "None".
Sample Input:
12 4
Zoe_Bill 35 2333
Bob_Volk 24 5888
Anny_Cin 95 999999
Williams 30 -22
Cindy 76 76000
Alice 18 88888
Joe_Mike 32 3222
Michael 5 300000
Rosemary 40 5888
Dobby 24 5888
Billy 24 5888
Nobody 5 0
4 15 45
4 30 35
4 5 95
1 45 50
Sample Output:
Case #1:
Alice 18 88888
Billy 24 5888
Bob_Volk 24 5888
Dobby 24 5888
Case #2:
Joe_Mike 32 3222
Zoe_Bill 35 2333
Williams 30 -22
Case #3:
Anny_Cin 95 999999
Michael 5 300000
Alice 18 88888
Cindy 76 76000
Case #4:
None

题目大意：给出n个人的姓名，年龄和拥有的钱，让步进行k次查询，每次查询输出在年龄区间内的财富值的从大到小的前m个人的信息。如果财富值相同就就先输出年龄小的，如果年龄相同就把名字按照字典序排序输出
分析：不能先排序然后根据没一个条件再新建一个数组，对新数组排序的方法，这样测试点2会超时~~~因为n和m的悬殊太大了，n有10的5次方，m却只有100个。所以先把所有的人按照财富值排序，再建立一个数组book标记每个年龄段拥有的人的数量，遍历数组并统计相应年龄的人数，当当前年龄的人的数量不超过100的时候压入新的数组，否则就不要压入新的数组。因为无论怎样的年龄区间，查询人数都不会超过100个人，所以最多只要取每个年龄的前100个财富值的人到新的数组里面就可，再从这个新的数组里面取符合相应年龄的人的信息~~~~

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
struct node {
    char name[10];
    int age;
    int money;
};
int cmp1(node a, node b) {
    if(a.money != b.money)
        return a.money > b.money;
    else if(a.age != b.age)
        return a.age < b.age;
    else
        return (strcmp(a.name, b.name) < 0);
}

int main() {
    int n, k, num, amin, amax;
    scanf("%d %d", &n, &k);
    vector<node> vt(n), v;
    vector<int> book(205, 0);
    for(int i = 0; i < n; i++) {
        scanf("%s %d %d", vt[i].name, &vt[i].age, &vt[i].money);
    }
    sort(vt.begin(), vt.end(), cmp1);
    for(int i = 0; i < n; i++) {
        if(book[vt[i].age] < 100) {
            v.push_back(vt[i]);
            book[vt[i].age]++;
        }
    }
    for(int i = 0; i < k; i++) {
        scanf("%d %d %d", &num, &amin, &amax);
        vector<node> t;
        for(int j = 0; j < v.size(); j++) {
            if(v[j].age >= amin && v[j].age <= amax)
                t.push_back(v[j]);
        }
        if(i != 0) printf("\n");
        printf("Case #%d:", i + 1);
        int flag = 0;
        for(int j = 0; j < num && j < t.size(); j++) {
            printf("\n%s %d %d", t[j].name, t[j].age, t[j].money);
            flag = 1;
        }
        if(flag == 0) printf("\nNone");
    }
    return 0;
}