#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 5e5+10;

struct point{LL x, y;}pp[maxn], tmp[maxn];
bool cmp(point a, point b){return a.x*b.y>a.y*b.x;}

int main(){
	int n;  cin>>n;
	for(int i = 0; i < n; i++)
		cin>>pp[i].x>>pp[i].y;
	double ans = 1e18;
	for(int i = 0; i < n; i++){
		int cc = 0;
		for(int j = 0; j < n; j++){
			if(i==j)continue;
			tmp[cc].x = pp[j].x-pp[i].x;
			tmp[cc].y = pp[j].y-pp[i].y;
			cc++;
		}
		sort(tmp,tmp+cc,cmp);
		for(int j = 0; j < cc; j++)
			ans=min(ans,abs(0.5*(tmp[j].x*tmp[(j+1)%cc].y-tmp[(j+1)%cc].x*tmp[j].y)));
	}
	printf("%.3f\n",ans);
	return 0;
}

