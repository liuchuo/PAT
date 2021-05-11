#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	double x, y;
	cin>>x>>y;
	double z = x/y/y;
	printf("%.1lf\n",z);
	if(z>25.0){
		cout<<"PANG\n";
	}else{
		cout<<"Hai Xing\n";
	}
	return 0;
}

