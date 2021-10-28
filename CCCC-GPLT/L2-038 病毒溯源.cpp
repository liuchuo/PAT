#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e4+10;
vector<int>G[maxn];
int ans = 0, ans2=0, root=0;
void dfs(int u, int h){
	ans = max(ans,h);
	for(int v:G[u]){
		dfs(v,h+1);
	}
}

int ok = 0;
vector<int>vc;
void dfs2(int u,int h){
	if(ok==1)return ;
	if(h==ans2 && ok==0){
		ok = 1;
		for(int i = 0; i < ans2; i++){
			if(i!=0)cout<<" "<<vc[i];
			else cout<<vc[i];
		}
		return ;
	}
	for(int v:G[u]){
		vc.push_back(v);
		dfs2(v,h+1);
		vc.pop_back();
	}
}

int main(){
	int n;  cin>>n;
	for(int i = 0; i < n; i++){
		int k;  cin>>k;
		for(int j = 0; j < k; j++){
			int x;  cin>>x;
			G[i].push_back(x);
		}
		if(G[i].size()!=0)sort(G[i].begin(),G[i].end());
	}
	for(int i = 0; i < n; i++){
		dfs(i,1);
		if(ans>ans2){
			ans2 = ans; root = i;
		}
	}
	
	cout<<ans2<<"\n";
	vc.push_back(root);
	dfs2(root,1);
	return 0;
}
