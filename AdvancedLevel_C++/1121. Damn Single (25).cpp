1121. Damn Single (25)
“Damn Single (单身狗)” is the Chinese nickname for someone who is being single. You are supposed to find those who are alone in a big party, so they can be taken care of.
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (<=50000), the total number of couples. Then N lines of the couples follow, each gives a couple of ID’s which are 5-digit numbers (i.e. from 00000 to 99999). After the list of couples, there is a positive integer M (<=10000) followed by M ID’s of the party guests. The numbers are separated by spaces. It is guaranteed that nobody is having bigamous marriage (重婚) or dangling with more than one companion.
Output Specification:
First print in a line the total number of lonely guests. Then in the next line, print their ID’s in increasing order. The numbers must be separated by exactly 1 space, and there must be no extra space at the end of the line.
Sample Input:
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333

Sample Output:
5
10000 23333 44444 55555 88888

分析： 设立数组couple[i] = j表示i的对象是j。一开始先设置为都是-1。设立数组isExist表示某人的对象是否来到了派对上。接收数据的时候，对于每一对a和b，将couple的a设置为b，b设置为a，表示他俩是一对。对于每一个需要判断的人，将其存储在guest数组里面，如果它不是单身的（也就是如果它的couple[guest[i]] != -1）那么就将它对象的isExist设置为1，表示他对象的对象（也就是他自己）来到了派对。这样所有isExist不为1的人，对象是没有来到派对的。把所有的人遍历后插入一个集合set里面，set的size就是所求的人数，set里面的所有数就是所求的人的递增排列。

#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
    int n, a, b, m;
    scanf("%d", &n);
    vector<int> couple(100000);
    for (int i = 0; i < 100000; i++)
        couple[i] = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        couple[a] = b;
        couple[b] = a;
    }
    scanf("%d", &m);
    vector<int> guest(m), isExist(100000);
    for (int i = 0; i < m; i++) {
        scanf("%d", &guest[i]);
        if (couple[guest[i]] != -1) {
            isExist[couple[guest[i]]] = 1;
        }
    }
    set<int> s;
    for (int i = 0; i < m; i++) {
        if (!isExist[guest[i]]) {
            s.insert(guest[i]);
        }
    }
    printf("%d\n", s.size());
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        if (it != s.begin())
            printf(" ");
        printf("%05d", *it);
    }
    return 0;
}