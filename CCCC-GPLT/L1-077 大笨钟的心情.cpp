#include<bits/stdc++.h>
using namespace std;
int a[50];
int main(){
	for(int i = 0; i < 24; i++)
		cin>>a[i];
	int x; 
	while(cin>>x&&x>=0&&x<=23){
		if(a[x]>50)cout<<a[x]<<" Yes\n";
		else cout<<a[x]<<" No\n";
	}
	return 0;
}