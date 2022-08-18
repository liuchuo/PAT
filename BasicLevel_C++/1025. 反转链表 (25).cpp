#include <iostream>
#include <algorithm>
using namespace std;
int Data[100005], Next[100005], list[100005];
int main() {
    int first, k, n, temp;
    cin >> first >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        cin >> Data[temp] >> Next[temp];
    }
    int sum = 0;//不⼀定所有的输⼊的结点都是有⽤的，加个计数器
    while (first != -1) {
        list[sum++] = first;
        first = Next[first];
    }
    for (int i = 0; i < (sum - sum % k); i += k)
        reverse(begin(list) + i, begin(list) + i + k);
    for (int i = 0; i < sum - 1; i++)
        printf("%05d %d %05d\n", list[i], Data[list[i]], list[i + 1]);
    printf("%05d %d -1\n", list[sum - 1], Data[list[sum - 1]]);
    return 0;
}