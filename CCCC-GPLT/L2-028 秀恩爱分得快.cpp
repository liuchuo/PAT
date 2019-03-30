L2-028 秀恩爱分得快（25 分）
古人云：秀恩爱，分得快。
互联网上每天都有大量人发布大量照片，我们通过分析这些照片，可以分析人与人之间的亲密度。如果一张照片上出现了 K 个人，这些人两两间的亲密度就被定义为 1/K。任意两个人如果同时出现在若干张照片里，他们之间的亲密度就是所有这些同框照片对应的亲密度之和。下面给定一批照片，请你分析一对给定的情侣，看看他们分别有没有亲密度更高的异性朋友？
输入格式：
输入在第一行给出 2 个正整数：N（不超过1000，为总人数——简单起见，我们把所有人从 0 到 N-1 编号。为了区分性别，我们用编号前的负号表示女性）和 M（不超过1000，为照片总数）。随后 M 行，每行给出一张照片的信息，格式如下：
K P[1] ... P[K]
其中 K（<= 500）是该照片中出现的人数，P[1] ~ P[K] 就是这些人的编号。最后一行给出一对异性情侣的编号 A 和 B。同行数字以空格分隔。题目保证每个人只有一个性别，并且不会在同一张照片里出现多次。
输出格式：
首先输出“A PA”，其中 PA 是与 A 最亲密的异性。如果 PA 不唯一，则按他们编号的绝对值递增输出；然后类似地输出“B PB”。但如果 A 和 B 正是彼此亲密度最高的一对，则只输出他们的编号，无论是否还有其他人并列。
输入样例 1：
10 4
4 -1 2 -3 4
4 2 -3 -5 -6
3 2 4 -5
3 -6 0 2
-3 2
输出样例 1：
-3 2
2 -5
2 -6
输入样例 2：
4 4
4 -1 2 -3 0
2 0 -3
2 2 -3
2 -1 2
-3 2
输出样例 2：
-3 2

分析：1.此题考查的是对 0 -0 的特殊处理。当遇到 0 时候把此人转为1000存储, 所以读数据的时候要以字符串形式读取
2.遍历每张照片，把与男主女主对应的异性亲密度用sum数字累加起来， 并维护maxn[1] maxn[2]， 为男主女主的最亲密值 和ans[1], ans[2]容器，为最亲密异性id。
3.判断男主女主是否互为最亲密，如果是，输出并return 0， 否则分别输出他们的最亲密好友
4.注意输出时候，因为把0当1000存储，会导致0号人排在最后，这是不符题意的，输出之前排个序，让1000排在最前面

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp (int a, int b) {
    if(abs(a) == 1000) return true;
    if(abs(b) == 1000) return false;
    return abs(a) < abs(b);
}
int main(){
    int n, m, num, k, sex[1010] = {0}, love[3];
    double sum[1010] = {0}, maxn[3] = {0} ;
    string s;
    cin >> n >> m;
    vector<vector<int>> v(m), ans(3);
    for(int i = 0; i < m; i++) {
        cin >> k;
        for(int j = 0; j < k; j++){
            cin >> s;
            if(s == "0")  s = "1000";
            if(s == "-0") s = "-1000";
            num = stoi(s);
            sex[abs(num)] = num;
            v[i].push_back(num);
        }
    }
    for(int i = 1; i <= 2; i++) {
        cin >> s;
        if(s == "0")  s = "1000";
        if(s == "-0") s = "-1000";
        love[i] = stoi(s);
    }
    for(int k = 1; k <= 2; k++) {
        for(int i = 0; i < m; i++) {
            int flag = 0;
            for(int j = 0; j < v[i].size(); j++){
                if(v[i][j] == love[k]) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1) {
                for(int j = 0; j < v[i].size(); j++){
                    if(love[k] * v[i][j] < 0)  {
                        sum[(int)abs(v[i][j])] += 1.0 / v[i].size();
                    }
                }
            }
        }
    }
    maxn[1] = maxn[2] = -1;
    for(int k = 1; k <= 2; k++) {
        for(int i = 1; i <= 1000; i++) {
            if(love[k] * sex[i] < 0) {
                if(sum[i] > maxn[k]) {
                    maxn[k] = sum[i];
                    ans[k].clear();
                    ans[k].push_back(sex[i]);
                }else if(sum[i] == maxn[k]) {
                    ans[k].push_back(sex[i]);
                }
            }
        }
    }
    if(maxn[1] == sum[(int)abs(love[2])] && maxn[2] == sum[(int)abs(love[1])]) {
        string s1 = to_string(love[1]), s2 = to_string(love[2]);
        if(love[1] == 1000)  s1 = "0";
        if(love[1] == -1000)  s1 = "-0";
        if(love[2] == 1000)  s2 = "0";
        if(love[2] == -1000)  s2 = "-0";
        cout << s1 << " " << s2 << endl;
        return 0;
    }
    for(int k = 1; k <= 2; k++) {
        sort(ans[k].begin(), ans[k].end(), cmp);
        for(int i = 0; i < ans[k].size(); i++) {
            string s1 = to_string(love[k]), s2 = to_string(ans[k][i]);
            if(love[k] == 1000)  s1 = "0";
            if(love[k] == -1000)  s1 = "-0";
            if(ans[k][i] == 1000)  s2 = "0";
            if(ans[k][i] == -1000)  s2 = "-0";
            cout << s1 << " " << s2 << endl;
        }
    }
    return 0;
}