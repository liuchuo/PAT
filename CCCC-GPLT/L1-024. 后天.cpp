#include <iostream>
using namespace std;
int main() {
	int a;
	cin >> a;
	int b = (a + 2 > 7) ? (a - 5) : (a + 2);
	cout << b;
	return 0;
}