#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e4+10;
int a[maxn];
int main(){
	int n;  cin>>n;
	int mx = -1, mi = 1e9+10;
	for(int i = 1; i <= n; i++){
		cin>>a[i]; 
		mx = max(mx, a[i]);
		mi = min(mi, a[i]);
	}
	int a1 = 0, a2 = 0;
	for(int i = 1; i <= n; i++){
		if(a[i]==mx)a1++;
		if(a[i]==mi)a2++;
	}
	cout<<mi<<" "<<a2<<"\n";
	cout<<mx<<" "<<a1<<"\n";
	return 0;
}