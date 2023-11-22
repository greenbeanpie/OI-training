#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m,k,d;
int x,y,v;
struct point
{
	int l,r,val;
}a[100001];
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==1||c==2||c==3||c==4)
	{
		int pb[30],p;
		struct node
		{
			int dy,en;
		}jl[30];
		while(t--)
		{
			int nans=0;
			for(int i=1;i<=n;i++)jl[i].dy=jl[i].en=0;
			scanf("%d%d%d%d",&n,&m,&k,&d);
			for(int i=1;i<=m;i++)
			{
				scanf("%d",&p);
				scanf("%d%d",&jl[p].dy,&jl[p].en);
			}
			for(int i=0;i<(1<<n);i++)
			{
				for(int j=1;j<=n;j++)
				{
					if((i>>(j-1))&1)pb[j]=1;
					else pb[j]=0;
				}
				int s=0,ans=0;
				for(int j=1;j<=n;j++)
				{
					if(pb[j])s++,ans-=d;
					else s=0;
					if(s>k)break;
					if(jl[j].dy<=s)ans+=jl[j].en;
				}
				nans=max(nans,ans);
			}
			printf("%d\n",nans);
		}
	}
	else
	{
		while(t--)
		{
			int cnt=0,ans=0;
			scanf("%d%d%d%d",&n,&m,&k,&d);
			for(int i=1;i<=m;i++)
			{
				scanf("%d%d%d",&x,&y,&v);
				if(y>k)continue;
				a[++cnt].l=x-y+1;
				a[cnt].r=x;
				a[cnt].val=v-y;
			}
			for(int i=1;i<=cnt;i++)
			{
				int nmax=0;
				for(int j=i-1;j>=1;j--)
					if(a[j].r+1<a[i].l&&a[j].val>nmax)nmax=a[j].val;
				a[i].val+=nmax;
				if(nmax>ans)ans=nmax;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
