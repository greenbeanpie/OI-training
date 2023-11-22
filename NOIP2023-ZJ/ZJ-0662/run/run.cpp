#include <bits/stdc++.h>
#define int long long
const int N=105;
using namespace std;
int n,m,k,d;
int w[N][N],f[N][N];
int len,r,val;
int maxn;
void solve()
{
	maxn=0;
	memset(w,0,sizeof(w));
	memset(f,0,sizeof(f));
	cin>>n>>m>>k>>d;
	for(int i=1;i<=m;i++)cin>>r>>len>>val,w[r-len+1][r]+=val;
	for(int len=n;len>=1;len--)
	for(int l=1;l+len-1<=n;l++)
	{
		int r=l+len-1;
		for(int i=l;i<=r;i++)
		for(int j=i;j<=r;j++)
		{
			if(i==l&&j==r)continue;
			w[l][r]+=w[i][j];
		}
	}
	for(int r=1;r<=n;r++)
	{
		for(int j=0;j<=k;j++)
		f[r][0]=max(f[r][0],f[r-1][j]);
		for(int j=1;j<=k;j++)
		for(int z=0;z<=min({r,j,k});z++)
		f[r][j]=max(f[r][j],f[r-z][j-z]+w[r-z+1][r]-d*z);
	}
	for(int i=0;i<=k;i++)
	maxn=max(maxn,f[n][i]);
	cout<<maxn<<'\n';
}
int id,T;
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>id>>T;
	while(T--)solve();
}
