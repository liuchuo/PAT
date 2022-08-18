#include <stdio.h>
int main() {
    int a, b;
    scanf("%d%d", &a, &b); 
    for(int i = 0; i < a + b; i++)
        printf("Wang!");
    return 0;
}