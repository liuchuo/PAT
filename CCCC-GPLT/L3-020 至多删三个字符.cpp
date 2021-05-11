#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
LL f[maxn][5];
int main(){
	string s;  cin>>s; s = "0"+s;//从1开始
	f[0][0] = 1;
	for(int i = 1; i < s.size(); i++){
		for(int j = 0; j <= 3; j++){//删0-3个
			f[i][j] = f[i-1][j]+f[i-1][j-1];//第i个删还是不删
			for(int k=i-1; k>=1 && (i-k)<=j; k--){//去重
				if(s[k]==s[i]){//如果当前字符一样，那么前面的重复统计了
					f[i][j] -= f[k-1][j-(i-k)];
					break;
				}
			}
		}
	}
	LL ans = 0;
	for(int i = 0; i <= 3; i++)
		ans += f[s.size()-1][i];
	cout<<ans<<endl;
	return 0;
}

