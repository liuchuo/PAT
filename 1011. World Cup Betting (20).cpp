1011. World Cup Betting (20)
With the 2010 FIFA World Cup running, football fans the world over were becoming increasingly excited as the best players from the best teams doing battles for the World Cup trophy in South Africa. Similarly, football betting fans were putting their money where their mouths were, by laying all manner of World Cup bets.

Chinese Football Lottery provided a "Triple Winning" game. The rule of winning was simple: first select any three of the games. Then for each selected game, bet on one of the three possible results -- namely W for win, T for tie, and L for lose. There was an odd assigned to each result. The winner's odd would be the product of the three odds times 65%.

For example, 3 games' odds are given as the following:

 W    T    L
1.1  2.5  1.7
1.2  3.0  1.6
4.1  1.2  1.1
To obtain the maximum profit, one must buy W for the 3rd game, T for the 2nd game, and T for the 1st game. If each bet takes 2 yuans, then the maximum profit would be (4.1*3.0*2.5*65%-1)*2 = 37.98 yuans (accurate up to 2 decimal places).

Input

Each input file contains one test case. Each case contains the betting information of 3 games. Each game occupies a line with three distinct odds corresponding to W, T and L.

Output

For each test case, print in one line the best bet of each game, and the maximum profit accurate up to 2 decimal places. The characters and the number must be separated by one space.

Sample Input
1.1 2.5 1.7
1.2 3.0 1.6
4.1 1.2 1.1
Sample Output
T T W 37.98

题目大意：简单模拟。
给出三场比赛以及每场比赛的W、T、L的赔率，选取每一场比赛中赔率最大的三个数a b c，
先输出三行各自选择的是W、T、L中的哪一个，然后根据计算公式 (a * b * c * 0.65 - 1) * 2 得出最大收益。

分析：以三个数一组的形式读取，读取完一组后输出最大值代表的字母，然后同时ans累乘该最大值。最后根据公式输出结果。

#include <cstdio>
using namespace std;
int main() {
	char c[4] = {"WTL"};
	double ans = 1.0;
	for(int i = 0; i < 3; i++) {
		double maxvalue = 0.0;
		int maxchar = 0;
		for(int j = 0; j < 3; j++) {
			double temp;
			scanf("%lf", &temp);
			if(maxvalue <= temp) {
				maxvalue = temp;
				maxchar = j;
			}
		}
		ans *= maxvalue;
		printf("%c ", c[maxchar]);
	}
	printf("%.2f", (ans * 0.65 - 1) * 2);
	return 0;
}