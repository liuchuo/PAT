L1-018. 大笨钟
微博上有个自称“大笨钟V”的家伙，每天敲钟催促码农们爱惜身体早点睡觉。不过由于笨钟自己作息也不是很规律，所以敲钟并不定时。一般敲钟的点数是根据敲钟时间而定的，如果正好在某个整点敲，那么“当”数就等于那个整点数；如果过了整点，就敲下一个整点数。另外，虽然一天有24小时，钟却是只在后半天敲1~12下。例如在23:00敲钟，就是“当当当当当当当当当当当”，而到了23:01就会是“当当当当当当当当当当当当”。在午夜00:00到中午12:00期间（端点时间包括在内），笨钟是不敲的。
下面就请你写个程序，根据当前时间替大笨钟敲钟。
输入格式：
输入第一行按照“hh:mm”的格式给出当前时间。其中hh是小时，在00到23之间；mm是分钟，在00到59之间。
输出格式：
根据当前时间替大笨钟敲钟，即在一行中输出相应数量个“Dang”。如果不是敲钟期，则输出：
Only hh:mm.  Too early to Dang.
其中“hh:mm”是输入的时间。
输入样例1：
19:05
输出样例1：
DangDangDangDangDangDangDangDang
输入样例2：
07:05
输出样例2：
Only 07:05.  Too early to Dang.

#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int hour, min;
    scanf("%d:%d", &hour, &min);
    if(hour <= 12) {
        printf("Only %02d:%02d.  Too early to Dang.", hour, min);
    } else {
        hour -= 12;
        for(int i = 0; i < hour; i++)
            cout << "Dang";
        if(min > 0)
            cout << "Dang";
    }
    return 0;
}