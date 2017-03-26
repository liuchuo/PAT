L1-035. 情人节
以上是朋友圈中一奇葩贴：“2月14情人节了，我决定造福大家。第2个赞和第14个赞的，我介绍你俩认识…………咱三吃饭…你俩请…”。现给出此贴下点赞的朋友名单，请你找出那两位要请客的倒霉蛋。

输入格式：
输入按照点赞的先后顺序给出不知道多少个点赞的人名，每个人名占一行，为不超过10个英文字母的非空单词，以回车结束。一个英文句点“.”标志输入的结束，这个符号不算在点赞名单里。

输出格式：
根据点赞情况在一行中输出结论：若存在第2个人A和第14个人B，则输出“A and B are inviting you to dinner...”；若只有A没有B，则输出“A is the only one for you...”；若连A都没有，则输出“Momo... No one is for you ...”。

输入样例1：
GaoXZh
Magi
Einst
Quark
LaoLao
FatMouse
ZhaShen
fantacy
latesum
SenSen
QuanQuan
whatever
whenever
Potaty
hahaha
.
输出样例1：
Magi and Potaty are inviting you to dinner...
输入样例2：
LaoLao
FatMouse
whoever
.
输出样例2：
FatMouse is the only one for you...
输入样例3：
LaoLao
.
输出样例3：
Momo... No one is for you ...

分析：接收输入，当输入为"."的时候退出循环～每次接收一个输入就将cnt++，如果当前cnt==2或者==4就将结果保存到string a或者string b中，最后根据cnt不同的值输出不同的结果～

#include <iostream>
using namespace std;
int main() {
    string a, b, str;
    int cnt = 0;
    while(cin >> str) {
        if (str == ".") {
            break;
        }
        cnt++;
        if (cnt == 2) a = str;
        if (cnt == 14) b = str;
    }
    if (cnt >= 14)
        cout << a << " and " << b << " are inviting you to dinner...";
    else if (cnt <= 1)
        cout << "Momo... No one is for you ...";
    else
        cout << a << " is the only one for you...";
    return 0;
}