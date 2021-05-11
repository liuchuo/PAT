//给出n个点m条边的有向图，判断a到b有几条路，以及从a出发的终点是否都是b。
//先跑一遍dfs，维护从终点到点u的路径条数，答案为f[a]-f[b]。再跑一遍bfs，判断起点出发是否会到达从终点出发无法到达的点。
#include<bits/stdc++.h>
using namespace std;
const int maxn = 510;

vector<int>G[maxn];

int s, t;
int f[maxn];//记忆化,维护从终点反向搜索到u的路径有几条
int dfs(int u){
	if(f[u])return f[u];
	if(u==t)return 1;
	for(int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		f[u] += dfs(v);
	}
	return f[u];
}

int ok=1;
int vis[510];
void bfs(){
	queue<int>q;
	q.push(s);
	while(q.size()){
		int tmp = q.front();  q.pop();
		if(vis[tmp])continue;
		vis[tmp] = 1;
		if(f[tmp]==0){
			ok = 0; break;
		}
		if(tmp==t)continue;
		for(int i = 0; i < G[tmp].size(); i++){
			int v = G[tmp][i];
			q.push(v);
		}
	}
}

int main(){
	int n, m;
	cin>>n>>m;
	for(int i = 1; i <= m; i++){
		int u, v;  cin>>u>>v;
		G[u].push_back(v);
	}
	cin>>s>>t;
	dfs(s);
	cout<<f[s]-f[t]<<" ";
	f[t] = 1;
	bfs();
	if(ok)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}