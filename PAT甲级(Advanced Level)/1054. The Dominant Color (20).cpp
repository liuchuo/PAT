1054. The Dominant Color (20)
Behind the scenes in the computers memory, color is always talked about as a series of 24 bits of information for each pixel. In an image, the color with the largest proportional area is called the dominant color. A strictly dominant color takes more than half of the total area. Now given an image of resolution M by N (for example, 800x600), you are supposed to point out the strictly dominant color.
Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive numbers: M (<=800) and N (<=600) which are the resolutions of the image. Then N lines follow, each contains M digital colors in the range [0, 224). It is guaranteed that the strictly dominant color exists for each input image. All the numbers in a line are separated by a space.
Output Specification:
For each test case, simply print the dominant color in a line.
Sample Input:
5 3
0 0 255 16777215 24
24 24 0 0 24
24 0 24 24 24
Sample Output:
24

题目大意：选取主色调，就是M列N行的矩阵里面出现次数多余一半的那个数字。

分析：STL中map的应用。
使用arr[i] = j表示i元素在矩阵中出现了j次，在输入的同时比较arr当前的值是否已经超过半数，如果超过，就直接输出该数字并退出程序。


#include <cstdio>
#include <map>
using namespace std;
int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	map<int, int> arr;
	int half = m * n / 2;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int temp;
			scanf("%d", &temp);
			arr[temp]++;
			if(arr[temp] > half) {
				scanf("%d", temp);
				return 0;
			}
		}
	}
	return 0;
}