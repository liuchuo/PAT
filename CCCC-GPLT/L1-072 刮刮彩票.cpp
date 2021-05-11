#include<bits/stdc++.h>
using namespace std;

int a[10][10], b[10], bx,by,bz;
int num[] = {0,1,2,3,4,5,10000,36,720,360,80,252,108,72,54,180,72,180,119,36,306,1080,144,1800,3600};
int main(){
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 3; j++){
			cin>>a[i][j];
			b[a[i][j]]++;
			if(a[i][j]==0){
				bx = i; by = j;
			}
		}
	}
	for(int i = 1; i <= 9; i++)
		if(b[i]==0)bz=i;
	a[bx][by]=bz;
	for(int i = 1; i <= 3; i++){
		int x, y;  cin>>x>>y;
		cout<<a[x][y]<<"\n";
	}
	int fx;  cin>>fx;
	int ans = 0;
	for(int i = 1; i <= 3; i++){
		if(fx<=3)ans += a[fx][i];
		else if(fx<=6)ans += a[i][fx-3];//WA2
		else if(fx==7)ans += a[i][i];
		else ans += a[i][3-i+1];
		
	}
	cout<<num[ans];
	return 0;
}

