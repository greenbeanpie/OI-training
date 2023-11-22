#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;
int fa[MAXN];
int find(int x)
{
	if(abs(fa[x])==x||fa[x]==MAXN||fa[x]==-MAXN||fa[x]==0)
		return fa[x];
	else
	return fa[x]=(fa[x]>0?1:-1)*find(abs(fa[x]));
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		int n,m,ans=0;
		scanf("%d%d",&n,&m);
		for(int i(1);i<=n;++i)
		fa[i]=i;
		while(m--)
		{
			char op;
			int u,v;
			cin>>op;
			if(op=='+')
			{
				scanf("%d%d",&u,&v);
				fa[u]=fa[find(v)];
				find(u);
			}
			if(op=='-')
			{
				scanf("%d%d",&u,&v);
				fa[u]=-fa[find(v)];
				find(u);
			}
			if(op=='T')
			{
				scanf("%d",&u);
				fa[u]=MAXN;
			}
			if(op=='F')
			{
				scanf("%d",&u);
				fa[u]=-1*MAXN;
			}
			if(op=='U')
			{
				scanf("%d",&u);
				fa[u]=0;
			}
		}
		for(int i(1);i<=n;++i)
			if(fa[find(i)]==0)
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}
