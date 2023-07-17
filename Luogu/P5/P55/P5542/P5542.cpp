#include <bits/stdc++.h>
using namespace std;
int n,k,ans;
int c[1010][1010];
int a[1010][1010];
int main(){
	#ifndef ONLINE_JUDGE
		freopen("P5542.in","r",stdin);
		freopen("P5542.out","w",stdout);
	#endif
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		c[x1][y1]++;
		c[x2][y2]++;
		c[x1][y2]--;
		c[x2][y1]--;
	}
	for(int i=1;i<=1005;i++)
		for(int j=1;j<=1005;j++){
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+c[i][j];
			if(a[i][j]==k) ans++;
		}
	cout<<ans;
	return 0;
}