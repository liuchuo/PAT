#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m,k; cin>>n>>m>>k;
	while(k--){
		stack<int>s;
		int cnt=1;
		int mx=1;
		for(int i=1; i<=n; i++){
			int x; cin>>x;
			int ok=1;
			if(cnt==x){
				cnt++; ok=0;
			}
			while(s.size()&&s.top()==cnt){
				cnt++; s.pop(); ok=0;
			}
			if(ok) s.push(x);
			mx=max(mx,(int)s.size());
		}
		//while(s.size()==cnt){
		//	cnt++; s.pop();
		//}
		if(cnt==n+1&&mx<=m) cout<<"YES"<<endl; else cout<<"NO"<<endl;
	}
	return 0;
}