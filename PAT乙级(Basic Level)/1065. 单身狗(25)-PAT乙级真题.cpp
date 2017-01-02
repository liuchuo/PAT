1065. 单身狗(25)-PAT乙级真题

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

#include <cstdio>
#include <set>
#include <iterator>

using namespace std;

int main() {

    int n = 0;
    scanf("%d", &n);
    int *couple = new int[100000];
    int *isCoupleAbsent = new int[100000];
    for (int i = 0; i < 100000; i++) {
        couple[i] = -1;
        isCoupleAbsent[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int a = 0, b = 0;
        scanf("%d %dd", &a, &b);
        couple[a] = b;
        couple[b] = a;
    }

    int m = 0;
    scanf("%d", &m);
    int *guest = new int[m];

    for (int i = 0; i < m; i++) {
        scanf("%d", &guest[i]);
        if (couple[guest[i]] != -1) {
            isCoupleAbsent[couple[guest[i]]] = 1;
        }
    }

    set<int> s;
    for (int i = 0; i < m; i++) {
        if (!isCoupleAbsent[guest[i]]) {
            s.insert(guest[i]);
        }
    }

    printf("%d\n", s.size());
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        if (it != s.begin()) {
            printf(" ");
        }
        printf("%05d", *it);
    }
    delete [] isCoupleAbsent;
    delete [] guest;
    delete [] couple;
    return 0;
}