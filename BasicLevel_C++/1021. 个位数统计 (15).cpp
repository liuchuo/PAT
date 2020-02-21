#include <iostream>
using namespace std;
int main(){
    int result[10] = {0};
    char c;
    while(cin >> c){
        result[c-'0']++;
    }
    for(int i = 0;i < 10;i++){
        if(result[i] > 0) cout << i << ':' << result[i] << '\n';
    }
    return 0;
}
