1082. Read Number in Chinese (25)
Given an integer with no more than 9 digits, you are supposed to read it in the traditional Chinese way. Output "Fu" first if it is negative. For example, -123456789 is read as "Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu". Note: zero ("ling") must be handled correctly according to the Chinese tradition. For example, 100800 is "yi Shi Wan ling ba Bai".
Input Specification:
Each input file contains one test case, which gives an integer with no more than 9 digits.
Output Specification:
For each test case, print in a line the Chinese way of reading the number. The characters are separated by a space and there must be no extra space at the end of the line.
Sample Input 1:
-123456789
Sample Output 1:
Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu
Sample Input 2:
100800
Sample Output 2:
yi Shi Wan ling ba Bai

#include <iostream>
#include <string>
#include <vector>
using namespace std;
string num[10] = { "ling","yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
string c[6] = { "Ge","Shi", "Bai", "Qian", "Yi", "Wan" };
int J[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
vector<string> res;
int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "ling";
        return 0;
    }
    if (n < 0) {
        cout << "Fu ";
        n = -n;
    }
    int part[3];
    part[0]= n / 100000000; 
    part[1]= (n % 100000000) / 10000;
    part[2] = n % 10000;
    bool zero = false; //是否在非零数字前输出合适的ling
    int printCnt = 0; //用于维护单词前没有空格，之后输入的单词都在前面加一个空格。
    for (int i = 0; i < 3; i++) {
        int temp = part[i]; //三个部分，每部分内部的命名规则都一样，都是X千X百X十X
        for (int j = 3; j >= 0; j--) {
            int curPos = 8 - i * 4 + j; //当前数字的位置
            if (curPos >= 9) continue; //最多九位数
            int cur = (temp / J[j]) % 10;//取出当前数字
            if (cur != 0) {
                if (zero) {
                    printCnt++ == 0 ? cout<<"ling" : cout<<" ling";
                    zero = false;
                }
                if (j == 0)
                    printCnt++ == 0 ? cout << num[cur] : cout << ' ' << num[cur]; //在个位，直接输出
                else                             
                    printCnt++ == 0 ? cout << num[cur] << ' ' << c[j] : cout << ' ' << num[cur] << ' ' << c[j]; //在其他位，还要输出十百千
            } else {
                if (!zero&&j != 0 && n / J[curPos] >= 10) zero = true;   //注意100020这样的情况
            }
        }
        if (i != 2 && part[i]>0) cout << ' ' << c[i + 4]; //处理完每部分之后，最后输出单位，Yi/Wan
    }
    return 0;
}