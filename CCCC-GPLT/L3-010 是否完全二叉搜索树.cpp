#include <cstdio>
using namespace std;
int tree[1<<20];
int num;
void BST(int a) {
    if(tree[a] == 0)
        tree[a] = num;
    else if(tree[a] < num)
        BST(a<<1);
    else
        BST(a<<1|1);
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        BST(1);
    }
    bool flag = true;
        for(int cnt = 1, k = 1; cnt <= n; k++) {
            if(tree[k] == 0)
                flag = false;
            else {
                printf("%d", tree[k]);
                if(cnt++ != n) printf(" ");
            }
        }
    if(flag) printf("\nYES");
    else printf("\nNO");
    return 0;
}