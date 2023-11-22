#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[1005][1005],Map[1005][1005];
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int i,j,c,t,n,m,k,d,x,y,z;
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
		if(c==17||c==18)
		{
			int ans=0;
			for(i=1;i<=m;i++)
			{
				scanf("%lld%lld%lld",&x,&y,&z);
				if(d*y<z) ans+=z-d*y;
			}
			printf("%lld\n",ans);
			continue;
		}
		for(i=1;i<=n;i++)
			for(j=1;j<=k;j++)
				Map[i][j]=f[i][j]=0;
		for(i=1;i<=m;i++)
		{
			scanf("%lld%lld%lld",&x,&y,&z);
			for(j=y;j<=k;j++)
				Map[x][j]+=z;
		}
		for(i=1;i<=n;i++)
		{
			int MAX=LLONG_MIN;
			for(j=0;j<=min(i-1,k);j++)
				MAX=max(MAX,f[i-1][j]);
			f[i][0]=MAX;
			for(j=1;j<=min(i,k);j++)
				f[i][j]=f[i-1][j-1]+Map[i][j]-d;
		}
		int MAX=LLONG_MIN;
		for(i=0;i<=k;i++)
			MAX=max(MAX,f[n][i]);
		printf("%lld\n",MAX);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
