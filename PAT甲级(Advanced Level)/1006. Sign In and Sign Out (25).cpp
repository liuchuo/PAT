1006. Sign In and Sign Out (25)
At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.

Input Specification:

Each input file contains one test case. Each case contains the records for one day. The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:

ID_number Sign_in_time Sign_out_time
where times are given in the format HH:MM:SS, and ID number is a string with no more than 15 characters.

Output Specification:

For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. The two ID numbers must be separated by one space.

Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.

Sample Input:
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
Sample Output:
SC3021234 CS301133

分析：将最早和最迟的时间保存在变量中，并同时保存当前最早和最迟的人的编号，最后输出。

#include <iostream>
#include <cstdio>
using namespace std;

bool cmp(int th, int tm, int ts, int h, int m, int s) {
	if(th > h) {
		return true;
	} else if(tm > m) {
		return true;
	} else if(ts > s) {
		return true;
	}
	return false;
}

int main() {
	int n;
	scanf("%d", &n);
	string unlocked, locked;
	int unlockedh = 23, unlockedm = 59, unlockeds = 59;
	int lockedh = 0, lockedm = 0, lockeds = 0;
	for(int i = 0; i < n; i++) {
		string t;
		cin >> t;
		int h1, m1, s1, h2, m2, s2;
		scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
		if(cmp(h1, m1, s1, unlockedh, unlockedm, unlockeds) == false) {
			unlockedh = h1;
			unlockedm = m1;
			unlockeds = s1;
			unlocked = t;
		}
		if(cmp(h2, m2, s2, lockedh, lockedm, lockeds) == true) {
			lockedh = h2;
			lockedm = m2;
			lockeds = s2;
			locked = t;
		}
	}
	cout << unlocked << " " << locked;
	return 0;
}