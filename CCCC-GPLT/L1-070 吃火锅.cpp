#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int n=0, fs=0, cnt=0;
	while(getline(cin,s)){
		if(s==".")break;
		n++;
		if(s.find("chi1 huo3 guo1")!=string::npos){
			if(cnt==0)fs=n;
			cnt++;
		}
	}
	cout<<n<<"\n";
	if(cnt!=0)cout<<fs<<" "<<cnt<<endl;
	else cout<<"-_-#\n";
	return 0;
}

