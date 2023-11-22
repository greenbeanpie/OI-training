#include <bits/stdc++.h>
#define int long long
using namespace std;
int f[1010][1010],s[1010][1010];
signed main()
{
	freopen("run.in","r",stdin);freopen("run.out","w",stdout);
	int sid,T;scanf("%lld%lld",&sid,&T);if(sid<=9) while(T--)
	{
		int n,m,k,d,tmp1,tmp2,w;scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
		for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&tmp1,&tmp2,&w),s[tmp1][tmp2]+=w;
		for(int i=1;i<=n;i++)
		{
			int tot=0;
			for(int j=0;j<=k;j++)
			{
				tot+=s[i][j];
				if(j==0) for(int p=0;p<=k;p++) f[i][j]=max(f[i][j],f[i-1][p]);
				else f[i][j]=f[i-1][j-1]-d+tot;
			}
		}
		int ans=0;for(int i=0;i<=k;i++) ans=max(ans,f[n][i]);printf("%lld\n",ans);
		for(int i=1;i<=n;i++) for(int j=0;j<=k;j++) f[i][j]=s[i][j]=0;
	}
	return 0;
}