/*
+ 一开始初始化成n条链，传送门对应链上的结点，将所有需要新增或者删除的传送门的y值离散化，存入链上。
+ 对于每个操作，实际上要做的是“分别查询两个结点各自所在链上的左右端点”和“将两个结点的后继结点交换”，用splay可以做到logq
*/
#include<bits/stdc++.h>
using namespace std;
typedef long  long LL;
const int maxn = 5e5+10, inf =1e9+10;

int n, m;
struct node{int x1,x2,y1,y2;}qr[maxn];
vector<int>rt[maxn];

#define l(u) ch[u][0]
#define r(u) ch[u][1]
int fa[maxn], ch[maxn][2], tot, X[maxn];
int sf(int u){return u== r(fa[u]);}
bool isrt(int u){return u!=l(fa[u])&&u!= r(fa[u]);}
void rot(int u){
	int v=fa[u],f= sf (u);
	if(!isrt(v))ch[fa[v]][sf(v)]= u;
	ch[v][f]=ch[u][f^1],fa[ch[v][f]]= v;
	fa[u]=fa[v],ch[u][f^1]=v,fa[v]= u;
}
int newnode(){int u=++tot; fa[u]=l(u)=r(u)= 0 ; return u;}
void splay(int u){ for(;!isrt(u); rot(u))if(!isrt(fa[u])&&sf(fa[u])==sf(u))rot(fa[u]);}
int fdl(int u){splay(u); for(;l(u); u=l(u)); splay(u); return u;}
int fdr(int u){splay(u); for(;r(u); u=r(u)); splay(u); return u;}

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1; i <= m; i++){
		char ch;  cin>>ch;
		cin>>qr[i].x1>>qr[i].x2>>qr[i].y1;
	}
	for(int i=1; i <= n; i++){
		rt[i].push_back(0);  rt[i].push_back(inf);
	}
	for(int i=1; i <= m; i++){
		rt[qr[i].x1].push_back(qr[i].y1);
		rt[qr[i].x2].push_back(qr[i].y1);
	}
	for(int i=1; i <= n; i++){
		sort(rt[i].begin(),rt[i].end());
		rt[i].resize(unique(rt[i].begin(),rt[i].end()) - rt[i].begin());
	}
	for(int i=1; i <= m; i++){
		int y = qr[i].y1;
		qr[i].y1= lower_bound(rt[qr[i].x1].begin(),rt[qr[i].x1].end(),y)- rt[qr[i].x1].begin();
		qr[i].y2=lower_bound(rt[qr[i].x2].begin(),rt[qr[i].x2].end(),y)- rt[qr[i].x2].begin( );
	}
	for(int i=1; i <= n; i++){
		for(int j=0; j<rt[i].size(); j++){
			rt[i][j]=newnode(); X[rt[i][j]]= i;
		}
		for(int j=0; j<rt[i].size()-1; j++){
			r(rt[i][j])=rt[i][j+1],fa[rt[i][j+1]]= rt[i][j];
		}
	}
	LL ans=(LL)n*(n+1)*(2*n+1)/6;
	for(int i=1; i <= m; i++){
		int x1=qr[i].x1,x2=qr[i].x2,y1=qr[i].y1,y2=qr[i].y2;
		int u=rt[x1][y1],v= rt[x2][y2];
		int lu=X[fdl(u)],ru=X[fdr(u)],lv=X[fdl(v)],rv= X[fdr(v)];
		ans-=(LL)lu*ru+(LL)lv*rv;
		ans+=(LL)lu*rv+(LL) lv*ru;
		splay(u),splay(v);
		int u2=r(u),v2=r(v);
		r(u)=v2,r(v)=u2,fa[v2]=u,fa[u2]=v;
		cout<<ans<<"\n";
	}
	return 0;
}


