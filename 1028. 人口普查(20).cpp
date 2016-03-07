//1028. 人口普查(20)
时间限制
200 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。
这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过200岁的老人，
而今天是2014年9月6日，所以超过200岁的生日和未出生的生日都是不合理的，应该被过滤掉。

输入格式：

输入在第一行给出正整数N，取值在(0, 10^5]；随后N行，每行给出1个人的姓名
（由不超过5个英文字母组成的字符串）、以及按“yyyy/mm/dd”（即年/月/日）格式给出的生日。
题目保证最年长和最年轻的人没有并列。

输出格式：

在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。

2
John 2001/05/12
Tom 1814/09/06
输入样例：
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 2007/11/20
输出样例：
3 Tom John

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct person {
    string name;
    int year;
    int month;
    int day;
    int flag = 0;
};

// 按照年龄从大到小来排列
int cmp(person a, person b) {
    if (a.year != b.year)
        return a.year < b.year;
    else {
        if (a.month != b.month)
            return a.month < b.month;
        else
            return a.day < b.day;
    }
}

int main() {
    int n;
    cin >> n;
    person *a = new person [n];
    int count = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].name;
        scanf("%d/%d/%d",&a[i].year, &a[i].month, &a[i].day);
        // 把不满足的人的结构体内的flag值设为1，满足的进行计数
        if (a[i].year > 2014 || (a[i].year == 2014 && a[i].month > 9) ||(a[i].year == 2014 && a[i].month ==9 && a[i].day > 6) 
            || a[i].year < 1814 || (a[i].year == 1814 && a[i].month < 9) || (a[i].year == 1814 && a[i].month == 9 && a[i].day < 6)) {
            a[i].flag = 1;
        } else {
            count++;
        }
    }
    cout << count;
    if (count != 0)
        cout << " ";
  
    sort(a, a + n, cmp);
    // 输出最年长的人的名字，从i = 0开始搜索flag == 0的，找到了就直接break退出
    for (int i = 0; i < n; i++) {
        if (a[i].flag == 0) {
            cout << a[i].name << " ";
            break;
        }
    }
    // 输出最年轻的人的名字，从i = n - 1开始搜索flag == 0的，找到了就直接break退出
    for (int i = n - 1; i >= 0; i--) {
        if (a[i].flag == 0) {
            cout << a[i].name;
            break;
        }
    }
    delete [] a;
    return 0;
}
