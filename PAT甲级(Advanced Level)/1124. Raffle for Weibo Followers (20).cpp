1124. Raffle for Weibo Followers (20)
John got a full mark on PAT. He was so happy that he decided to hold a raffle（抽奖） for his followers on Weibo -- that is, he would select winners from every N followers who forwarded his post, and give away gifts. Now you are supposed to help him generate the list of winners.
Input Specification:
Each input file contains one test case. For each case, the first line gives three positive integers M (<= 1000), N and S, being the total number of forwards, the skip number of winners, and the index of the first winner (the indices start from 1). Then M lines follow, each gives the nickname (a nonempty string of no more than 20 characters, with no white space or return) of a follower who has forwarded John s post.
Note: it is possible that someone would forward more than once, but no one can win more than once. Hence if the current candidate of a winner has won before, we must skip him/her and consider the next one.
Output Specification:
For each case, print the list of winners in the same order as in the input, each nickname occupies a line. If there is no winner yet, print "Keep going..." instead.
Sample Input 1:
9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain
Sample Output 1:
PickMe
Imgonnawin!
TryAgainAgain
Sample Input 2:
2 3 5
Imgonnawin!
PickMe
Sample Output 2:
Keep going...

题目大意：小明PAT考了满分，高兴之余决定发起微博转发抽奖活动，从转发的网友中按顺序每隔N个人就发出一个红包。请你编写程序帮助他确定中奖名单。注意：可能有人转发多次，但不能中奖多次。所以如果处于当前中奖位置的网友已经中过奖，则跳过他顺次取下一位。按照输入的顺序输出中奖名单，每个昵称占一行。如果没有人中奖，则输出“Keep going...”
分析：用mapp存储当前用户有没有已经中奖过～当输入的时候，判断当前字符串是否已经在mapp中出现过，如果出现过就将s+1。每次判断i是否等于s，如果等于s且当前用户没有中过奖，就将它的名字输出，并且s = s + n～并将mapp[str]标记为1，且flag标记为true表示有过人中奖。最后flag如果依然是false说明要输出Keep going...

#include <iostream>
#include <map>
using namespace std;
int main() {
    int m, n, s;
    scanf("%d%d%d", &m, &n, &s);
    string str;
    map<string, int> mapp;
    bool flag = false;
    for (int i = 1; i <= m; i++) {
        cin >> str;
        if (mapp[str] == 1) s = s + 1;
        if (i == s && mapp[str] == 0) {
            mapp[str] = 1;
            cout << str << endl;
            flag = true;
            s = s + n;
        }
    }
    if (flag == false) cout << "Keep going...";
    return 0;
}