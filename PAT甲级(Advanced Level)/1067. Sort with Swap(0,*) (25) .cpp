1067. Sort with Swap(0,*) (25)
Given any permutation of the numbers {0, 1, 2,..., N-1}, it is easy to sort them in increasing order. But what if Swap(0, *) is the ONLY operation that is allowed to use? For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:
Swap(0, 1) => {4, 1, 2, 0, 3}
Swap(0, 3) => {4, 1, 2, 3, 0}
Swap(0, 4) => {0, 1, 2, 3, 4}
Now you are asked to find the minimum number of swaps need to sort the given permutation of the first N nonnegative integers.
Input Specification:
Each input file contains one test case, which gives a positive N (<=105) followed by a permutation sequence of {0, 1, ..., N-1}. All the numbers in a line are separated by a space.
Output Specification:
For each case, simply print in a line the minimum number of swaps need to sort the given permutation.
Sample Input:
10 3 5 7 2 6 4 9 0 8 1
Sample Output:
9

题目大意：给出一个n个数的序列，数字为0~n-1的乱序，每次用两两交换的方式而且只能用0和另一个数交换，使序列变成有序的，问最少需要多少步骤。
分析：贪心算法，每次只能用0交换，有两种情况：
1. 0不在0位，那么0如果在第i位，而第i位本应该是i，就应该把0和i数字所在的位置交换。
2. 如果0在0位，而且整个序列到现在还不是有序的，那就把0和第一个序列没在该在的位置上的数字交换。
我们每次交换的时候都统计好ans的值，表示一共交换了多少次，每当把一个数复原的时候，让cnt--;就可以通过cnt是否大于0判断什么时候退出while循环~~~
所以说，首先我们想要知道除了0到底有多少个数字是不在位置上的（cnt），这个可以在输入的时候就判断好cnt的大小
注意：因为多次涉及到想要知道某个数所在的位置，每次都遍历数组太麻烦了，干脆在保存的时候就保存每个数字所在的位置好了，即v[i] = j表示i数字在j位置，所以每次交换i和0只需要交换v[i]和v[0]就好了
第二个注意点，很重要，如果不处理会产生两个测试点超时：在0在0位的时候，找寻第一个不在该在的位置的数的时候，如果每次都for循环从头开始找，那么时间复杂度会很高，但是我们知道，找的时候找的是第一个不在该在位置的数，那么index每前进一步都说明前面的数字是符合在该在的位置上的，而且在该在的位置上的数是不可能再交换变化的，所以直接设置一个index的变量，每次找第一个数的时候就可以直接从上一次index开始查找，避免了每次都从头找。

#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int n, num, cnt = 0, ans = 0, index = 1;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        v[num] = i;
        if(num != i && num != 0) cnt++;
    }
    while(cnt > 0) {
        if(v[0] == 0) {
            while(index < n) {
                if(v[index] != index) {
                    swap(v[index], v[0]);
                    ans++;
                    break;
                }
                index++;
            }
        }
        while(v[0] != 0) {
            swap(v[v[0]], v[0]);
            ans++;
            cnt--;
        }
    }
    printf("%d", ans);
    return 0;
}