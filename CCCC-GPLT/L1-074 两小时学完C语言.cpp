#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, k, m;
	cin>>n>>k>>m;
	int x = n-k*m;
	if(x<0)x = 0;
	cout<<x<<"\n";
	return 0;
}