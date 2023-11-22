#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
int c,n,m,q,X[500005],Y[500005],x[500005],y[500005];
int f[2005][2005];
string ans;
void work()
{
	if(x[1]>=y[1]&&x[n]<=y[m]){ans+='0';return;}
	if(x[1]<=y[1]&&x[n]>=y[m]){ans+='0';return;}
	f[1][1]=1;
	rep(i,1,n)rep(j,1,m)
	{
		if(i==1&&j==1)continue;
		f[i][j]=0;
		if((x[1]>y[1]&&x[i]>y[j])
			||(x[1]<y[1]&&x[i]<y[j]))
		{
			if(i!=1)f[i][j]|=f[i-1][j];
			if(j!=1)f[i][j]|=f[i][j-1];
			if(i!=1&&j!=1)f[i][j]|=f[i-1][j-1];
		}
	}
	if(f[n][m])ans+='1';
	else ans+='0';
}
signed main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>q;
	rep(i,1,n)cin>>X[i];
	rep(i,1,m)cin>>Y[i];
	rep(i,1,n)x[i]=X[i];
	rep(i,1,m)y[i]=Y[i];
	work();
	while(q--)
	{
		int kx,ky,p,v;
		cin>>kx>>ky;
		rep(i,1,kx)
		{
			cin>>p>>v;
			x[p]=v;
		}
		rep(i,1,ky)
		{
			cin>>p>>v;
			y[p]=v;
		}
		work();
		rep(i,1,n)x[i]=X[i];
		rep(i,1,m)y[i]=Y[i];
	}
	cout<<ans;
}