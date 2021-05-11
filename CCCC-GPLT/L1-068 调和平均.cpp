#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;  cin>>n;
	float ans;
	for(int i = 1; i <= n; i++){
		float x;  cin>>x; 
		ans += 1.0/x;
	}
	ans /= n;
	ans = 1.0/ans;
	printf("%.2f",ans);
	return 0;
}

