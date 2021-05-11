#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;  cin>>n;
	for(int i = 1; i <= n; i++){
		int sx, hei, wei;
		cin>>sx>>hei>>wei;
		if(sx==1){
			if(hei==130)cout<<"wan mei! ";
			else if(hei<130)cout<<"duo chi yu! ";
			else cout<<"ni li hai! ";
			
			if(wei==27)cout<<"wan mei!\n";
			else if(wei<27)cout<<"duo chi rou!\n";
			else cout<<"shao chi rou!\n";
		}else{
			if(hei==129)cout<<"wan mei! ";
			else if(hei<129)cout<<"duo chi yu! ";
			else cout<<"ni li hai! ";
			
			if(wei==25)cout<<"wan mei!\n";
			else if(wei<25)cout<<"duo chi rou!\n";
			else cout<<"shao chi rou!\n";
		}
	}
	return 0;
}

