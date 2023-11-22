#include<bits/stdc++.h>
using namespace std;
#define int long long/*
4 6 6 0
8 4 12 2 7 10
3 6 11 1 9 5*/
int c;
namespace subtask1
{
	const int N=5e5+5;
	int n,m,q,a[N],b[N],cnt,ans[N],aa[N],bb[N];
	void doit(int *x,int *y,int xlen,int ylen)
	{
		int now=1,last=0;
		for(int i=1;i<=xlen;i++)
		{
			if(x[i]>last)
			{
				last=x[i];
				for(int j=now;j<=ylen;j++)
				{
					if(x[i]>y[j]) now=j;
					else break;
				}
			}
			else
			{
				last=x[i];
				for(int j=now;j>=1;j--)
				{
					if(x[i]<=y[j]) now=j-1;
					else break;
				}
			}
			//cout<<now<<endl;
			if(now==0)
			{
				ans[++cnt]=0;
				return;
			}
		}
		if(now>=ylen) ans[++cnt]=1;
		else ans[++cnt]=0;
	}
	void reset()
	{
		for(int i=1;i<=n;i++) a[i]=aa[i];
		for(int i=1;i<=m;i++) b[i]=bb[i];
	}
	void work()
	{
		//cout<<"!";
		if(a[1]>b[1]) doit(a,b,n,m);
		else if(a[1]==b[1]) ans[++cnt]=0;
		else doit(b,a,m,n);
	}
	void solve()
	{
		scanf("%lld%lld%lld",&n,&m,&q);
		//cout<<n<<m<<q;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]),aa[i]=a[i];
		for(int i=1;i<=m;i++) scanf("%lld",&b[i]),bb[i]=b[i];
		work();
		for(int i=1,ka,kb,p,v;i<=q;i++)
		{
			scanf("%lld%lld",&ka,&kb);
			for(int j=1;j<=ka;j++)
			{
				scanf("%lld%lld",&p,&v);
				a[p]=v;
			}
			for(int j=1;j<=kb;j++)
			{
				scanf("%lld%lld",&p,&v);
				b[p]=v;
			}
			work();
			reset();
		}
		for(int i=1;i<=cnt;i++)
		{
			printf("%lld",ans[i]);
		}
	}
}
signed main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%lld",&c);
	subtask1::solve();
}
