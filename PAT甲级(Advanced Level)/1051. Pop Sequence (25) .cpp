1051. Pop Sequence (25)
Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly. You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.
Input Specification:
Each input file contains one test case. For each case, the first line contains 3 numbers (all no more than 1000): M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked). Then K lines follow, each contains a pop sequence of N numbers. All the numbers in a line are separated by a space.
Output Specification:
For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.
Sample Input:
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
Sample Output:
YES
NO
NO
YES
NO

题目大意：有个容量限制为m的栈，分别把1，2，3，...，n入栈,给出一个系列出栈顺序，问这些出栈顺序是否可能.
分析：按照要求进行模拟。先把输入的序列接收进数组v。然后按顺序1~n把数字进栈，每进入一个数字，判断有没有超过最大范围，超过了就break。如果没超过，设current = 1，从数组的第一个数字开始，看看是否与栈顶元素相等，while相等就一直弹出栈，不相等就继续按顺序把数字压入栈~~~最后根据变量flag的bool值输出yes或者no~~~

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    for(int i = 0; i < k; i++) {
        bool flag = false;
        stack<int> s;
        vector<int> v(n + 1);
        for(int j = 1; j <= n; j++)
            scanf("%d", &v[j]);
        int current = 1;
        for(int j = 1; j <= n; j++) {
            s.push(j);
            if(s.size() > m) break;
            while(!s.empty() && s.top() == v[current]) {
                s.pop();
                current++;
            }
        }
        if(current == n + 1) flag = true;
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}