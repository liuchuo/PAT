#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int hour, min;
    scanf("%d:%d", &hour, &min);
    if(hour <= 12) {
        printf("Only %02d:%02d.  Too early to Dang.", hour, min);
    } else {
        hour -= 12;
        for(int i = 0; i < hour; i++)
            cout << "Dang";
        if(min > 0)
            cout << "Dang";
    }
    return 0;
}