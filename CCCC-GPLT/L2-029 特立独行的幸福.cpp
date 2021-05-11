#include<bits/stdc++.h>
using namespace std;
set<int>happy;
vector<pair<int,int> >ans;
int dd(int x){
	int sum = 0;
	while(x>0){
		sum += (x%10)*(x%10);
		x /= 10;
	}
	return sum;
}
bool is_prime(int x){
	for(int i = 2; i <= sqrt(x)+1; i++)
		if(x%i==0)return false;
	return true;
}
void love(int x){
	int t = x;
	set<int>se;
	while(x!=1 && !se.count(x)){
		se.insert(x);
		x = dd(x);
	}
	if(x==1){
		//if(!is_prime(t))cout<<t<<" "<<se.size()<<"\n";
		//else cout<<t<<" "<<2*se.size()<<"\n";
		if(!is_prime(t))ans.push_back(make_pair(t,se.size()));
		else ans.push_back(make_pair(t,2*se.size()));
		se.erase(t);
		happy.insert(se.begin(),se.end());
	}
}

int main(){
	//cout<<dd(dd(19));
	//love(19);
	//return 0;
	int l, r;
	cin>>l>>r;
	for(int i = l; i <= r; i++){
		love(i);
	}
	for(int i = 0; i < ans.size(); i++){
		if(!happy.count(ans[i].first)){
			cout<<ans[i].first<<" "<<ans[i].second<<"\n";
		}
	}
	if(ans.size()==0){
		cout<<"SAD\n";
	}
	return 0;
}
