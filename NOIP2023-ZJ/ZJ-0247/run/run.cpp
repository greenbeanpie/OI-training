#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	int cs;
	ll val;
};
const int N=1e3+5;
vector<node>e[N];
ll f[N][N];
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while (T--)
	{
		int n,m,k;
		ll d;
		scanf("%d%d%d%lld",&n,&m,&k,&d);
		for (int i = 1; i <= n; i++)
		  e[i].clear();
		for (int i = 1; i <= m; i++)
		{
			int x,y;
			ll z;
			scanf("%d%d%lld",&x,&y,&z);
			e[x].push_back((node){y,z});
		}
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= k; j++)
			  f[i][j]=-1e16;
		}
		f[0][0]=0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= k; j++)
			{
				ll now=0;
				for (int l = 0; l < e[i].size(); l++)
				{
					node x=e[i][l];
					if (x.cs<=j+1)
					  now+=x.val;
				}
		     	if (f[i-1][j]!=-1e16)
					f[i][0]=max(f[i][0],f[i-1][j]);
				if (f[i-1][j]!=-1e16)
				    f[i][j+1]=max(f[i][j+1],f[i-1][j]-d+now);
			}
		}
		ll ans=-1e18;
		for (int j = 0; j <= k; j++)
		  ans=max(ans,f[n][j]);
		printf("%lld\n",ans);
	}
	return 0;
}
