#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e4+10;
int a[maxn];
int main(){
	int n;
	cin>>a[1]>>a[2]>>n;
	int cur = 3;
	for(int i = 3; i <= n; i++){
		int x = a[i-1]*a[i-2];
		string s = to_string(x);
		for(int j = 0; j < s.size(); j++){
			a[cur++] = s[j]-'0';
		}
	}
	for(int i = 1; i <= n; i++){
		if(i!=n)cout<<a[i]<<" ";
		else cout<<a[i];
	}
		
	return 0;
}