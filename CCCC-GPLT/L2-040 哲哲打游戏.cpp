#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
vector<int>G[maxn];
int back[110];
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;  cin>>n>>m;
	for(int i = 1; i <= n; i++){
		int k;  cin>>k;
		for(int j = 1; j <= k; j++){
			int x;  cin>>x;
			G[i].push_back(x);
		}
	}
	int now = 1;
	for(int i = 1; i <= m; i++){
		int op, x;  cin>>op>>x;
		if(op==0){
			now = G[now][x-1];
		}else if(op==1){
			back[x] = now;
			cout<<now<<"\n";
		}else{
			now = back[x];
		}
	}
	cout<<now<<"\n";
	return 0;
}
