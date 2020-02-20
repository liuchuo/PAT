#include <iostream>
#include <set>
using namespace std;
int main(){
    int k;
    cin >> k;
    set <int,greater<int>> st;
    for(int i = 0;i < k;i++){
        cin >> k;
        st.insert(k);
    }
    set <int,greater<int>>::iterator t;
    for(t = st.begin();t != st.end();t++){
        int tmp_num = *t;
        while(tmp_num != 1){
            if(tmp_num & 1) tmp_num = tmp_num * 3 + 1;
            tmp_num /= 2;
            if(tmp_num != *t && st.find(tmp_num) != st.end()) st.erase(tmp_num);
        }
    }
    for(t = st.begin();t != st.end();t++){
        if(t != st.begin()) cout << ' ';
        cout << *t;
    }
    return 0;
}
