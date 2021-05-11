//满二叉树后序转先序，输出层次遍历
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100010;

int n, a[maxn];
int Tree[maxn], r;
void build(int x){
	if(x>n)return ;
	build(x<<1);
	build(x<<1|1);
	Tree[x] = a[++r];
}

int main(){
	cin>>n;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	build(1);
	for(int i = 1; i <= n; i++){
		if(i!=1)cout<<" ";
		cout<<Tree[i];
	}
	return 0;
}

