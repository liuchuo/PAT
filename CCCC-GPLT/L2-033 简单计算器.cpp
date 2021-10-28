//开两个栈直接模拟
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	int n;  cin>>n;
	stack<int>s1;
	stack<char>s2;
	for(int i = 1; i <= n; i++){
		int x;  cin>>x;  s1.push(x);
	}
	for(int i = 1; i < n; i++){
		char ch;  cin>>ch; s2.push(ch);
	}
	while(s1.size()>1){
		int n1 = s1.top();  s1.pop();
		int n2 = s1.top();  s1.pop();
		char op = s2.top();  s2.pop();
		if(op=='+')
			s1.push(n2+n1);
		else if(op=='-')
			s1.push(n2-n1);
		else if(op=='*')
			s1.push(n2*n1);
		else{
			if(n1==0){
				cout<<"ERROR: "<<n2<<"/0\n";
				return 0;
			}
			s1.push(n2/n1);
		}
	}
	cout<<s1.top();
	return 0;
}