#include <iostream>
#include <vector>
using namespace std;
struct node {
    int a;
    string s;
};
int main() {
    int n;
    cin >> n;
    vector<node> stu;
    for(int i = 0; i < n; i++) {
        node temp;
        cin >> temp.a >> temp.s;
        stu.push_back(temp);
    }
    int j = n - 1, k = n - 1;
    for(int i = 0; i < n/2; i++) {
        if(stu[i].a == 1) {
            while(stu[j].a == stu[i].a) j--;
            cout << stu[i].s << " " << stu[j].s << endl;
            j--;
        } else {
            while(stu[k].a == stu[i].a) k--;
            cout << stu[i].s << " " << stu[k].s << endl;
            k--;
        }
    }
    return 0;
}