#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
const ll inf=1e18;
const int N=1e5+5;
int n,m,k,d,ax[N],ay[N],av[N],cnt,a[N];
int find(int x){return lower_bound(a+1,a+cnt+1,x)-a;}
namespace baoli1{
	ll dp[1005][1005],val[1005];
	vector<pair<int,int> >E[1005];
	void main(){
		memset(dp,-0x3f,sizeof dp);
		dp[0][0]=0;
		for(int i=1;i<=n;i++)E[i].clear();
		for(int i=1;i<=m;i++)E[ax[i]].pb(mkp(ay[i],av[i]));
		for(int i=1;i<=n;i++){
			ll mx=-inf;
			for(int j=min(i,k);j>=0;j--){
				mx=max(mx,dp[i-1][j]),val[j]=0;
				if(j)dp[i][j]=max(dp[i][j],dp[i-1][j-1]-d);
			}dp[i][0]=mx;ll sum=0;
			for(auto w:E[i])if(w.first<=min(i,k))val[w.first]+=w.second;
			for(int j=0;j<=min(i,k);j++)sum+=val[j],dp[i][j]+=sum;
		}ll ans=-inf;
		for(int j=0;j<=k;j++)ans=max(ans,dp[n][j]);
		printf("%lld\n",ans);
	}
}
namespace baoli2{
	ll dp[100005][105],val[1005];
	vector<pair<int,int> >E[100005];
	void main(){
		for(int i=1;i<=m;i++)
			if(ay[i]<=k)E[find(ax[i])].pb(mkp(ay[i],av[i]));
		memset(dp,-0x3f,sizeof dp);
		dp[0][0]=0;
//		for(int i=1;i<=cnt;i++)cout<<a[i]<<' ';cout<<endl;
		for(int i=1;i<=cnt;i++){
			ll mx=-inf;
			for(int j=k;j>=0;j--){
				mx=max(mx,dp[i-1][j]),val[j]=0;
				if(j-(a[i]-a[i-1])>=0)dp[i][j]=max(dp[i][j],dp[i-1][j-(a[i]-a[i-1])]-d*(a[i]-a[i-1]));
			}dp[i][0]=mx;ll sum=0;
			for(int j=1;j<a[i]-a[i-1];j++)dp[i][j]=max(dp[i][j],mx-d*j);
			for(auto w:E[i])val[w.first]+=w.second;
			for(int j=0;j<=k;j++)sum+=val[j],dp[i][j]+=sum;
//			for(int j=0;j<=k;j++)cout<<dp[i][j]<<' ';cout<<endl;
		}ll ans=-inf;
		for(int j=0;j<=k;j++)ans=max(ans,dp[cnt][j]);
		printf("%lld\n",ans);
		for(int i=1;i<=m;i++)E[find(ax[i])].clear();
	}
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int T;scanf("%*d%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&k,&d);cnt=0;
		for(int i=1;i<=m;i++)scanf("%d%d%d",&ax[i],&ay[i],&av[i]);
		for(int i=1;i<=m;i++)a[++cnt]=ax[i];
		sort(a+1,a+cnt+1);
		cnt=unique(a+1,a+cnt+1)-a-1;
		if(n<=1000)baoli1::main();
		else if(k<=100)baoli2::main();
	}
}
