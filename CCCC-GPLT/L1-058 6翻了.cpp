#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 3e5+10;

int main(){
	string s;  getline(cin,s);
	for(int i = 0; i < s.size(); i++){
		if(s[i]!='6')cout<<s[i];
		else{
			int cc = i;
			while(s[cc]=='6' && cc<s.size())cc++;
			if(cc-i>9)cout<<"27";
			else if(cc-i>3)cout<<"9";
			else cout<<s.substr(i,cc-i);
			i = cc-1;
		}
	}
	return 0;
}

