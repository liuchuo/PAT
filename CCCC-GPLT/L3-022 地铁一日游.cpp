#include<bits/stdc++.h>
using namespace std;
const int maxn = 210;
const int inf = 1e9+10;
int G[maxn][maxn];
vector<int>st[maxn]; int ed[maxn], vis[maxn];
void dfs(int u){
	for(int i = 0; i < st[u].size(); i++){
		int v = st[u][i];
		if(!vis[v]){
			vis[v] = 1;
			dfs(v);
		}
	}
}
int main(){
	//input
	int n, m, k;  cin>>n>>m>>k;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			G[i][j] = inf;
	for(int i = 1; i <= m; i++){
		int a, b, dis;
		cin>>a; ed[a] = 1;
		while(cin>>dis>>b){
			G[a][b] = min(G[a][b], dis);
			G[b][a] = min(G[b][a], dis);
			a = b;
			if(getchar()=='\n')break;
		}
		ed[a] = 1;
	}
	//solve
	for(int k = 1; k <= n; k++)//Floyd
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(i!=j)G[i][j] = min(G[i][j],G[i][k]+G[k][j]);
	for(int i = 1; i <= n; i++){//从点i出发
		map<int,int>cost;//各种费用能到的最远距离
		for(int j = 1; j <= n; j++){//遍历到每个点的费用去更新距离
			if(G[i][j]==inf)continue;
			cost[2+G[i][j]/k] = max(cost[2+G[i][j]/k],G[i][j]);
		}
		for(int j = 1; j <= n; j++){//更新点i能到达的最远点或者端点
			if(G[i][j]==cost[2+G[i][j]/k] || i!=j&&ed[j]&&G[i][j]!=inf){
				st[i].push_back(j);
			}
		}
		/*此时其他的st还没有更新完
		memset(vis,0,sizeof(vis));
		vis[i] = 1;
		dfs(i);
		for(int j = 1; j <= n; j++)
			if(vis[j])st[i].push_back(j);
		sort(st[i].begin(), st[i].end());
		st[i].erase(unique(st[i].begin(), st[i].end()), st[i].end());
		*/
	}
	int q;  cin>>q;
	for(int i = 1; i <= q; i++){
		int x;  cin>>x;
		memset(vis,0,sizeof(vis));
		vis[x] = 1;
		dfs(x);
		for(int j = 1; j <= n; j++)
			if(vis[j])st[x].push_back(j);
		sort(st[x].begin(), st[x].end());
		st[x].erase(unique(st[x].begin(), st[x].end()), st[x].end());
		for(int j = 0; j < st[x].size(); j++){
			if(j!=0)cout<<" ";
			cout<<st[x][j];
		}
		cout<<"\n";
	}
	return 0;
}
