L1-023. 输出GPLT
给定一个长度不超过10000的、仅由英文字母构成的字符串。请将字符重新调整顺序，按“GPLTGPLT....”这样的顺序输出，并忽略其它字符。当然，四种字符（不区分大小写）的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按GPLT的顺序打印，直到所有字符都被输出。
输入格式：
输入在一行中给出一个长度不超过10000的、仅由英文字母构成的非空字符串。
输出格式：
在一行中按题目要求输出排序后的字符串。题目保证输出非空。
输入样例：
pcTclnGloRgLrtLhgljkLhGFauPewSKgt
输出样例：
GPLTGPLTGLTGLGLL

#include <iostream>
#include <cctype>
int c[4];
using namespace std;
int main() {
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); i++) {
		if(toupper(s[i]) == 'G') {
			c[0]++;
		} else if(toupper(s[i]) == 'P') {
			c[1]++;
		} else if(toupper(s[i]) == 'L') {
			c[2]++;
		} else if(toupper(s[i]) == 'T') {
			c[3]++;
		}
	}
	while(c[0] != 0 || c[1] != 0 || c[2] != 0 || c[3] != 0) {
		for(int i = 0; i < 4; i++) {
			if(c[i] != 0) {
				c[i]--;
				if(i == 0)
					cout << "G";
				else if(i == 1)
					cout << "P";
				else if(i == 2)
					cout << "L";
				else
					cout << "T";
			}
		}
	}
	return 0;
}
