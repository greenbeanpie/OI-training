#include<bits/stdc++.h>
using namespace std;
int id,n,m,q,kx,ky,x,y,a[2005],pa[2005],b[2005],pb[2005];
bitset<2005>dp[2005];
int solve(){
	if(a[1]==b[1]||a[n]==b[m])return 0;
	if((a[1]<b[1])!=(a[n]<b[m]))return 0;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		dp[i]=0;
		for(int j=1;j<=m;j++)
			if(a[i]!=b[j]&&(a[1]<b[1])==(a[i]<b[j]))
				dp[i][j]=dp[i-1][j]|dp[i][j-1]|dp[i-1][j-1];
	}	
	return dp[n][m];
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>id>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>a[i],pa[i]=a[i];
	for(int i=1;i<=m;i++)cin>>b[i],pb[i]=b[i];
	cout<<solve();
	while(q--){
		cin>>kx>>ky;
		for(int i=1;i<=kx;i++)cin>>x,cin>>a[x];
		for(int i=1;i<=ky;i++)cin>>y,cin>>b[y];
		cout<<solve();
		for(int i=1;i<=n;i++)a[i]=pa[i];
		for(int i=1;i<=m;i++)b[i]=pb[i];
	}
}