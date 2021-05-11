#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e4+10;
string ss[1010];
int f[1010];
int main(){
	int n, m, s;
	cin>>n>>m>>s;
	for(int i = 1; i <= n; i++){
		cin>>ss[i];
	}
	stack<char>stk;
	int x;  
	while(cin>>x && x!=-1){
		if(x==0){
			if(stk.size()==0){
				continue;
			}
			cout<<stk.top(); stk.pop();
		}else{
			if(f[x]>=ss[x].size())continue;
			if(stk.size()==s){
				cout<<stk.top();  stk.pop();
				//if(f[x]<ss[x].size())
				//	stk.push(ss[x][f[x]++]);
			}
			//if(f[x]<ss[x].size())
				stk.push(ss[x][f[x]++]);
		}
	}
	return 0;
}