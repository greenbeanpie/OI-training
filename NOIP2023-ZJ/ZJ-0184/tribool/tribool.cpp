#include <bits/stdc++.h>
#define OK
using namespace std;
namespace Tribool
{
#define Node(x) ((x)<0?-(x)+n+1:(x))
	int C,T,n,m,ans,a[200010],fa[200010];
	char v[15];
	int find (int x)
	{
		if (fa[x]==x) return x;
		return fa[x]=find(fa[x]);
//		int y=x;
//		while (fa[x]!=x) x=fa[x];
//		return fa[y]=x; // 写成下面的会超时，写成上面的会厌氧？？！！ 
// 想改系统的时候已经太晚了，所以还是用了 Windows，希望 NOI Linux 上能过 
	}
	void merge (int u,int v)
	{
		u=find(u); v=find(v);
//		printf ("%d %d %d %d\n",u,fa[u],v,fa[v]);
		if (u!=v) fa[v]=u;
	}
	int main ()
	{
#ifdef OK
		freopen ("tribool.in","r",stdin);
		freopen ("tribool.out","w",stdout);
#endif
		scanf ("%d%d",&C,&T);
		while (T--)
		{
			scanf ("%d%d",&n,&m);
			for (int i=0;i<=2*n+2;i++)
				a[i]=fa[i]=i;
			ans=0;
//			for (int i=1;i<=n;i++)
//				printf ("a[%d]=%d\n",i,a[i]);
			while (m--)
			{
				int x,y;
				scanf ("%s%d",v,&x);
				if (v[0]=='T') a[x]=n+1;
				else if (v[0]=='F') a[x]=2*n+2;
				else if (v[0]=='U') a[x]=0;
				else if (v[0]=='+')
				{
					scanf ("%d",&y);
					a[x]=a[y];
				}
				else if (v[0]=='-')
				{
					scanf ("%d",&y);
					if (!a[y]) a[x]=0;
					else a[x]=(a[y]+n)%(2*n+2)+1;
				}
			}
			for (int i=1;i<=n;i++)
			{
				merge (i,a[i]);
				merge (i+n+1,a[i]?(a[i]+n)%(2*n+2)+1:0);
			}
			for (int i=1;i<=n;i++)
				if (find(i)==find(i+n+1)) ans++;
			printf ("%d\n",ans);
		}
#ifndef OK
		printf ("\n%d\n",clock());
#endif
		exit(0);
	}
#undef Node
}
int main ()
{
	Tribool::main();
	return 0;
}
/*
2 1
10 10
- 9 8
- 8 6
- 6 5
- 5 4
- 4 3
+ 3 9
- 1 2
+ 2 7
+ 7 10
- 10 1
*/
