1106. Lowest Price in Supply Chain (25)
A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.
Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. Only the retailers will face the customers. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.
Now given a supply chain, you are supposed to tell the lowest price a customer can expect from some retailers.
Input Specification:
Each input file contains one test case. For each case, The first line contains three positive numbers: N (<=105), the total number of the members in the supply chain (and hence their ID’s are numbered from 0 to N-1, and the root supplier’s ID is 0); P, the price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then N lines follow, each describes a distributor or retailer in the following format:
Ki ID[1] ID[2] ... ID[Ki]
where in the i-th line, Ki is the total number of distributors or retailers who receive products from supplier i, and is then followed by the ID’s of these distributors or retailers. Kj being 0 means that the j-th member is a retailer. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print in one line the lowest price we can expect from some retailers, accurate up to 4 decimal places, and the number of retailers that sell at the lowest price. There must be one space between the two numbers. It is guaranteed that the all the prices will not exceed 1010.
Sample Input:
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0
2 6 1
1 8
0
0
0
Sample Output:
1.8362 2

题目大意：提供一棵树，在树根处货物的价格为p，从根结点开始每往下一层，该层货物价格将会在父亲结点的价格上增加r%。求叶子结点出能获得的最低价格以及能提供最低价格的叶子结点数
分析：dfs。保存深度的最小值mindepth，以及最小值下该深度的个数minnum。深度优先搜索参数为index和depth，不断遍历index结点的孩子结点，直到当前结点没有孩子结点为止return~~~~

#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
vector<int> v[100005];
int mindepth = 99999999, minnum = 1;
void dfs(int index, int depth) {
    if(mindepth < depth)
        return ;
    if(v[index].size() == 0) {
        if(mindepth == depth)
            minnum++;
        if(mindepth > depth) {
            mindepth = depth;
            minnum = 1;
        }
        return ;
    }
    for(int i = 0; i < v[index].size(); i++)
        dfs(v[index][i], depth + 1);
}
int main() {
    int n, k, c;
    double p, r;
    scanf("%d %lf %lf", &n, &p, &r);
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[i].push_back(c);
        }
    }
    dfs(0, 0);
    printf("%.4f %d", p * pow(1 + r/100, mindepth), minnum);
    return 0;
}