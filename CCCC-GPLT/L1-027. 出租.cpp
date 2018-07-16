L1-027. 出租
下面是新浪微博上曾经很火的一张图：
一时间网上一片求救声，急问这个怎么破。其实这段代码很简单，index数组就是arr数组的下标，index[0]=2 对应 arr[2]=1，index[1]=0 对应 arr[0]=8，index[2]=3 对应 arr[3]=0，以此类推…… 很容易得到电话号码是18013820100。

本题要求你编写一个程序，为任何一个电话号码生成这段代码 —— 事实上，只要生成最前面两行就可以了，后面内容是不变的。

输入格式：

输入在一行中给出一个由11位数字组成的手机号码。

输出格式：

为输入的号码生成代码的前两行，其中arr中的数字必须按递减顺序给出。

输入样例：
18013820100
输出样例：
int[] arr = new int[]{8,3,2,1,0};
int[] index = new int[]{3,0,4,3,1,0,2,4,3,4,4};

分析：用int a[10]对号码每一位进行桶排序。逆序将a的下标存入不定长数组vector arr中，再遍历原号码生成index数组，最后输出。
#include <iostream>
#include <vector>
using namespace std;
int main() {
    string s;
    cin >> s;
    int a[10] = {0};
    for(int i = 0; i < 11; i++) {
        a[s[i] - '0']++;
    }
    vector<int> arr;
    for(int i = 9; i >= 0; i--) {
        if(a[i] != 0) {
            arr.push_back(i);
        }
    }
    vector<int> index;
    for(int i = 0; i < 11; i++) {
        for(int j = 0; j < arr.size(); j++) {
            if((s[i] - '0') == arr[j]) {
                index.push_back(j);
            }
        }
    }
    cout << "int[] arr = new int[]{" << arr[0];
    for(int i = 1; i < arr.size(); i++) {
        cout << "," << arr[i];
    }
    cout << "};" << endl << "int[] index = new int[]{" << index[0];
    for(int i = 1; i < index.size(); i++) {
        cout << "," << index[i];
    }
    cout << "};";
    return 0;
}