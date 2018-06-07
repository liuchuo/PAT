1056. Mice and Rice (25)
Mice and Rice is the name of a programming contest in which each programmer must write a piece of code to control the movements of a mouse in a given map. The goal of each mouse is to eat as much rice as possible in order to become a FatMouse.
First the playing order is randomly decided for NP programmers. Then every NG programmers are grouped in a match. The fattest mouse in a group wins and enters the next turn. All the losers in this turn are ranked the same. Every NG winners are then grouped in the next match until a final winner is determined.
For the sake of simplicity, assume that the weight of each mouse is fixed once the programmer submits his/her code. Given the weights of all the mice and the initial playing order, you are supposed to output the ranks for the programmers.
Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers: NP and NG (<= 1000), the number of programmers and the maximum number of mice in a group, respectively. If there are less than NG mice at the end of the player's list, then all the mice left will be put into the last group. The second line contains NP distinct non-negative numbers Wi (i=0,...NP-1) where each Wi is the weight of the i-th mouse respectively. The third line gives the initial playing order which is a permutation of 0,...NP-1 (assume that the programmers are numbered from 0 to NP-1). All the numbers in a line are separated by a space.
Output Specification:
For each test case, print the final ranks in a line. The i-th number is the rank of the i-th programmer, and all the numbers must be separated by a space, with no extra space at the end of the line.
Sample Input:
11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3
Sample Output:
5 5 5 2 5 5 5 3 1 3 5

题目大意：np为老鼠的数量，ng为每组最多g个老鼠。先给出np个老鼠的重量，再给出老鼠的初始顺序（第i名的老鼠是第j号，j从0开始）。每ng个老鼠分为一组，对于每组老鼠，选出最重的那个，晋级下一轮比赛，然后依次再以np个老鼠一组分类，然后选出重量最大的。。。直到只剩下一只老鼠，排名为1.输出为老鼠的排名，这个排名是按照原输入老鼠的顺序输出的。
分析：设立结构体node表示老鼠，里面包括weight重量，index是按照排名后的顺序的老鼠的下标，index0是排名前老鼠的下标。rank是最终要输出的老鼠的排名。
先将所有的老鼠按照排名后的顺序依次放入队列中，对于队列中的每一个老鼠，按照分组后选择最大重量的比赛规则，将每次分组获得第一的老鼠放入队列尾部。此处有一点，如果当前剩下的老鼠可以分为group组，那么这一组里面没有晋级的老鼠排名就是group+1.此处解释一下：
因为对于共有group组的老鼠，每组晋级一个，也就是说最终这一轮能晋级的是group个老鼠，那么没有晋级的所有人就是group+1名，就像有4个人晋级下一轮，那么所有没晋级的这一轮就都是并列第5名。
group的计算方法是：如果当前轮次的人数正好可以被每组ng人的ng整除，那么就有人数/ng个组。如果不能被整除，就有剩下来的一些老鼠分为一组，就是人数/ng + 1组。（这是求得group的方法）
cnt用来控制当前的组内第几个人，如果cnt能够被ng整除了说明已经是下一组了，就cnt = 0；否则cnt不断++，同时将最重的老鼠体重赋值给maxn，最重的老鼠的node赋值给maxnode。
最后将结果结构体w排序，按照先前保存的index0的顺序排序，因为题目要求是必须按照题目所给的输入顺序输出的，排序后即可按序输出。
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int weight;
    int index;
    int rank;
    int index0;
};
bool cmp1(node a, node b) {
    return a.index0 < b.index0;
}
int main() {
    int n, g, num;
    scanf("%d%d", &n, &g);
    vector<int> v(n);
    vector<node> w(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        w[i].weight = v[num];
        w[i].index = i;
        w[i].index0 = num;
    }
    queue<node> q;
    for(int i = 0; i < n; i++)
        q.push(w[i]);
    while(!q.empty()) {
        int size = q.size();
        if(size == 1) {
            node temp = q.front();
            w[temp.index].rank = 1;
            break;
        }
        int group = size / g;
        if(size % g != 0)
            group += 1;
        node maxnode;
        int maxn = -1, cnt = 0;
        for(int i = 0; i < size; i++) {
            node temp = q.front();
            w[temp.index].rank = group + 1;
            q.pop();
            cnt++;
            if(temp.weight > maxn) {
                maxn = temp.weight;
                maxnode = temp;
            }
            if(cnt == g || i == size - 1) {
                cnt = 0;
                maxn = -1;
                q.push(maxnode);
            }
        }
    }
    sort(w.begin(), w.end(), cmp1);
    for(int i = 0; i < n; i++) {
        if(i != 0)
            printf(" ");
        printf("%d", w[i].rank);
    }
    return 0;
}