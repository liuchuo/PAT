#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9+10;
const int maxn = 110;

struct point{ int x, y;  double dis;};
bool operator!=(point a, point b){return a.x!=b.x||a.y!=b.y;}
bool operator==(point a, point b){return a.x==b.x&&a.y==b.y;}

int n, m;
double sc[maxn][maxn];//分数
point s, t;
void input(){
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin>>sc[i][j];
	cin>>s.y>>s.x>>t.y>>t.x;
	s.x++;s.y++;t.x++;t.y++;
	s.dis = sc[s.x][s.y];
}

int flag;//1上半部分，0下半部分
double f[maxn][maxn]; //到i,j为止的最小值
int dir[][2]= {{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1},{1,1}}; //上下左右+前后左右
int cross(point a,point b,point p){//三角形行列式公式,判断三点是否在一个直线上
	return (b.x-a.x)*(p.y-a.y)-(p.x-a.x)*(b.y-a.y);
}
bool check(point p){//检查p是否合法（越界）
	if(p.x<1||p.x>n||p.y<1||p.y>m)return false;//越界
	if(flag && p!=s&&p!=t && cross(s,t,p)<=0)return false;//1:上半部分但点在下面(起点终点不算)
	if(!flag && p!=s&&p!=t && cross(s,t,p)>=0)return false;//2.下半部分但点在上面
	if(p.dis>=f[p.x][p.y])return false;//不是最小值
	return true;
}
void bfs(){
	//init
	queue<point>q;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			f[i][j] = inf;
	//search
	if(check(s)){
		f[s.x][s.y] = s.dis;
		q.push(s);
	}
	while(q.size()){
		point now = q.front(); q.pop();
		point next;
		for(int i = 0; i < 8; i++){
			next.x=now.x+dir[i][0];
			next.y=now.y+dir[i][1];
			if(i<4)next.dis = f[now.x][now.y]+sc[next.x][next.y];
			else next.dis=f[now.x][now.y]+sc[next.x][next.y]+(sc[next.x][next.y]+sc[now.x][now.y])*(sqrt(2)-1);
			if(check(next)){
				f[next.x][next.y] = next.dis;
				q.push(next);
			}
		}
	}
}

int main(){
	input();
	double ans = 0;
	flag = 1; bfs(); ans += f[t.x][t.y];//搜上面
	flag = 0; bfs(); ans += f[t.x][t.y];//搜下面
	ans -= sc[s.x][s.y]+sc[t.x][t.y];//重复
	printf("%.2f\n",ans);
	return 0;
}