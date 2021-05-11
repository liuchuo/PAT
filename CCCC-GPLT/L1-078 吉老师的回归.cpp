#include<bits/stdc++.h>
using namespace std;
int a[50];
int main(){
	int n, m;
	cin>>n>>m; cin.get();
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		string s;  getline(cin,s);
		if(s.find("easy")==string::npos && s.find("qiandao")==string::npos){
			//cout<<"adsfkragnnlkm";
			cnt++;
			if(cnt==m+1){
				cout<<s<<"\n";
				return 0;
			}
		}
	}
	cout<<"Wo AK le\n";
	return 0;
}