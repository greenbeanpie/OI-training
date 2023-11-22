#include<bits/stdc++.h>
using namespace std;
#define int long long
int id;
namespace bf{
	int t,n,m,k,d,f[1005],g[1005][1005];
	void solve()
	{
		cin>>t;
		while(t--)
		{
			memset(f,0,sizeof(f));
			memset(g,0,sizeof(g));
			cin>>n>>m>>k>>d;
			for(int i=1;i<=m;i++)
			{
				int x,y,v;
				cin>>x>>y>>v;
				int l=x-y+1,r=x;
				// for(int j=1;j<=l;j++)
				// {
				// 	for(int t=r;t<=n;t++)
				// 	{
				// 		g[j][t]+=v;
				// 	}
				// }
				g[x-y+1][x]+=v;
			}
			for(int len=1;len<=n;len++)
			{
				for(int i=1;i+len<=n;i++)
				{
					int j=i+len;
					g[i][j]+=g[i+1][j]+g[i][j-1]-g[i+1][j-1];
					// cerr<<i<<" "<<j<<" "<<g[i][j]<<"\n";
				}
			}
			for(int i=1;i<=n;i++)
			{
				f[i]=f[i-1];
				for(int j=i;j>=max(1ll,i-k+1);j--)
				{
					f[i]=max(f[i],(j==1?0:f[j-2])-(i-j+1)*d+g[j][i]);
					// cerr<<i<<" "<<j<<" "<<f[j-1]<<" "<<g[j][i]<<" "<<(i-j+1)<<f[i]<<" "<<"\n";
				}
			}
			cout<<f[n]<<"\n";
		}
	}
}
namespace B{
	int t,n,m,k,d,ans;
	void solve()
	{
		cin>>t;
		while(t--)
		{
			cin>>n>>m>>k>>d;
			ans=0;
			for(int i=1;i<=m;i++)
			{
				int x,y,v;
				cin>>x>>y>>v;
				if(v>y*d) ans+=v-y*d;
			}
			cout<<ans<<"\n";
		}
	}
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>id;
	if(id<=9) bf::solve();
	else B::solve();
}