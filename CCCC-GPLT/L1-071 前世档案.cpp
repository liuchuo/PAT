#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;  cin>>n>>m;
	for(int i = 1; i <= m; i++){
		string s;  cin>>s;
		int p = 0;
		for(int j = 0; j < s.size(); j++){
			if(s[j]=='y')p = p<<1;
			else p = p<<1|1;
		}
		cout<<p+1<<"\n";
	}
	return 0;
}

