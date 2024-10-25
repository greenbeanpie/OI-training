#include<bits/stdc++.h>
using namespace std;
const int N=80,M=998244353;
int n,m,t,dp[N][N][N<<1],a[N],mx;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("qigong.in","r",stdin);
	freopen("qigong.out","w",stdout);
	memset(dp,0x3f,sizeof(dp));
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],
		mx=max(mx,a[i]),
		dp[i][i][a[i]/2]=a[i];
	for(int i=1;i<=n;i++)
		dp[i+1][i][0]=0;
	for(int l=2;l<=n;l++)
		for(int i=1,j=i+l-1;j<=n;j++,i++)
			for(int k=i;k<j;k++)
				for(int l=0;l<=mx;l++){
					if(dp[i][k][l]==dp[0][0][0])
						continue;
					int p=k+1,x=l;
					while(p<=j){
						for(int h=x;h<=mx;h++)
							dp[i][j][h]=min(dp[i][j][h],dp[p][j][h-x]+dp[i][k][l]);
						if(x>=a[p])
							x/=2;
						else
							break;
						p++;
					}
					for(int h=0;h<=mx;h++)
						dp[i][j][h]=min(dp[i][j][h],max(0,dp[p][j][h]-x)+dp[i][k][l]);
				}
	for(int i=1;i<=n;i++){
		int ans=1e9;
		for(int j=0;j<=mx;j++)
			ans=min(ans,dp[1][i][j]);
		cout<<ans<<' ';
	}
	return 0;
}

