#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	if(s.size()==4){
		int x = stoi(s.substr(0,2));
		if(x<22){
			cout<<20<<s.substr(0,2)<<"-"<<s.substr(2,2)<<"\n";
		}else{
			cout<<19<<s.substr(0,2)<<"-"<<s.substr(2,2)<<"\n";
		}
	}else{
		cout<<s.substr(0,4)<<"-"<<s.substr(4,2);
	}
	return 0;
}