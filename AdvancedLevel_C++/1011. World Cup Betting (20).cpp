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