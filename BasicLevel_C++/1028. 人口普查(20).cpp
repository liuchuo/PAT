1028. 人口普查(20)
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
using namespace std;
int main() {
    int n;
    cin >> n;
    string name;
    int year, month, day, count = 0;
    int maxyear = 0, maxmonth = 0, maxday = 0, minyear = 9999, minmonth = 9999, minday = 9999;
    string maxname, minname;
    for (int i = 0; i < n; i++) {
        cin >> name;
        scanf("%d/%d/%d",&year, &month, &day);
        if((year < 2014 || (year == 2014 && month < 9) || (year == 2014 && month == 9 && day <= 6)) &&
           (year > 1814 || (year == 1814 && month > 9) || (year == 1814 && month == 9 && day >= 6))) {
            count++;
            if(year > maxyear || (year == maxyear && month > maxmonth) || (year == maxyear && month == maxmonth && day > maxday)) {
                maxyear = year;
                maxmonth = month;
                maxday = day;
                maxname = name;
            }
            if(year < minyear || (year == minyear && month < minmonth) || (year == minyear && month == minmonth && day < minday)) {
                minyear = year;
                minmonth = month;
                minday = day;
                minname = name;
            }
        }
    }
    cout << count;
    if (count != 0)
        cout << " " << minname << " " << maxname;
    return 0;
}
