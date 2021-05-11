//+ 在D天里发口罩，每个人获得要间隔P天。
//+ 给出每天的申请记录和口罩供应，包括string,id,siates,time;按照先后顺序判断每天发给谁。
//+ 并统计状态出问题的人，汇总输出。
//+ 直接模拟即可。能获得口罩的人，P天内没拿过，并且每天排名前几个。
#include<bits/stdc++.h>
using namespace std;

struct node{string name, id; int states; int t1, t2;};//申请，出现时间
bool cmp(node a, node b){return a.t1!=b.t1?a.t1<b.t1:a.t2<b.t2;}
int checkid(string s){
	if(s.size() != 18)return 0;
	for(int i = 0; i < 18; i++)//WA4,5,身份证必须是数字
		if(!isdigit(s[i]))return 0;
	return 1;
}

int main(){
	int d, p;  cin>>d>>p;
	map<string,int>mp;//相隔天数
	vector<node>ans; set<string>se;//生病的人
	for(int i = 1; i <= d; i++){
		int t, c;  cin>>t>>c;
		vector<node>tmp;
		for(int j = 1; j <= t; j++){
			string name, id;  int states, mm, hh; char ch;
			cin>>name>>id>>states>>hh>>ch>>mm;
			if(checkid(id)){
				tmp.push_back({name,id,states,hh*60+mm,j});
				if(states==1 && se.count(id)==0){
					ans.push_back({name,id,states,hh*60+mm,j});
					se.insert(id);
				}
			}
		}
		if(tmp.size()==0 || c==0)continue;
		sort(tmp.begin(),tmp.end(), cmp);
		for(int j = 0; j < tmp.size() && c; j++){
			if(mp.count(tmp[j].id)==0 || mp[tmp[j].id]+p+1<=i){
				mp[tmp[j].id] = i;
				c--;
				cout<<tmp[j].name<<" "<<tmp[j].id<<"\n";
			}
		}
	}
	for(int i = 0; i < ans.size(); i++){
		cout<<ans[i].name<<" "<<ans[i].id<<"\n";
	}
	return 0;
}