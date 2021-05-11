#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[10], bj, yz;
	int mx=-1;
	for(int i=1;i<=4;i++){cin>>a[i];mx=max(mx,a[i]);}
	cin>>bj>>yz;
	
	int ok = 1, lq;
	for(int i = 1; i <= 4; i++){
		if(mx-a[i]>yz || a[i]<bj){
			if(ok==1)ok=0;
			else ok = 2;
			lq = i;
		}
	}
	if(ok==1)cout<<"Normal\n";
	else if(ok==0)cout<<"Warning: please check #"<<lq<<"!\n";
	else cout<<"Warning: please check all the tires!\n";
	
	return 0;
}

