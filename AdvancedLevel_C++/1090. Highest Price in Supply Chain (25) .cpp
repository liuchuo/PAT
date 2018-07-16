1090. Highest Price in Supply Chain (25)
A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.
Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.
Now given a supply chain, you are supposed to tell the highest price we can expect from some retailers.
Input Specification:
Each input file contains one test case. For each case, The first line contains three positive numbers: N (<=105), the total number of the members in the supply chain (and hence they are numbered from 0 to N-1); P, the price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then the next line contains N numbers, each number Si is the index of the supplier for the i-th member. Sroot for the root supplier is defined to be -1. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print in one line the highest price we can expect from some retailers, accurate up to 2 decimal places, and the number of retailers that sell at the highest price. There must be one space between the two numbers. It is guaranteed that the price will not exceed 1010.
Sample Input:
9 1.80 1.00
1 5 4 4 -1 4 5 3 6
Sample Output:
1.85 2

题目大意：给一棵树，在树根出货物的价格为p，然后没往下走一层，价格增加r%，求所有叶子结点的最高价格，以及这个价格的叶子结点个数。
分析：用二维数组v[i][j]存储，对于每一个结点i，它的孩子结点的下标push_back存储在v[i]中。用深度优先搜索dfs，保存当前结点的下标index以及当前结点所在层数，当当前结点的孩子结点个数为0的时候说明是叶子结点，更新maxdepth和maxnum的值，最后输出。
注意：如果采用保存某个结点的父结点的下标的形式，然后一直遍历到根结点的深度/广度优先，会出现三个超时。因为从叶子结点往上遍历将会把所有路径都走一遍，很多都是重复走的路径，会超时，没有从根结点往下遍历的方式快~~~
记得r是百分比，要除以100之后再计算复利~

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int n, maxdepth = 0, maxnum = 0, temp, root;
vector<int> v[100010];
void dfs(int index, int depth) {
    if(v[index].size() == 0) {
        if(maxdepth == depth)
            maxnum++;
        if(maxdepth < depth) {
            maxdepth = depth;
            maxnum = 1;
        }
        return ;
    }
    for(int i = 0; i < v[index].size(); i++)
        dfs(v[index][i], depth + 1);
}
int main() {
    double p, r;
    scanf("%d %lf %lf", &n, &p, &r);
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if(temp == -1)
            root = i;
        else
            v[temp].push_back(i);
    }
    dfs(root, 0);
    printf("%.2f %d", p * pow(1 + r/100, maxdepth), maxnum);
    return 0;
}