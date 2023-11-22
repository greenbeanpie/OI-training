#include<bits/stdc++.h>
#define int long long
using namespace std;
int dian,T,n,m,ans,kun,d,i,x,y,z,tree[1010][1010],dp[1010][1010],j;
int lowbit(int x){return x&-x;}
void add(int x,int y,int z){
	for(;y<=n;y+=lowbit(y))
		tree[x][y]+=z;
}
int da(int x,int y){
	int sum=0;
	for(;y;y-=lowbit(y))
		sum=sum+tree[x][y];
	return sum;
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>dian>>T;
	if(dian==17||dian==18){
		while(T--){
			cin>>n>>m>>kun>>d;ans=0;
			for(i=1;i<=m;i++){
				cin>>x>>y>>z;
				if(y>kun||y>x)continue;
				if(z>y*d)ans=ans+z-y*d;
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	while(T--){
		cin>>n>>m>>kun>>d;
		for(i=1;i<=n;i++)
			for(j=0;j<=n;j++)
				tree[i][j]=0;
		for(i=1;i<=m;i++){
			cin>>x>>y>>z;
			add(x,y,z);
		}
		for(i=0;i<=n;i++)
			for(j=0;j<=kun;j++)
				dp[i][j]=-1e18;
		dp[0][0]=0;
		for(i=1;i<=n;i++){
			for(j=0;j<=min(i-1,kun);j++)
				dp[i][0]=max(dp[i][0],dp[i-1][j]);
			for(j=1;j<=min(kun,i);j++)
				dp[i][j]=dp[i-1][j-1]+da(i,j)-d;
		}
		ans=0;
		for(j=0;j<=min(n,kun);j++)
			ans=max(ans,dp[n][j]);
		cout<<ans<<'\n';
	}
	return 0;
}