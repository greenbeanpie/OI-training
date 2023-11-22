#include<iostream>
#include<cstdio>
using namespace std;
const int N=2e5+10;
int T;
int n,m;
int a[N];
int fa[N];
int get(int x)
{
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void merge(int x,int y)
{
	x=get(x),y=get(y);
	if(x!=y) fa[x]=y;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&T,&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=2*n+3;i++) fa[i]=i;
		for(int i=1;i<=n;i++) a[i]=i;
		for(int i=1;i<=m;i++)
		{
			int x,y;
			getchar();
			char c=getchar();
			if(c=='T') scanf("%d",&x),a[x]=2*n+1;
			if(c=='F') scanf("%d",&x),a[x]=2*n+2;
			if(c=='U') scanf("%d",&x),a[x]=2*n+3;
			if(c=='+') scanf("%d%d",&x,&y),a[x]=a[y];
			if(c=='-')
			{
				scanf("%d%d",&x,&y);
				if(a[y]==2*n+1) a[x]=2*n+2;
				else if(a[y]==2*n+2) a[x]=2*n+1;
				else if(a[y]==2*n+3) a[x]=2*n+3;
				else if(a[y]<=n) a[x]=a[y]+n;
				else a[x]=a[y]-n;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==2*n+1) merge(i,2*n+1),merge(i+n,2*n+2);
			else if(a[i]==2*n+2) merge(i,2*n+2),merge(i+n,2*n+1);
			else if(a[i]==2*n+3) merge(i,2*n+3),merge(i+n,2*n+3);
			else if(a[i]<=n) merge(i,a[i]),merge(i+n,a[i]+n);
			else merge(i,a[i]),merge(i+n,a[i]-n);
		}
		int ans=0;
		for(int i=1;i<=n;i++) ans+=(get(i)==get(i+n));
		printf("%d\n",ans);
	}
	return 0;
}