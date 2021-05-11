#include<bits/stdc++.h>
using namespace std;
struct node{
	char sex;
	string father;
};
map<string,node>people;
inline int judge(string a, string b){//TLE6
	int i = 1, j;
	for(string A=a; !A.empty(); A=people[A].father,i++){
		j = 1;
		for(string B=b; !B.empty(); B=people[B].father,j++){
			if(i>=5 && j>=5)return 1;//TLE6
			if(A==B && (i<5||j<5))return 0;//WA3,6:任意一个五代内有CA都不行
		}
		//if(i>=5 && j>=5)break; WA6
	}
	return 1;
}

int main(){
	int n;  cin>>n;
	cin.sync_with_stdio(false);//TLE6!!
	string a, b, t;  //TLE6
	for(int i = 0; i < n; i++){
		cin>>a>>b;
		if(b.back()=='n') //+sson
			people[a] = {'m',b.substr(0,b.size()-4)};
		else if(b.back()=='r')//+sdottir
			people[a] = {'f',b.substr(0,b.size()-7)};
		else people[a].sex = b.back();
	}
	int m;  cin>>m;
	//string a, b, t;//TLE6
	for(int i = 0; i < m; i++){
		cin>>a>>t>>b>>t;
		if(people.find(a)==people.end()||people.find(b)==people.end())
			printf("NA\n");//TLE6!!
		else if(people[a].sex == people[b].sex)
			printf("Whatever\n");
		else if(judge(a,b))
			printf("Yes\n");
		else 
			printf("No\n");
	}
	return 0;
}