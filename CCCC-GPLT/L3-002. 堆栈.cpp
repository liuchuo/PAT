L3-002. 堆栈
大家都知道“堆栈”是一种“先进后出”的线性结构，基本操作有“入栈”（将新元素插入栈顶）和“出栈”（将栈顶元素的值返回并从堆栈中将其删除）。现请你实现一种特殊的堆栈，它多了一种操作叫“查中值”，即返回堆栈中所有元素的中值。对于N个元素，若N是偶数，则中值定义为第N/2个最小元；若N是奇数，则中值定义为第(N+1)/2个最小元。

输入格式：

输入第一行给出正整数N（<= 105）。随后N行，每行给出一个操作指令，为下列3种指令之一：

Push key
Pop
PeekMedian
其中Push表示入栈，key是不超过105的正整数；Pop表示出栈；PeekMedian表示查中值。

输出格式：

对每个入栈指令，将key入栈，并不输出任何信息。对每个出栈或查中值的指令，在一行中打印相应的返回结果。若指令非法，就打印“Invalid”。

输入样例：
17
Pop
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
Pop
Push 5
Push 4
PeekMedian
Pop
Pop
Pop
Pop
输出样例：
Invalid
Invalid
3
2
2
1
2
4
4
5
3
Invalid

分析：如果排序查找的话会超时，用树状数组，即求第k = (s.size() + 1) / 2大的数。查询小于等于x的数的个数是否等于k的时候用二分法更快~

#include <cstdio>
#include <stack>
#define lowbit(i) ((i) & (-i))
const int maxn = 100010;
using namespace std;
int c[maxn];
stack<int> s;
void update(int x, int v) {
    for(int i = x; i < maxn; i += lowbit(i))
        c[i] += v;
}
int getsum(int x) {
    int sum = 0;
    for(int i = x; i >= 1; i -= lowbit(i))
        sum += c[i];
    return sum;
}
void PeekMedian() {
    int left = 1, right = maxn, mid, k = (s.size() + 1) / 2;
    while(left < right) {
        mid = (left + right) / 2;
        if(getsum(mid) >= k)
            right = mid;
        else
            left = mid + 1;
    }
    printf("%d\n", left);
}
int main() {
    int n, temp;
    scanf("%d", &n);
    char str[15];
    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        if(str[1] == 'u') {
            scanf("%d", &temp);
            s.push(temp);
            update(temp, 1);
        } else if(str[1] == 'o') {
            if(!s.empty()) {
                update(s.top(), -1);
                printf("%d\n", s.top());
                s.pop();
            } else {
                printf("Invalid\n");
            }
        } else {
            if(!s.empty())
                PeekMedian();
            else
                printf("Invalid\n");
        }
    }
    return 0;
}

