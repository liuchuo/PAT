#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
vector<int>Tree[maxn];
int rt, in[maxn], Hei, ans;
void dfs1(int u, int h){
	Hei = max(Hei, h);
	for(int i = 0; i < Tree[u].size(); i++){
		dfs1(Tree[u][i], h+1);
	}
}
void dfs2(int u, int h){
	if(h==Hei)ans = u;
	if(ans)return ;
	for(int i = 0; i < Tree[u].size(); i++){
		dfs2(Tree[u][i],h+1);
	}
}
int main(){
	int n;  cin>>n;
	for(int i = 1; i <= n; i++){
		int k;  cin>>k;
		for(int j = 1; j <= k; j++){
			int x;  cin>>x;
			Tree[i].push_back(x);
			in[x]++;
		}
	}
	for(int i = 1; i <= n; i++)
		if(in[i]==0){rt = i; break;}
	//cout<<rt<<endl;
	dfs1(rt,1);
	dfs2(rt,1);
	cout<<ans<<endl;
	return 0;
}
