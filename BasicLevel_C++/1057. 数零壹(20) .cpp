1057. 数零壹(20)
给定一串长度不超过10^5的字符串，本题要求你将其中所有英文字母的序号（字母a-z对应序号1-26，不分大小写）相加，得到整数N，然后再分析一下N的二进制表示中有多少0、多少1。例如给定字符串“PAT (Basic)”，其字母序号之和为：16+1+20+2+1+19+9+3=71，而71的二进制是1000111，即有3个0、4个1。
输入格式：
输入在一行中给出长度不超过105、以回车结束的字符串。
输出格式：
在一行中先后输出0的个数和1的个数，其间以空格分隔。
输入样例：
PAT (Basic)
输出样例：
3 4

分析：用getline接收一行字符串，对于字符串的每一位，如果是字母(isalpha)，则将字母转化为大写，并累加(s[i] - 'A' + 1)算出n，然后将n转化为二进制，对每一位处理，如果是0则cnt0++，如果是1则cnt1++，最后输出cnt0和cnt1的值~~~

#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int n = 0;
    for(int i = 0; i < s.length(); i++) {
        if(isalpha(s[i])) {
            s[i] = toupper(s[i]);
            n += (s[i] - 'A' + 1);
        }
    }
    int cnt0 = 0, cnt1 = 0;
    while(n != 0) {
        if(n % 2 == 0) {
            cnt0++;
        } else {
            cnt1++;
        }
        n = n / 2;
    }
    printf("%d %d", cnt0, cnt1);
    return 0;
}