1071. Speech Patterns (25)
People often have a preference among synonyms of the same word. For example, some may prefer "the police", while others may prefer "the cops". Analyzing such patterns can help to narrow down a speaker's identity, which is useful when validating, for example, whether it's still the same person behind an online avatar.
Now given a paragraph of text sampled from someone's speech, can you find the person's most commonly used word?
Input Specification:
Each input file contains one test case. For each case, there is one line of text no more than 1048576 characters in length, terminated by a carriage return '\n'. The input contains at least one alphanumerical character, i.e., one character from the set [0-9 A-Z a-z].
Output Specification:
For each test case, print in one line the most commonly occurring word in the input text, followed by a space and the number of times it has occurred in the input. If there are more than one such words, print the lexicographically smallest one. The word should be printed in all lower case. Here a "word" is defined as a continuous sequence of alphanumerical characters separated by non-alphanumerical characters or the line beginning/end.
Note that words are case insensitive.
Sample Input:
Can1: "Can a can can a can?  It can!"
Sample Output:
can 5

题目大意：大小写字母+数字的组合才是合法的单词，给出一个字符串，求出现的合法的单词的个数最多的那个单词，以及它出现的次数。如果有并列的，那么输出字典序里面的第一个~~~
分析：用map很简单的~不过呢~有几个注意点~~：
1. 大小写不区分，所以统计之前要先s[i] = tolower(s[i]);
2. [0-9 A-Z a-z]可以简写为cctype头文件里面的一个函数isalnum~~
3. 必须用getline读入一长串的带空格的字符串~~
4. 一定要当t不为空的时候m[t]++，因为t为空也会被统计的！！！~~~
5. 最最重要的是~~，如果最后一个字符是合法的，那么因为else是建立在遇到分隔符（即不合法字符）的前提下的，所以必须在for循环之外再判断一次if(t.length()) m[t]++;~~~要不然最后一个合法的单词可能会被忘记记入进去而导致最后一个测试点不通过~~~

#include <iostream>
#include <map>
#include <string>
#include <cctype>
using namespace std;
int main() {
    string s, t;
    getline(cin, s);
    map<string, int> m;
    for(int i = 0; i < s.length(); i++) {
        if(isalnum(s[i])) {
            s[i] = tolower(s[i]);
            t += s[i];
        } else {
            if(t.length())
                m[t]++;
            t = "";
        }
    }
    if(t.length()) m[t]++;
    int maxn = 0;
    for(auto it = m.begin(); it != m.end(); it++) {
        if(it->second > maxn) {
            maxn = it->second;
            t = it->first;
        }
    }
    cout << t << " " << maxn;
    return 0;
}