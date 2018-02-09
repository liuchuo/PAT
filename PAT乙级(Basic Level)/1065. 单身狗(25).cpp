1065. 单身狗(25)
“单身狗”是中文对于单身人士的一种爱称。本题请你从上万人的大型派对中找出落单的客人，以便给予特殊关爱。
输入格式：
输入第一行给出一个正整数N（<=50000），是已知夫妻/伴侣的对数；随后N行，每行给出一对夫妻/伴侣——为方便起见，每人对应一个ID号，为5位数字（从00000到99999），ID间以空格分隔；之后给出一个正整数M（<=10000），为参加派对的总人数；随后一行给出这M位客人的ID，以空格分隔。题目保证无人重婚或脚踩两条船。
输出格式：
首先第一行输出落单客人的总人数；随后第二行按ID递增顺序列出落单的客人。ID间用1个空格分隔，行的首尾不得有多余空格。
输入样例：
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
输出样例：
5
10000 23333 44444 55555 88888

分析： 设立数组couple[i] = j表示i的对象是j。一开始先设置为都是-1。设立数组isExist表示某人的对象是否来到了派对上。接收数据的时候，对于每一对a和b，将couple的a设置为b，b设置为a，表示他俩是一对。对于每一个需要判断的人，将其存储在guest数组里面，如果它不是单身的（也就是如果它的couple[guest[i]] != -1）那么就将它对象的isExist设置为1，表示他对象的对象（也就是他自己）来到了派对。这样所有isExist不为1的人，对象是没有来到派对的。把所有的人遍历后插入一个集合set里面，set的size就是所求的人数，set里面的所有数就是所求的人的递增排列。

#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
    int n, a, b, m;
    scanf("%d", &n);
    vector<int> couple(100000, -1);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        couple[a] = b;
        couple[b] = a;
    }
    scanf("%d", &m);
    vector<int> guest(m), isExist(100000);
    for (int i = 0; i < m; i++) {
        scanf("%d", &guest[i]);
        if (couple[guest[i]] != -1)
            isExist[couple[guest[i]]] = 1;
    }
    set<int> s;
    for (int i = 0; i < m; i++) {
        if (!isExist[guest[i]])
            s.insert(guest[i]);
    }
    printf("%d\n", s.size());
    for (auto it = s.begin(); it != s.end(); it++) {
        if (it != s.begin()) printf(" ");
        printf("%05d", *it);
    }
    return 0;
}