#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define MP make_pair
#define fi first
#define se second
using namespace std;
int o,T;
namespace A
{
	const int N=1010;
	const int inf=1e18;
	int n,m,k,d;
	int f[N][N];
	int F[N][N];
	void main()
	{
		while(T--)
		{
			scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
			for(int i=1;i<=n;i++) for(int j=0;j<=n;j++) F[i][j]=0;
			while(m--)
			{
				int x,y,z;
				scanf("%lld%lld%lld",&x,&y,&z);
				F[x][y]+=z;
			}
			for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) F[i][j]+=F[i][j-1];
			for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) f[i][j]=-inf;
			f[0][0]=0;
			for(int i=1;i<=n;i++) for(int j=0;j<=min(i-1,k);j++)
			{
				f[i][0]=max(f[i][0],f[i-1][j]);
				if(j+1<=k) f[i][j+1]=max(f[i][j+1],f[i-1][j]-d+F[i][j+1]);
			}
			int ans=-inf;
			for(int i=0;i<=k;i++) ans=max(ans,f[n][i]);
			printf("%lld\n",ans);
		}
	}
}
namespace B
{
	const int N=1e5+10;
	const int M=2010;
	const int inf=1e18;
	int c[N];
	int F[N];
	int id[N];
	int n,m,k,d;
	int f[M][M];
	int cnt,a[N];
	int x[N],y[N],z[N];
	vector <pii> v[N];
	void main()
	{
		while(T--)
		{
			cnt=0;
			for(int i=1;i<=n;i++) c[i]=0;
			scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
			for(int i=1;i<=m;i++)
			{
				scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
				y[i]=x[i]-y[i]+1,c[x[i]]=c[y[i]]=1;
			}
			for(int i=1;i<=n;i++) if(c[i]) a[++cnt]=i,id[i]=cnt;
			for(int i=1;i<=m;i++) v[id[x[i]]].push_back(MP(id[y[i]],z[i]));
			for(int i=0;i<=cnt;i++) for(int j=0;j<=cnt;j++) f[i][j]=-inf;
			f[0][0]=0;
			for(int i=1;i<=cnt;i++)
			{
				if(a[i]-a[i-1]>1) for(int j=1;j<i;j++)
					f[i-1][0]=max(f[i-1][0],f[i-1][j]);
				for(int j=0;j<i;j++)
				{
					f[i][0]=max(f[i][0],f[i-1][j]);
					f[i][j+1]=max(f[i][j+1],f[i-1][j]-(!j?d:(d*(a[i]-a[i-1]))));
				}
				for(int j=0;j<=cnt+1;j++) F[j]=0;
				for(pii j:v[i]) F[j.fi]+=j.se;
				for(int j=cnt;j>=1;j--) F[j]+=F[j+1];
				for(int j=1;j<=i;j++)
				{
					if(a[i]-a[i-j+1]+1>k) f[i][j]=-inf;
					else f[i][j]+=F[i-j+1];
				}
			}
			int ans=0;
			for(int i=0;i<=cnt;i++) ans=max(ans,f[cnt][i]);
			printf("%lld\n",ans);
			for(int i=1;i<=cnt;i++) v[i].clear();
		}
	}
}
namespace C
{
	int n,m,k,d;
	void main()
	{
		while(T--)
		{
			int ans=0;
			scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
			while(m--)
			{
				int x,y,z;
				scanf("%lld%lld%lld",&x,&y,&z);
				if(y>k) continue;
				ans+=max(z-y*d,0ll);
			}
			printf("%lld\n",ans);
		}
	}
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&o,&T);
	if(o<=9) A::main(),exit(0);
	if(o<=11) B::main(),exit(0);
	if(o<=18) C::main(),exit(0);
	return 0;
}