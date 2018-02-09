1039. 到底买不买（20）
小红想买些珠子做一串自己喜欢的珠串。卖珠子的摊主有很多串五颜六色的珠串，
但是不肯把任何一串拆散了卖。于是小红要你帮忙判断一下，某串珠子里是否包含
了全部自己想要的珠子？如果是，那么告诉她有多少多余的珠子；如果不是，那么
告诉她缺了多少珠子。
为方便起见，我们用[0-9]、[a-z]、[A-Z]范围内的字符来表示颜色.
输入格式：
每个输入包含1个测试用例。每个测试用例分别在2行中先后给出摊主的珠串和小红想
做的珠串，两串都不超过1000个珠子。
输出格式：
如果可以买，则在一行中输出“Yes”以及有多少多余的珠子；如果不可以买，则在一
行中输出“No”以及缺了多少珠子。其间以1个空格分隔。
输入样例1：
ppRYYGrrYBR2258
YrR8RrY
输出样例1：
Yes 8
输入样例2：
ppRYYGrrYB225
YrR8RrY
输出样例2：
No 2

#include <iostream>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < b.length(); i++) {
        for (int j = 0; j < a.length(); j++) {
            if (a[j] == b[i]) {
                b[i] = '#';
                a[j] = '#';
            }
        }
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < b.length(); i++)
        if (b[i] != '#') cnt1++;
    for (int i = 0; i < a.length(); i++)
        if (a[i] != '#') cnt2++;
    if (cnt1 != 0)
        cout << "No " << cnt1;
    else
        cout << "Yes " << cnt2;
    return 0;
}