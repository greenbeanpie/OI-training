#include<bits/stdc++.h>

using namespace std;

struct Node
{
	long long xx,yy,vv;
};

long long c,t;
long long n,m,k,d;
long long maxn=0;
Node a[100010];
long long b[100100];

void dfs(long long x,long long s)
{
	if (x>n)
	{
		for (long long i=1;i<=n;i++)
		{
			if (b[a[i].xx]>=a[i].yy) s+=a[i].vv;
		}
		
		maxn=max(maxn,s);
		return ;
	}
	
	for (long long i=1;i<=2;i++)
	{
		if (i==1LL) 
		{
			b[x]=b[x-1]+1;
			s-=d;
		}
		else b[x]=0;
		if (b[x]>k) 
		{
			b[x]=0;
			s+=d;
		}
		
		dfs(x+1,s);
		b[x]=0;
	}
	
	return ;
}

int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	
	scanf("%lld%lld",&c,&t);
	
	if (c<=2LL)
	{
		for (long long l=1;l<=t;l++)
		{
			maxn=0LL;
			scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
			for (long long i=1;i<=m;i++)
			{
				scanf("%lld%lld%lld",&a[i].xx,&a[i].yy,&a[i].vv);
			}
			
			dfs(1LL,0LL);
			printf("%lld",maxn);
		}
		
		return 0;
	}
	else
	{
		long long s;
		for (long long l=1;l<=t;l++)
		{
			maxn=0LL;
			s=0LL;
			scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
			for (long long i=1;i<=m;i++)
			{
				scanf("%lld%lld%lld",&a[i].xx,&a[i].yy,&a[i].vv);
			}
			
			for (long long i=1;i<=n;i++)
			{
				b[i]=b[i-1]+1;
				s-=d;
				if (b[i]>k) 
				{
					b[i]=0;
					s+=d;
				}
			}
			
			for (long long i=1;i<=n;i++)
			{
				if (b[a[i].xx]>=a[i].yy) s+=a[i].vv;
			}
			
			printf("%lld\n",max(maxn,s));
		}
	}
	
	return 0;
}