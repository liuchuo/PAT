#include <cstdio>
#include <vector>
using namespace std;
vector<int> in, pre, level(100000, -1);
void post(int root, int start, int end, int index) {
    if(start > end) return ;
    int i = start;
    while(i < end && in[i] != pre[root]) i++;
    level[index] = pre[root];
    post(root + 1, start, i - 1, 2 * index + 2);
    post(root + 1 + i - start, i + 1, end, 2 * index + 1);
}
int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    in.resize(n);
    pre.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &in[i]);
    for(int i = 0; i < n; i++) scanf("%d", &pre[i]);
    post(0, 0, n-1, 0);
    for(int i = 0; i < level.size(); i++) {
        if(level[i] != -1 && cnt != n - 1) {
            printf("%d ", level[i]);
            cnt++;
        } else if(level[i] != -1){
            printf("%d", level[i]);
            break;
        }
    }
    return 0;
}