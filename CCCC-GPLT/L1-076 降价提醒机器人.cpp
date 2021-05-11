#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; double m;  cin>>n>>m;
	for(int i = 1; i <= n; i++){
		double p;  cin>>p;
		if(p<m)printf("On Sale! %.1lf\n",p);
	}
	return 0;
}