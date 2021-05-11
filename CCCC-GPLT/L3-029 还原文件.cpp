#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n, m, a[maxn];
vector<int>z[110];

vector<int>ans;
int vis[110], flag = 0;
void dfs(int cur){
	if(flag==1)return ;
	if(cur>=n){
		for(int i = 0; i < ans.size(); i++){
			if(i!=0)cout<<" ";
			cout<<ans[i];
		}
		flag = 1;
		return ;
	}
	for(int i = 1; i <= m; i++){
		if(vis[i])continue;
		int ok = 1;
		for(int j = 0; j < z[i].size(); j++){
			if(a[cur+j]!=z[i][j]){ok=0;break;}
		}
		if(ok==0)continue;
		vis[i] = 1;
		ans.push_back(i);
		dfs(cur+z[i].size()-1);
		ans.pop_back();
		vis[i] = 0;
	}
}

int main(){
	cin>>n;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	cin>>m;
	for(int i = 1; i <= m; i++){
		int k;  cin>>k;
		for(int j = 1; j <= k; j++){
			int x;  cin>>x;
			z[i].push_back(x);
		}
	}
	dfs(1);
	return 0;
}
