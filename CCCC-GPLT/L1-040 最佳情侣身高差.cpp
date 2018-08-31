#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    string s;
    double num;
    cin >> s >> num;
    if(s == "M")
      printf("%.2f\n",num / 1.09);
    else  
      printf("%.2f\n",num * 1.09);
  }
  return 0;
}