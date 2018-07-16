L2-019. 悄悄关注
新浪微博上有个“悄悄关注”，一个用户悄悄关注的人，不出现在这个用户的关注列表上，但系统会推送其悄悄关注的人发表的微博给该用户。现在我们来做一回网络侦探，根据某人的关注列表和其对其他用户的点赞情况，扒出有可能被其悄悄关注的人。

输入格式：
输入首先在第一行给出某用户的关注列表，格式如下：

人数N 用户1 用户2 …… 用户N

其中N是不超过5000的正整数，每个“用户i”（i=1, ..., N）是被其关注的用户的ID，是长度为4位的由数字和英文字母组成的字符串，各项间以空格分隔。

之后给出该用户点赞的信息：首先给出一个不超过10000的正整数M，随后M行，每行给出一个被其点赞的用户ID和对该用户的点赞次数（不超过1000），以空格分隔。注意：用户ID是一个用户的唯一身份标识。题目保证在关注列表中没有重复用户，在点赞信息中也没有重复用户。

输出格式：
我们认为被该用户点赞次数大于其点赞平均数、且不在其关注列表上的人，很可能是其悄悄关注的人。根据这个假设，请你按用户ID字母序的升序输出可能是其悄悄关注的人，每行1个ID。如果其实并没有这样的人，则输出“Bing Mei You”。

输入样例1：
10 GAO3 Magi Zha1 Sen1 Quan FaMK LSum Eins FatM LLao
8
Magi 50
Pota 30
LLao 3
Ammy 48
Dave 15
GAO3 31
Zoro 1
Cath 60
输出样例1：
Ammy
Cath
Pota
输入样例2：
11 GAO3 Magi Zha1 Sen1 Quan FaMK LSum Eins FatM LLao Pota
7
Magi 50
Pota 30
LLao 48
Ammy 3
Dave 15
GAO3 31
Zoro 29
输出样例2：
Bing Mei You

分析：将关注的人存储在集合set里，将点赞的人和点赞的次数存储在map中，并统计点赞的平均次数sum / M，遍历map，如果map的值大于平均次数，且在set中找不到该用户名，就输出当前用户名（因为map中的键是已经按照字典序排序过的，所以直接输出就可以），并用flag标记是否有过输出，如果从始至终没有输出，说明没有悄悄关注的人，就输出Bing Mei You～～～

#include <iostream>
#include <map>
#include <set>
using namespace std;
int main() {
    int N, M, sum = 0, cnt, flag = 0;
    string str;
    cin >> N;
    set<string> s;
    for (int i = 0; i < N; i++) {
        cin >> str;
        s.insert(str);
    }
    cin >> M;
    map<string, int> m;
    for (int i = 0; i < M; i++) {
        cin >> str >> cnt;
        m[str] = cnt;
        sum += cnt;
    }
    sum /= M;
    for (auto it : m) {
        if (it.second > sum && s.find(it.first) == s.end()) {
            cout << it.first << endl;
            flag = 1;
        }
    }
    if (flag == 0) cout << "Bing Mei You";
    return 0;
}