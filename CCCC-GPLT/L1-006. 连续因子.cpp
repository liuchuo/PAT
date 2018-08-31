#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int max = sqrt(n);
    for(int len = 12; len >= 1; len--) {
        for(int start = 2; start <= max; start++) {
            long long int ans = 1;
            for(int i = start; i - start <= len - 1; i++) {
                ans *= i;
            }
            if(n % ans == 0) {
                printf("%d\n%d", len, start);
                for(int i = start + 1; i - start <= len - 1; i++) {
                    printf("*%d", i);
                }
                return 0;
            }
        }
    }
    printf("1\n%d", n);
    return 0;
}

[Update v2.0] 由github用户littlesevenmo提供的更高效的解法
不用算连续因子最多不会超过12个。也不需要三重循环，两重循环即可，直接去计算当前部分乘积能不能整除N，代码如下：

#include <iostream>
#include <cmath>
using namespace std;
long int num, temp;
int main(){
    cin >> num;
    int first = 0, len = 0, maxn = sqrt(num);
    for (int i = 2; i <= maxn; i++){
        int j; temp = 1;
        for (j = i; j <= maxn; j++){
            temp *= j;
            if (num % temp != 0) break;
        }
        if (j - i > len){
            len = j - i;
            first = i;
        }
    }
    if (first == 0) cout << 1 << endl << num;
    else {
        cout << len << endl;
        for (int i = 0; i < len; i++){
            cout << first + i;
            if (i != len - 1) cout << '*';
        }
    }
    return 0;
}