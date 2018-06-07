1063. Set Similarity (25)
Given two sets of integers, the similarity of the sets is defined to be Nc/Nt*100%, where Nc is the number of distinct common numbers shared by the two sets, and Nt is the total number of distinct numbers in the two sets. Your job is to calculate the similarity of any given pair of sets.
Input Specification:
Each input file contains one test case. Each case first gives a positive integer N (<=50) which is the total number of sets. Then N lines follow, each gives a set with a positive M (<=104) and followed by M integers in the range [0, 109]. After the input of sets, a positive integer K (<=2000) is given, followed by K lines of queries. Each query gives a pair of set numbers (the sets are numbered from 1 to N). All the numbers in a line are separated by a space.
Output Specification:
For each query, print in one line the similarity of the sets, in the percentage form accurate up to 1 decimal place.
Sample Input:
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
Sample Output:
50.0%
33.3%

题目大意：给定两个整数集合，它们的相似度定义为：Nc/Nt*100%。其中Nc是两个集合都有的不相等整数的个数，Nt是两个集合一共有的不相等整数的个数。你的任务就是计算任意一对给定集合的相似度。
nc是两个集合的公共元素个数，nt是两个集合的所有包含的元素个数（其中元素个数表示各个元素之间互不相同）。

分析：因为给出的集合里面含有重复的元素，而计算nc和nt不需要考虑两个集合里面是否分别有重复的元素，所以可以直接使用set存储每一个集合，然后把set放进一个数组里面存储。当需要计算集合a和集合b的相似度nc和nt的时候，遍历集合a中的每一个元素，寻找集合b中是否有该元素，如果有，说明是两个人公共的集合元素，则nc++，否则nt++（nt的初值为b集合里面本有的元素）。

#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
    int n, m, k, temp, a, b;
    scanf("%d", &n);
    vector<set<int>> v(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &m);
        set<int> s;
        for(int j = 0; j < m; j++) {
            scanf("%d", &temp);
            s.insert(temp);
        }
        v[i] = s;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d %d", &a, &b);
        int nc = 0, nt = v[b-1].size();
        for(auto it = v[a-1].begin(); it != v[a-1].end(); it++) {
            if(v[b-1].find(*it) == v[b-1].end()) {
                nt++;
            } else {
                nc++;
            }
        }
        double ans = (double)nc / nt * 100;
        printf("%.1f%%\n", ans);
    }
    return 0;
}