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
分析：
1.0号为哨兵， 用用哨兵与其他数字交换，使其他数字回到有序的位置（最后有序时所处的位置），则排序完成
2.a[t] = i; 表示t数字当前正在占着哪一个位置。 （如果想实时监测每个数字的位置，可以用 b 数组{b[a[i]] = i } 缓存一下数据，输出查看的）
3.依次遍历每个位置i，如果当前位置不是与之对应的数字，那么我们让这哨兵来去该数执行操作回到正确位置
4.数字如何被哨兵执行操作回到序的位置：
如果哨兵此时不在自己有序的位置上，那就，先让哨兵去让他占的那个位置上的真正应该放的数字回到此位置，即交换哨兵和此数字，我们swap(a[0],a[a0])，直到哨兵在交换的过程中回到了自己的有序位置。字词再次检查该位置是不是应该放的数字（别的数字回到有序位置的时候即哨兵执行操作的过程中，有可能让此位置该有的数字回到位置）。如果此位置不是当前数字，那哨兵和他交换swap(a[0],a[i])，就是让他先去哨兵的有序位置待一会，等下一轮操作，哨兵会把他交换回来的。如果此位置已经是该数字了，那就什么都不做。
5.当到达最后一个位置时候，两种情况 1）。如果第一个数字和最后一个数字都在自己的有序位置 那ok~ 2）.哨兵和最后一个数字互相占着对方的位置，那最后一个数字就是哨兵，交换一次后，哨兵在交换后的位置等待，就是已经回到自己的有序位置，此时排序也是完成的。此过程包括在4里面了，怕你们不理解，单独说一下～

#include <iostream>
using namespace std;
int main() {
    int n, t, cnt = 0, a[100010];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t;
        a[t] = i;
    }
    for(int i = 1; i < n; i++) {
        if(i != a[i]) {
            while(a[0] != 0) {
                swap(a[0],a[a[0]]);
                cnt++;
            }
            if(i != a[i]) {
                swap(a[0],a[i]);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}