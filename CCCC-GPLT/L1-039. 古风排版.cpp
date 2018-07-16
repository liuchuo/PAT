L1-039. 古风排版
中国的古人写文字，是从右向左竖向排版的。本题就请你编写程序，把一段文字按古风排版。

输入格式：
输入在第一行给出一个正整数N（<100），是每一列的字符数。第二行给出一个长度不超过1000的非空字符串，以回车结束。

输出格式：
按古风格式排版给定的字符串，每列N个字符（除了最后一列可能不足N个）

输入样例：
4
This is a test case
输出样例：
asa T
st ih
e tsi
 ce s

分析：先根据字符串的长度s.length()和n计算出col列数，然后建立一个n行col列的字符数组，一开始都赋值为空格，然后根据先最后一列再倒数第二列依次向前，行数从0～n-1的顺序依次将s[index]的值填入vector中，直到s的所有字符都填完为止，最后输出这个字符数组～

#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    string s;
    cin >> n;
    getchar();
    getline(cin, s);
    int col = (s.length() - 1) / n + 1;
    vector<vector<char> > v(n, vector<char>(col, ' '));
    int index = 0;
    for (int j = col - 1; j >= 0; j--) {
        for (int i = 0; i < n; i++) {
            if (index < s.length())
                v[i][j] = s[index++];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < col; j++)
            cout << v[i][j];
        cout << endl;
    }
    return 0;
}