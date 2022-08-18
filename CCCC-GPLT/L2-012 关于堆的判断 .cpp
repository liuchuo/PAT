#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector<int> v;
int n;
void upAdjust(int i) {
    if(i == 1) return ;
    while(i != 1) {
        if(v[i] < v[i / 2]) {
            swap(v[i], v[i / 2]);
            i = i / 2;
        } else {
            break;
        }
    }
}
void judge1(int a) {
    if(v[1] == a) printf("T\n");
    else printf("F\n");
}
void judge2(int a, int b) {
    int indexa = 0, indexb = 0;
    for(int i = 1; i <= n; i++) {
        if(v[i] == a) indexa = i;
        if(v[i] == b) indexb = i;
    }
    if(indexa > indexb) swap(indexa, indexb);
    if(indexa % 2 == 0 && indexb - indexa == 1) printf("T\n");
    else printf("F\n");
}
void judge3(int a, int b) {
    int indexa = 0, indexb = 0;
    for(int i = 1; i <= n; i++) {
        if(v[i] == a) indexa = i;
        if(v[i] == b) indexb = i;
    }
    if((2 * indexa) == indexb || (2 * indexa) + 1 == indexb) printf("T\n");
    else printf("F\n");
}
void judge4(int a, int b) {
    int indexa = 0, indexb = 0;
    for(int i = 1; i <= n; i++) {
        if(v[i] == a) indexa = i;
        if(v[i] == b) indexb = i;
    }
    if(indexa == indexb * 2 || indexa == 2 * indexb + 1) printf("T\n");
    else printf("F\n");
}
int main() {
    int k, a, b;
    char c[100];
    scanf("%d%d", &n, &k);
    v.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        upAdjust(i);
    }
    for(int i = 0; i < k; i++) {
        scanf("%d%s", &a, c);
        if(strcmp(c, "and") == 0) {
            scanf("%d%s%s", &b, c, c);
            judge2(a, b);
        } else {
            scanf("%s", c);
            if(strcmp(c, "a") == 0) {
                scanf("%s%s%d", c, c, &b);
                judge4(a, b);
            } else {
                scanf("%s", c);
                if(strcmp(c, "root") == 0) {
                    judge1(a);
                } else {
                    scanf("%s%d", c, &b);
                    judge3(a, b);
                }
            }
        }
    }
    return 0;
}