#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;  cin>>n;  cin.get();
	for(int i = 1; i <= n; i++){
		string s;  getline(cin,s);
		if(s.find("ong,")==string::npos||s.find("ong.")==string::npos){
			cout<<"Skipped\n";
			continue;
		}
		int d = s.find(','), ju = s.find('.');
		if(s.substr(d-3,3)!="ong" || s.substr(ju-3,3)!="ong")
			cout<<"Skipped\n";
		else{
			int jj = ju, cc = 0;
			while(cc<3 && jj>=0)if(s[jj--]==' ')cc++;
			cout<<s.substr(0,jj+1)<<" qiao ben zhong.\n";
		}
	}
	return 0;
}

