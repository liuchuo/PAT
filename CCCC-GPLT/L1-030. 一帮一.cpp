L1-030. 一帮一
“一帮一学习小组”是中小学中常见的学习组织方式，老师把学习成绩靠前的学生跟学习成绩靠后的学生排在一组。本题就请你编写程序帮助老师自动完成这个分配工作，即在得到全班学生的排名后，在当前尚未分组的学生中，将名次最靠前的学生与名次最靠后的异性学生分为一组。
输入格式：
输入第一行给出正偶数N（<=50），即全班学生的人数。此后N行，按照名次从高到低的顺序给出每个学生的性别（0代表女生，1代表男生）和姓名（不超过8个英文字母的非空字符串），其间以1个空格分隔。这里保证本班男女比例是1:1，并且没有并列名次。
输出格式：
每行输出一组两个学生的姓名，其间以1个空格分隔。名次高的学生在前，名次低的学生在后。小组的输出顺序按照前面学生的名次从高到低排列。
输入样例：
8
0 Amy
1 Tom
1 Bill
0 Cindy
0 Maya
1 John
1 Jack
0 Linda
输出样例：
Amy Jack
Tom Linda
Bill Maya
Cindy John

分析：先把输入数据存入结构体数组。然后用两个指针j、k（分别代表男女）从末尾开始扫描。找到没有被使用过的异性。
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int a;
    string s;
};
int main() {
    int n;
    cin >> n;
    vector<node> stu;
    for(int i = 0; i < n; i++) {
        node temp;
        cin >> temp.a >> temp.s;
        stu.push_back(temp);
    }
    int j = n - 1, k = n - 1;
    for(int i = 0; i < n/2; i++) {
        if(stu[i].a == 1) {
            while(stu[j].a == stu[i].a) {
                j--;
            }
            cout << stu[i].s << " " << stu[j].s << endl;
            j--;
        } else {
            while(stu[k].a == stu[i].a) {
                k--;
            }
            cout << stu[i].s << " " << stu[k].s << endl;
            k--;
        }
    }
    return 0;
}