#include<bits/stdc++.h>
using namespace std;
int main(){
	float a, b, c; int d;
	cin>>a>>d>>b;
	if(d==0){
		c = a*2.455;
	}else{
		c = a*1.26;
	}
	printf("%.2f ",c);
	if(c<b)cout<<"^_^";
	else cout<<"T_T";
	return 0;
}
