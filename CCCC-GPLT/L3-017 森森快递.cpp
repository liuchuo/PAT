#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5+10;

struct seg{int x, y;}sg[maxn];
bool cmp(seg a, seg b){return a.y!=b.y?a.y<b.y:a.x<b.x;}

LL rmq[maxn<<2], tag[maxn<<2], c[maxn];
#define lch p<<1
#define rch p<<1|1
void pushdown(int p){
	if(tag[p]){
		tag[lch] += tag[p], tag[rch]+=tag[p];
		rmq[lch] += tag[p], rmq[rch]+=tag[p];
		tag[p] = 0;
	}
}
void pushup(int p){
	rmq[p] = min(rmq[lch], rmq[rch]); 
}
void build(int p, int l, int r){
	tag[p] = 0;
	if(l==r){
		rmq[p] = c[l];
		return ;
	}else{
		int m = l+r>>1;
		build(lch,l,m);
		build(rch,m+1,r);
		pushup(p);
	}
}
void update(int p, int l, int r, int L, int R, int v){
	if(l>R || r<L)return ;
	if(L<=l && r<=R){
		rmq[p] += v;  tag[p] += v;
		return ;
	}
	pushdown(p);
	int mid = l+r>>1;
	update(lch,l,mid,L,R,v);
	update(rch,mid+1,r,L,R,v);
	pushup(p);
}
LL query(int p, int l, int r, int L, int R){
	if(l>R || r<L)return (1ll<<60);
	if(L<=l && r<=R)return rmq[p];
	pushdown(p);
	LL mid = l+r>>1, ans = 1ll<<60;
	ans = min(ans, query(lch,l,mid,L,R));
	ans = min(ans, query(rch,mid+1,r,L,R));
	return ans;
}

int main(){
	int n, q;
	cin>>n>>q;
	for(int i = 1; i < n; i++)
		cin>>c[i];
	build(1,1,n-1); //1-(n-1)号城市分别对应i与i+1的边
	for(int i = 1; i <= q; i++){
		cin>>sg[i].x>>sg[i].y;
		if(sg[i].x>sg[i].y)swap(sg[i].x,sg[i].y);
	}
	sort(sg+1,sg+q+1,cmp);
	LL ans = 0;
	for(int i = 1; i <= q; i++){
		//cout<<sg[i].x+1<<" "<<sg[i].y<<" ";
		LL res = query(1,1,n-1,sg[i].x+1,sg[i].y);//因为编号从0开始，所以x+1。
		//cout<<res<<"\n";
		ans += res;
		if(res)update(1,1,n-1,sg[i].x+1,sg[i].y,-res);
	}
	cout<<ans<<endl;
	return 0;
}
