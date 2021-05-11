#include<bits/stdc++.h>
using namespace std;

struct node{int l=-1, r=-1, fa=-1, h;};
map<int,node>Tree;
void insert(int u, int h, int v){
	if(u==-1)return ;
	int uu = (v<u ? Tree[u].l : Tree[u].r);
	if(uu!=-1){
		insert(uu,h+1,v);
	}else{
		if(v<u)Tree[u].l = v;
		else Tree[u].r = v;
		Tree[v].fa = u;
		Tree[v].h = h;
	}
}

bool judge(int u, int a, int b, string lk){
	if(lk=="root")return u==a;;
	if(Tree.find(a)==Tree.end() || Tree.find(b)==Tree.end())return false;
	if(lk=="siblings")return Tree[a].fa==Tree[b].fa;
	if(lk=="parent")return Tree[a].l==b || Tree[a].r==b;
	if(lk=="left")return Tree[b].l == a;
	if(lk=="right")return Tree[b].r == a;
	if(lk=="level")return Tree[a].h==Tree[b].h;	
}

int main(){
	int n, rt, t;
	cin>>n>>rt; //rt是根
	for(int i = 2; i <= n; i++){
		cin>>t;
		insert(rt,1,t);
	}
	int m, a=0, b=0;  cin>>m;
	for(int i = 1; i <= m; i++){
		string s, lk;  cin>>a>>s;
		if(s=="and"){
			cin>>b>>s>>s;
			if(s=="siblings")lk = s;
			else cin>>s>>s>>lk;
		}else{
			cin>>s>>lk;
			if(lk=="parent")cin>>s>>b;
			else if(lk!="root")cin>>s>>s>>b;
		}
		if(judge(rt,a,b,lk))cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}

