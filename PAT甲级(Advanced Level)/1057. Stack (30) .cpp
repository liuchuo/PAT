1057. Stack (30)
Stack is one of the most fundamental data structures, which is based on the principle of Last In First Out (LIFO). The basic operations include Push (inserting an element onto the top position) and Pop (deleting the top element). Now you are supposed to implement a stack with an extra operation: PeekMedian -- return the median value of all the elements in the stack. With N elements, the median value is defined to be the (N/2)-th smallest element if N is even, or ((N+1)/2)-th if N is odd.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (<= 105). Then N lines follow, each contains a command in one of the following 3 formats:
Push key
Pop
PeekMedian
where key is a positive integer no more than 105.
Output Specification:
For each Push command, insert key into the stack and output nothing. For each Pop or PeekMedian command, print in a line the corresponding returned value. If the command is invalid, print "Invalid" instead.
Sample Input:
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
Sample Output:
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

题目大意：现请你实现一种特殊的堆栈，它多了一种操作叫“查中值”，即返回堆栈中所有元素的中值。对于N个元素，若N是偶数，则中值定义为第N/2个最小元；若N是奇数，则中值定义为第(N+1)/2个最小元。
分析：用树状数组，即求第k = (s.size() + 1) / 2大的数。查询小于等于x的数的个数是否等于k的时候用二分法更快~

#include <iostream>
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










