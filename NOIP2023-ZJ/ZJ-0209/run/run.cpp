#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,k,d,x,y,z,f[1001][1001],jl[1001][1001],ans;
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>t;
//	if(c<=9)
	{
		for(int ii=1;ii<=t;ii++)
		{
			ans=-100000000000000;
			cin>>n>>m>>k>>d;
			for(int i=1;i<=n;i++)
			  for(int j=0;j<=k;j++)
			    jl[i][j]=0;
			for(int i=1;i<=k;i++)
			  f[0][i]=ans;
			for(int i=1;i<=n;i++)
			  f[i][0]=ans;
			for(int i=1;i<=m;i++)
			{
				cin>>x>>y>>z;
			//	for(int j=y;j<=k;j++)
				  jl[x][y]+=z;
			}
			for(int i=1;i<=n;i++)
			  for(int j=1;j<=k;j++)
			    jl[i][j]+=jl[i][j-1];
		//	cout<<endl;
			for(int i=1;i<=n;i++)
			{
			  for(int j=0;j<=k;j++)
			    f[i][0]=max(f[i][0],f[i-1][j]);
			  for(int j=1;j<=k;j++)
			  	f[i][j]=f[i-1][j-1]+jl[i][j]-d;
		//	  for(int j=0;j<=k;j++)
		//	    cout<<f[i][j]<<' ';
		//	  cout<<endl;	 
			}
			for(int i=0;i<=k;i++)
			  ans=max(ans,f[n][i]);
			cout<<ans<<endl;
		}
	}
	return 0;
}