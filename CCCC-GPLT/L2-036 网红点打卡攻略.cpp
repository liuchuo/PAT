//+ n个点m条带权边。给出k条路径，判断能否从v1出发经过每个点一次并返回v1，输出最短的路径。
//+ n<200 所以邻接矩阵存个图，直接暴力枚举就行。
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int inf = 1e9+10;
const int maxn = 220;
int e[maxn][maxn], vis[maxn];
int main(){
	int n, m;
	cin>>n>>m;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++)
			e[i][j] = inf;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		e[u][v] = e[v][u] = w;
	}
	int k;  cin>>k;
	int cnt = 0, po = 0, hf = inf;
	for(int i = 1; i <= k; i++){
		memset(vis,0,sizeof(vis));
		int kk;  cin>>kk;
		int la = 0, tmphf = 0, ok = 1;
		for(int j = 1; j <= kk; j++){
			int x;  cin>>x;
			if(e[la][x]!=inf && !vis[x]){
				//cout<<tmpfile<<" "<<e[la][x]<<"\n";
				tmphf += e[la][x];
				//cout<<tmpfile<<"\n";
				la = x;
				vis[x]++;
			}else{
				ok = 0;
			}
		}
		for(int i = 1; i <= n; i++){
			if(vis[i]!=1)ok = 0;
		}
		if(ok && e[la][0] != inf){
			tmphf += e[la][0];
			cnt++;
			//cout<<i<<": "<<tmphf<<"\n";
			if(tmphf < hf){
				hf = tmphf;
				po = i;
			}
		}
	}
	cout<<cnt<<"\n";
	cout<<po<<" "<<hf<<"\n";
	return 0;
}