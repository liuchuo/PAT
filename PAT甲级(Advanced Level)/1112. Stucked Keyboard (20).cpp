1112. Stucked Keyboard (20)
On a broken keyboard, some of the keys are always stucked. So when you type some sentences, the characters corresponding to those keys will appear repeatedly on screen for k times.
Now given a resulting string on screen, you are supposed to list all the possible stucked keys, and the original string.
Notice that there might be some characters that are typed repeatedly. The stucked key will always repeat output for a fixed k times whenever it is pressed. For example, when k=3, from the string "thiiis iiisss a teeeeeest" we know that the keys "i" and "e" might be stucked, but "s" is not even though it appears repeatedly sometimes. The original string could be "this isss a teest".
Input Specification:
Each input file contains one test case. For each case, the 1st line gives a positive integer k ( 1<k<=100 ) which is the output repeating times of a stucked key. The 2nd line contains the resulting string on screen, which consists of no more than 1000 characters from {a-z}, {0-9} and "_". It is guaranteed that the string is non-empty.
Output Specification:
For each test case, print in one line the possible stucked keys, in the order of being detected. Make sure that each key is printed once only. Then in the next line print the original string. It is guaranteed that there is at least one stucked key.
Sample Input:
3
caseee1__thiiis_iiisss_a_teeeeeest
Sample Output:
ei
case1__this_isss_a_teest

题目大意：键盘某些键卡住了，按一次重复k次，要求找出可能的键，并且输出正确的字符串顺序。可能的键要求按照被发现的顺序输出。
分析：map<char, bool>存储出现的键是否坏，set<char>存储输出可能坏的键的时候，当前字符是否已经被输出过，输出过的键放在set里面.
寻找坏键：遍历字符串的每个字符的时候，与pre（字符串当前字符s[i]的前一个字符）相比较，如果相等就继续计数cnt++，如果不相等，令cnt = 1表示当前字符出现了一次~~如果cnt % k等于0 则令s[i]可能是坏键，置map对应的字符的bool值为true~~
输出坏键：由于需要根据坏键发现的顺序输出，所以遍历整个字符串的方式输出~，并且确保不会重复输出~（用set集合确保，输出过了的放在set里面）
输出整个正确的字符串：如果当前s[i]是坏键，在输出一次后，令 i = i + k - 1，再输出，保证坏键出现k次只输出一次~~
tips：谢谢在csdn博客的评论里和github里面的同学友情提醒，如果出现了先不是坏建后又判断是坏键的情况，这种情况会出现错误，因为前面已经认为它不是坏键了，说明它一定不是坏建，所以要加一个sureNoBroken，把确定不是坏键的键标记出来，在map都设置完成后把确定不是坏键的m标记为false。虽然测试用例里面没有考虑到这种情况，但是如果输入3 aabbaaa，应该输出没有坏键～代码已改～

#include <iostream>
#include <map>
#include <set>
using namespace std;
bool sureNoBroken[256];
int main() {
    int k, cnt = 1;
    scanf("%d", &k);
    string s;
    cin >> s;
    map<char, bool> m;
    set<char> printed;
    char pre = '#';
    s = s + '#';
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == pre) {
            cnt++;
        } else {
            if(cnt % k != 0) {
                sureNoBroken[pre] = true;
            }
            cnt = 1;
        }
        if(i != s.length() - 1) m[s[i]] = (cnt % k == 0);
        pre = s[i];
    }
    for(int i = 0; i < s.length() - 1; i++) {
        if(sureNoBroken[s[i]] == true)
            m[s[i]] = false;
    }
    for(int i = 0; i < s.length() - 1; i++) {
        if(m[s[i]] && printed.find(s[i]) == printed.end()) {
            printf("%c", s[i]);
            printed.insert(s[i]);
        }
    }
    printf("\n");
    for(int i = 0; i < s.length() - 1; i++) {
        printf("%c", s[i]);
        if(m[s[i]])
            i = i + k - 1;
    }
    return 0;
}
