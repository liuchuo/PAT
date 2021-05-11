#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;  cin>>n;
	for(int i = 1; i <= n; i++){
		string s;  cin>>s;
		int a = 0, b = 0;
		for(int j = 0; j < 3; j++)a+=s[j]-'0';
		for(int j = 3; j < 6; j++)b+=s[j]-'0';
		if(a==b){
			cout<<"You are lucky!\n";
		}else{
			cout<<"Wish you good luck.\n";
		}
	}
	return 0;
}

