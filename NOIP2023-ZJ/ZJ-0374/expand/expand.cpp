#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
const int N=2005;
const int inf=1e9;
inline void fre()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
}
int c,n,m,q;
int x[N],y[N],a[N],b[N];
int kx,ky,p,v;
bool dp[N][N];
int opt,maxnx,maxny,minnx,minny;
inline bool solve()
{
	memset(dp,0,sizeof(dp));
//	for(int i=0;i<=n;i++) dp[i][0]=dp[0][i]=1;
	dp[0][0]=1;
 	maxnx=maxny=0;
	minnx=minny=inf;
	for(int i=1;i<=n;i++)
	{
		maxnx=max(maxnx,x[i]);
		minnx=min(minnx,x[i]);
	}
	for(int i=1;i<=m;i++)
	{
		maxny=max(maxny,y[i]);
		minny=min(minny,y[i]);
	}
	if(maxnx>maxny&&minnx>minny) opt=1;
	else if(maxnx<maxny&&minnx<minny) opt=-1;
	else return 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(opt*(x[i]-y[j])>0)
			{
				dp[i][j]=(dp[i-1][j]||dp[i-1][j-1])||dp[i][j-1];
			}
//			cout<<dp[i][j]<<' ';
		}
//		cout<<'\n';
	}
	return dp[n][m];
}
signed main()
{
	fre();
	IOS;
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>a[i],x[i]=a[i];
	for(int i=1;i<=m;i++) cin>>b[i],y[i]=b[i];
	cout<<solve();
	while(q--)
	{
		cin>>kx>>ky;
		for(int i=1;i<=n;i++) x[i]=a[i];
		for(int i=1;i<=m;i++)y[i]=b[i];
		for(int i=1;i<=kx;i++)
		{
			cin>>p>>v;
			x[p]=v;
		}
		for(int i=1;i<=ky;i++)
		{
			cin>>p>>v;
			y[p]=v;
		}
		cout<<solve();
	}
	return 0;
}
