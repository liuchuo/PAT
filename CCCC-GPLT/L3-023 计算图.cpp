#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e4+10;

struct node{
	int op, left, right; //运算符和数值
	double val; //当前节点的值
	int post;  //后继节点的
}a[maxn];
map<int,map<int,map<int,double>>>f;//记忆化数组

//第一个参数为结点，第二个参数决定是否求导，第三个参数是对谁求导
double calc(int nd, int key, int p){
	if(f[nd][key][p])return f[nd][key][p];
	int id = a[nd].op;
	if(id==0)return f[nd][key][p] = (key == 0 ? a[nd].val : (nd == p ? 1 : 0)); 
	if(id==1)return f[nd][key][p] = calc(a[nd].left, key, p) + calc(a[nd].right, key, p); 
	if(id==2)return f[nd][key][p]= calc(a[nd].left, key, p) - calc(a[nd].right, key, p); 
	if(id==3)return f[nd][key][p] = (key ? calc(a[nd].left, key, p) * calc(a[nd].right, 0, p) + calc(a[nd].left, 0, p) * calc(a[nd].right, key, p) : calc(a[nd].left, key, p) * calc(a[nd].right, key, p)); 
	if(id==4)return f[nd][key][p]=(key ? exp(calc(a[nd].left, 0, p)) * calc(a[nd].left, key, p) : exp(calc(a[nd].left, key, p)));
	if(id==5)return f[nd][key][p] = (key ? 1 / (calc(a[nd].left, 0, p)) * (calc(a[nd].left, key, p)) : log(calc(a[nd].left, key, p)));
	if(id==6)return f[nd][key][p] = (key ? cos(calc(a[nd].left, 0, p)) * calc(a[nd].left, key, p) : sin(calc(a[nd].left, key, p)));
}

int main(){
	int n;  cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i].op;
		if(a[i].op==0){
			cin>>a[i].val;
		}else if(a[i].op<=3){
			cin>>a[i].left>>a[i].right;
			a[a[i].left].post = 1;
			a[a[i].right].post = 1;
		}else{
			cin>>a[i].left;
			a[a[i].left].post = 1;
		}
	}
	int ed = 0, ok=0;
	while(a[ed].post)ed++;
	printf("%0.3lf\n",calc(ed,0,-1));
	for(int i = 0; i < n; i++){
		if(a[i].op==0){
			if(ok)cout<<" ";
			printf("%0.3lf",calc(ed,1,i));
			ok = 1;
		}
	}
	return 0;
}
