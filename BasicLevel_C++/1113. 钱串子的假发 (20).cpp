#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;
const size_t MAX_DIGIT = 100002; // plus 2 for '\0' and possible carry.
char* n1, * n2;

// Calculate a + b, and store the answer to a.
void add(char* const a, char* const b) {
	size_t len_a = strlen(a);
	size_t len_b = strlen(b);
	reverse(a, a + len_a); // low digit, low index.
	reverse(b, b + len_b);

	unsigned char carry = 0; // Carry Flag
	char* p = a, * q = b;
	while (*p != '\0' && *q != '\0') {
		*p = isdigit(*p) ? *p - '0' : *p - 'a' + 10;
		*q = isdigit(*q) ? *q - '0' : *q - 'a' + 10;
		*p = *p + *q + carry;
		carry = *p / 30;
		*p %= 30;
		++p; ++q;
	}
	char* left = (*p == '\0' ? q : p);
	while (*left != '\0') {
		*left = isdigit(*left) ? *left - '0' : *left - 'a' + 10;
		*p = *left + carry;
		carry = *p / 30;
		*p %= 30;
		++p; ++left;
	}

	if (carry) { *p = carry; ++p; }           // Possibly carry to a higher digit.
	*p = '\0';
	while (p > a && *(p - 1) == '\0') --p;    // Remove high digit 0.
	if (a == p) { *a = '0'; }                 // In case answer is zero.
	reverse(a, p);
	reverse(b, b + len_b);
	for (char* t = a; t != p; ++t) {          // Convert to show-up string.
		if (*t < 10) *t += '0';
		else *t += 'a' - 10;
	}
}

int main() {
	n1 = new char[MAX_DIGIT];
	n2 = new char[MAX_DIGIT];
	cin >> n1 >> n2;
	add(n1, n2);
	cout << n1 << endl;
	delete[] n1, n2;
	return 0;
}
