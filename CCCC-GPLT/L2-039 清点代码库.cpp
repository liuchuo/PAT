#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e4+10;
bool cmp(pair<vector<int>, int> a, pair<vector<int>, int> b){
	if(a.second!=b.second)return a.second>b.second;
	for(int i = 0; i < a.first.size(); i++){
		if(a.first[i]!=b.first[i])
			return a.first[i]<b.first[i];
	}
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;  cin>>n>>m;
	map<vector<int>, int>ma;
	for(int i = 1; i <= n; i++){
		vector<int>vc;
		for(int j = 1; j <= m; j++){
			int x;  cin>>x;  vc.push_back(x);
		}
		ma[vc]++;
	}
	vector<pair<vector<int>, int> >vc(ma.begin(), ma.end());
	sort(vc.begin(),vc.end(), cmp);
	cout<<vc.size()<<"\n";
	for(int i = 0; i < vc.size(); i++){
		cout<<vc[i].second;
		for(int j = 0; j < vc[i].first.size(); j++){
			cout<<" "<<vc[i].first[j];
		}
		cout<<"\n";
	}
	return 0;
}
