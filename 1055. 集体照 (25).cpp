/*
1055. 集体照 (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
拍集体照时队形很重要，这里对给定的N个人K排的队形设计排队规则如下：

每排人数为N/K（向下取整），多出来的人全部站在最后一排；
后排所有人的个子都不比前排任何人矮；
每排中最高者站中间（中间位置为m/2+1，其中m为该排人数，除法向下取整）；
每排其他人以中间人为轴，按身高非增序，先右后左交替入队站在中间人的两侧（例如5人身高为190、188、186、175、170，则队形为175、188、190、186、170。这里假设你面对拍照者，所以你的左边是中间人的右边）；
若多人身高相同，则按名字的字典序升序排列。这里保证无重名。
现给定一组拍照人，请编写程序输出他们的队形。

输入格式：

每个输入包含1个测试用例。每个测试用例第1行给出两个正整数N（<=10000，总人数）和K（<=10，总排数）。随后N行，每行给出一个人的名字（不包含空格、长度不超过8个英文字母）和身高（[30, 300]区间内的整数）。

输出格式：

输出拍照的队形。即K排人名，其间以空格分隔，行末不得有多余空格。注意：假设你面对拍照者，后排的人输出在上方，前排输出在下方。

输入样例：
10 3
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159
输出样例：
Bob Tom Joe Nick
Ann Mike Eva
Tim Amy John
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct node {
    string name;
    int height;
};

// 从高到矮，名字升序
int cmp(struct node a, struct node b) {
    if(a.height != b.height) {
        return a.height > b.height;
    } else {
        return a.name < b.name;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    struct node *stu = new struct node [n];
    int i, j;
    for(i = 0; i < n; i++) {
        cin >> stu[i].name;
        cin >> stu[i].height;
    }
    sort(stu, stu + n, cmp);
    
    // 最后一排的人数
    int m = n - n / k * (k - 1);
    //处理最后一排
    string *sbehind = new string [m];
    // 最后一排的左边排列
    j = m / 2 - 1;
    sbehind[m / 2] = stu[0].name;
    for(i = 1; i < m; i = i + 2) {
        sbehind[j--] = stu[i].name;
    }
    // 最后一排的右边排列
    j = m / 2 + 1;
    for(i = 2; i < m; i = i + 2) {
        sbehind[j++] = stu[i].name;
    }
    // 输出最后一排
    cout << sbehind[0];
    for(i = 1; i < m; i++) {
        cout << " " << sbehind[i];
    }
    cout << endl;
    delete [] sbehind;
    
    //其他排
    int t = m;
    int row = k - 1;
    while(row) {
        row--;
        m = n / k;
        string *stemp = new string [m];
        stemp[m / 2] = stu[t].name;
        // 左边一列
        j = m / 2 - 1;
        for(i = t + 1; i < t + m; i = i + 2) {
            stemp[j--] = stu[i].name;
        }
        // 右边一列
        j = m / 2 + 1;
        for(i = t + 2; i < t + m; i = i + 2) {
            stemp[j++] = stu[i].name;
        }
        // 输出当前排
        cout << stemp[0];
        for(i = 1; i < m; i++) {
            cout << " " << stemp[i];
        }
        cout << endl;
        t = t + m;
        delete [] stemp;//这句话很重要。。。
    }
    delete [] stu;
    return 0;
}

