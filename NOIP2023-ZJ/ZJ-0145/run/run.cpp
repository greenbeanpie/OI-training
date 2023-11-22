#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l,r;
	long long v;
}a[100005];
bool cmp(node x,node y)
{
	if(x.r!=y.r)
	{
		return x.r<y.r;
	}
	return x.l>y.l;
}
int c,t,n,m,k;
long long d;
long long f[1005][1005];
long long f2[100005];
int read()
{
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))
	{
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
int main ()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read();t=read();
	while(t--)
	{
		n=read();m=read();k=read();d=read();
		for(int i=1;i<=m;i++)
		{
			a[i].r=read();a[i].l=read();a[i].v=read();
			a[i].l=a[i].r-a[i].l+1;
		}
		sort(a+1,a+m+1,cmp);
		if(c<=9)
		{
			int now=0;
			for(int i=1;i<=n;i++)
			{
				while((now<=m)&&(a[now].r<i))
				{
					now++;
				}
				f[i][0]=0;
				for(int j=0;j<=k;j++)
				{
					f[i][0]=max(f[i][0],f[i-1][j]);
				}
				long long s=0;
				for(int j=1;j<=k;j++)
				{
					while((now<=m)&&(a[now].r==i)&&(a[now].r-a[now].l+1<=j))
					{
						s+=a[now].v;
						now++;
					}
					f[i][j]=f[i-1][j-1]-d+s;
				}
			}
			long long ans=0;
			for(int i=0;i<=k;i++)
			{
				ans=max(ans,f[n][i]);
			}
			printf("%lld\n",ans);
			continue;
		}
		if((c>=17)&&(c<=18))
		{
			long long ans=0;
			for(int i=1;i<=m;i++)
			{
				if(a[i].r-a[i].l+1>k)
				{
					continue;
				}
				if(a[i].v-d*(a[i].r-a[i].l+1)<=0)
				{
					continue;
				}
				ans+=a[i].v-d*(a[i].r-a[i].l+1);
			}
			printf("%lld\n",ans);
			continue;
		}
		long long ans=0;
		for(int i=1;i<=m;i++)
		{
			int l1=a[i].l,r1=a[i].r,p=i-1;
			long long s=a[i].v;
			for(int j=i;j>=1;j--)
			{
				if(r1-l1+1>k)
				{
					break;
				}
				while((p>0)&&(a[p].r>=l1-1))
				{
					p--;
				}
				f2[i]=max(f2[i],f2[p]+s-d*(r1-l1+1));
				if(p==j-1)
				{
					break;
				}
				l1=min(l1,a[j-1].l);
				s+=a[j-1].v;
			}
			ans=max(ans,f2[i]);
		}
		printf("%lld\n",ans);
	}
}