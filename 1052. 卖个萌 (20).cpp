/*
1052. 卖个萌 (20)
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
萌萌哒表情符号通常由“手”、“眼”、“口”三个主要部分组成。简单起见，我们假设一个表情符号是按下列格式输出的：

[左手]([左眼][口][右眼])[右手]
现给出可选用的符号集合，请你按用户的要求输出表情。

输入格式：

输入首先在前三行顺序对应给出手、眼、口的可选符号集。每个符号括在一对方括号[]内。题目保证每个集合都至少有一个符号，并不超过10个符号；每个符号包含1到4个非空字符。

之后一行给出一个正整数K，为用户请求的个数。随后K行，每行给出一个用户的符号选择，顺序为左手、左眼、口、右眼、右手——这里只给出符号在相应集合中的序号（从1开始），数字间以空格分隔。

输出格式：

对每个用户请求，在一行中输出生成的表情。若用户选择的序号不存在，则输出“Are you kidding me? @\/@”。

输入样例：
[╮][╭][o][~\][/~][<][>]
[╯][╰][^][-][=][>][<][@][⊙]
[Д][▽][_][ε][^]
4
1 1 2 2 2
6 8 1 5 5
3 3 4 3 3
2 10 3 9 3
输出样例：
╮(╯▽╰)╭
<(@Д=)/~
o(^ε^)o
Are you kidding me? @\/@
*/

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main() {
	string shou, yan, kou;
	cin >> shou >> yan >> kou;

	int n;
	int lenshou = shou.length();
	int lenyan = yan.length();
	int lenkou = kou.length();
	//先计算各个表情的个数
	int sumshou = 0, sumyan = 0, sumkou = 0;
	for (int i = 0; i < lenshou; i++) {
		if(shou[i] == '[') {
			sumshou++;
		}
	}
	for (int i = 0; i < lenyan; i++) {
		if(yan[i] == '[') {
			sumyan++;
		}
	}
	for (int i = 0; i < lenkou; i++) {
		if(kou[i] == '[') {
			sumkou++;
		}
	}

	for (int i = 0; i < n; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		//判断abcde是否有超过表情个数的
		if (a > sumshou || a < 1 || e > sumshou || e < 1 ||
			b > sumyan || b < 1 || d > sumyan || d < 1 ||
			c > sumkou || c < 1) {
			cout << "Are you kidding me? @\/@";
			continue;
		}

		int k = 0;
		for(int j = 0; j < lenshou; j++) {
			if(shou[j] == '[') {
				k++;
				if(k == a) {
					for(int l = j + 1; l <= j + 6; l++) {
						if(shou[l] != ']') {
							cout << shou[l];
						} else {
							break;
						}
					}
					cout << "(";
				}
			}
		}

		k = 0;
		for(int j = 0; j < lenyan; j++) {
			if(yan[j] == '[') {
				k++;
				if(k == b) {
					for(int l = j + 1; l <= j + 6; l++) {
						if(yan[l] != ']') {
							cout << yan[l];
						} else {
							break;
						}
					}
				}
			}
		}

		k = 0;
		for(int j = 0; j < lenkou; j++) {
			if(kou[j] == '[') {
				k++;
				if(k == c) {
					for(int l = j + 1; l <= j + 6; l++) {
						if(kou[l] != ']') {
							cout << kou[l];
						} else {
							break;
						}
					}
				}
			}
		}

		k = 0;
		for(int j = 0; j < lenyan; j++) {
			if(yan[j] == '[') {
				k++;
				if(k == d) {
					for(int l = j + 1; l <= j + 6; l++) {
						if(yan[l] != ']') {
							cout << yan[l];
						} else {
							break;
						}
					}
					cout << ")";
				}
			}
		}

		k = 0;
		for(int j = 0; j < lenshou; j++) {
			if(shou[j] == '[') {
				k++;
				if(k == e) {
					for(int l = j + 1; l <= j + 6; l++) {
						if(shou[l] != ']') {
							cout << shou[l];
						} else {
							break;
						}
					}
				}
			}
		}
		cout << endl;
	}
	return 0;
}