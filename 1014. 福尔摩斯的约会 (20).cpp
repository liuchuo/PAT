//1014. 福尔摩斯的约会 (20)
大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 
3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。
大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，
因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，
代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个
钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；后面两字符串
第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定
两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：
输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。

输出格式：
在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，
即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，
SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。

输入样例：
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm
输出样例：
THU 14:04

#include <iostream>
#include <string>
using namespace std;
int main() {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    int lena = a.length();
    int lenb = b.length();
    int min1 = lena < lenb ? lena : lenb;
    int lenc = c.length();
    int lend = d.length();
    int min2 = lenc < lend ? lenc : lend;
    char t[2];
    int pos;
    int j;
    for (int i = 0; i < min1; i++) {
        if (a[i] == b[i] && (a[i] >= 'A' && a[i] <= 'G')) {
            t[0] = a[i];
            a[i] = '#';
            j = i;
            break;
        }
    }
    for (int i = j + 1; i < min1; i++) {
        if (a[i] == b[i] && ((a[i] >= 'A' && a[i] <= 'N') ||
                             (a[i] >= '0' && a[i] <= '9'))) {
            t[1] = a[i];
            break;
        }
    }
    for (int i = 0; i < min2; i++) {
        if (c[i] == d[i] && ((c[i] >= 'A' && c[i] <= 'Z') || (c[i] >= 'a' && c[i] <= 'z'))) {
            pos = i;
            break;
        }
    }
    string e;
    switch(t[0]) {
        case 'A' : e = "MON "; break;
        case 'B' : e = "TUE "; break;
        case 'C' : e = "WED "; break;
        case 'D' : e = "THU "; break;
        case 'E' : e = "FRI "; break;
        case 'F' : e = "SAT "; break;
        case 'G' : e = "SUN "; break;
    }
    int m;
    if (t[1] >= '0' && t[1] <= '9') {
        m = t[1] - '0';
    } else {
        m = t[1] - 'A' + 10;
    }
    cout << e;
    if (m >= 0 && m <= 9) {
        cout << 0 << m << ":";
    } else {
        cout << m << ":";
    }
    if (pos >= 0 && pos <= 9) {
        cout << 0 << pos;
    } else {
        cout << pos;
    }
    return 0;
}