//大小写直接扫一遍处理。符号前面加空格当单词特判。空格用string流重新读一遍处理掉。
#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("input.txt","w",stdout);
	int n=-1;  cin>>n;   cin.get();
	for(int i = 1; i <= n; i++){
		string s;  getline(cin,s);
		cout<<s<<endl<<"AI:";
		
		for(int j = 0; j < s.size(); j++){
			if(isalnum(s[j]) && s[j]!='I')
				s[j] = tolower(s[j]);
			else if(!isalnum(s[j]))//符号前面加空格分隔
				s.insert(j," "),j++;
			if(s[j]=='?')
				s[j] = '!';
		}
		
		string ans[1010];
		int cnt = 0;
		stringstream ss(s);
		while(ss>>s)ans[cnt++] = s;
		
		if(!isalnum(ans[0][0]))//RE or PE
			cout<<" ";
		for(int j = 0; j < cnt; j++){
			if(!isalnum(ans[j][0]))
				cout<<ans[j];//除了第一个，符号前不加空格
			else if(ans[j]=="can"&&ans[j+1]=="you"){
				cout<<" I can"; j++;
			}else if(ans[j]=="could"&&ans[j+1]=="you"){
				cout<<" I could"; j++;
			}else if(ans[j]=="I" || ans[j]=="me"){
				cout<<" you";
			}else {
				cout<<" "<<ans[j];
			}
		}
		cout<<"\n";
		
	}
	return 0;
}