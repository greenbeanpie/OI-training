#include<bits/stdc++.h>
using namespace std;
int t;
long long n,m,k,d;
namespace sub1
{
	long long f[1005][1005];
	vector<pair<int,long long> > chag[1005];
	void work(void)
	{
		int x,y;
		long long z,ans;
		while(t--)
		{
			memset(f,0,sizeof(f));
			ans=-1e16;
			scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
			for(int i=1;i<=m;i++)
			{	
				scanf("%d%d%lld",&x,&y,&z);
				if(y>k) continue;
				chag[x].push_back(make_pair(y,z));
			}
			long long maxx=0;
			for(int i=1;i<=n;i++)
			{
				f[i][0]=maxx;
				for(int j=1;j<=min(i,(int)k);j++)
				{
					f[i][j]=f[i-1][j-1]-d;
					for(int p=0;p<chag[i].size();p++)
					{
						if(j>=chag[i][p].first) f[i][j]+=chag[i][p].second;
					}
					maxx=max(maxx,f[i][j]);
				}
			}
			for(int i=0;i<=k;i++)
			{
				ans=max(ans,f[n][i]);
			}
			cout<<ans<<'\n';
			for(int i=1;i<=n;i++) chag[i].clear();
		}
	}
}
namespace sub2
{
	void work(void)
	{
		long long x,y,z,ans;
		while(t--)
		{
			ans=0;
			scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
			for(int i=1;i<=m;i++)
			{	
				scanf("%lld%lld%lld",&x,&y,&z);
				if(y>k) continue;
				if(z>y*d) ans+=z-y*d;
			}
			cout<<ans<<'\n';
		}
	}
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c;
	scanf("%d%d",&c,&t);
	if(c<=9) sub1::work();
	else if(c==17||c==18) sub2::work();
	return 0;
}
