1028. 人口普查(20)
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

这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过200岁的老人，而今天是2014年9月6日，所以超过200岁的生日和未出生的生日都是不合理的，应该被过滤掉。

输入格式：

输入在第一行给出正整数N，取值在(0, 105]；随后N行，每行给出1个人的姓名（由不超过5个英文字母组成的字符串）、以及按“yyyy/mm/dd”（即年/月/日）格式给出的生日。题目保证最年长和最年轻的人没有并列。

输出格式：

在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。

输入样例：
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
输出样例：
3 Tom John
#include <iostream>
#include <string>
using namespace std;
struct peo{
	string name;
	int year, mon, date, id;
	//id表示像身份证一样把生日编号;  
	//id越小越老,越大越年轻; 
}t; 
int main() {
	int n, cnt = 0, maxn = 0, minn =20140907;
	string maxname,minname;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> t.name;
		scanf("%d/%d/%d",&t.year, &t.mon, &t.date);
		t.id  = 10000* t.year + 100*t.mon + t.date ;//编写id号码 
		if(t.id >=18140906 && t.id <= 20140906) {
			cnt++;
			if(t.id > maxn) {
				maxn = t.id ;
				maxname = t.name ;
			}
			if(t.id < minn) {
				minn = t.id ;
				minname = t.name ;
			}
		}
	}
	cout << cnt ;
	if(cnt != 0)
		cout << ' ' << minname << ' ' << maxname;//id越小越老 
return 0;
}

