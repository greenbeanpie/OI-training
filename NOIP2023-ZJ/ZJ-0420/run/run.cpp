#include"cstdio"
#include"cstring"
#define ll long long
inline ll max(ll x,ll y){return x>y?x:y;}
inline ll min(ll x,ll y){return x<y?x:y;}
ll f[1010][1010];
ll s[1010][1010];
int c,t,n,m,l,r,k;
ll v,d;
ll ans;
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		memset(f,-0x3f,sizeof(f));
		memset(s,0,sizeof(s));
		scanf("%d%d%d%lld",&n,&m,&k,&d);ans=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%lld",&l,&r,&v);
			s[l][r]+=v;
		}
		f[0][0]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=k;j++)f[i][0]=max(f[i][0],f[i-1][j]);
			for(int j=1;j<=k;j++)
			s[i][j]+=s[i][j-1],
			f[i][j]=f[i-1][j-1]-d+s[i][j];
		}
		for(int j=0;j<=k;j++)ans=max(f[n][j],ans);
		printf("%lld\n",ans);
	}
	return 0;
}
