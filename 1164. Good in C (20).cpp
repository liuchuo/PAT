#include <iostream>
using namespace std;
string letter[26][7];
void printW(string s) {
	for (int i = 0; i < 7; i++) {
		string line;
		for (int j = 0; j < s.length(); j++) {
			if (j != 0) line += " ";
			line += letter[s[j]-'A'][i];
		}
		cout << line << endl;
	}
}
int main() {
	string str, ss, w = "";
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 7; j++)
			getline(cin, letter[i][j]);
	getline(cin, ss);
	ss += '#';
	int flag = 0;
	for (int i = 0; i < ss.length(); i++)
		if (!isupper(ss[i])) {
			if (w != "") {
				if (flag == 0) flag = 1;
				else printf("\n");
				printW(w);
			}
			w = "";
		} else w += ss[i];
	return 0;
}
