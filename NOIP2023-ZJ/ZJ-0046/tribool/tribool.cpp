#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
int C,t,n,m;
int x,y,ans;
int sta[MAXN],v[MAXN];
char op;
struct edge{
	int to,nxt;
}e[MAXN<<1];
int head[MAXN],tot;
void link(int x,int y)
{
	e[++tot].nxt=head[x];
	head[x]=tot;
	e[tot].to=y;
}
int fa[MAXN];
bool c[MAXN],ret,flag[MAXN],vis[MAXN],fg[MAXN];
int fd(int x)
{
	return fa[x]==x?x:fa[x]=fd(fa[x]);
}
void lk(int x,int y)
{
	x=fd(x);y=fd(y);
	if(x!=y) fa[x]=y;
}
void bfs(int x,int col)
{
	if(flag[x]) ret=1;
	c[x]=col;
	vis[x]=1;
	for(int i=head[x];i;i=e[i].nxt)
	{
		if(!vis[e[i].to]) bfs(e[i].to,col^1);
		else
		{
			if(c[e[i].to]==c[x]) ret=1;
		}
	}
}
void md(int x)
{
	fg[x]=1;
	vis[x]=0;
	for(int i=head[x];i;i=e[i].nxt)
		if(vis[e[i].to]) md(e[i].to);
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&C,&t);
	while(t--)
	{
		tot=0;
		memset(head,0,sizeof(head));
		memset(sta,0,sizeof(sta));
		memset(v,0,sizeof(v));
		memset(fg,0,sizeof(fg));
		memset(flag,0,sizeof(flag));
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			sta[i]=1,v[i]=i;
		for(int i=1;i<=m;i++)
		{
			scanf(" %c",&op);
			if(op=='+')
			{
				scanf("%d%d",&x,&y);
				if(sta[y]==0)
				{
					sta[x]=sta[y];
					v[x]=v[y];
				}
				else
				{
					sta[x]=sta[y];
					v[x]=v[y];
				}
			}
			else if(op=='-')
			{
				scanf("%d%d",&x,&y);
				if(sta[y]==0)
				{
					sta[x]=sta[y];
					v[x]=v[y];
				}
				else
				{
					sta[x]=3-sta[y];
					v[x]=v[y];
				}
			}
			else
			{
				scanf("%d",&x);
				sta[x]=0;
				if(op=='U') v[x]=1;
				else v[x]=0;
			}
		}
		for(int i=1;i<=n;i++)
			fa[i<<1]=i<<1,
			fa[i<<1|1]=i<<1|1;
		for(int i=1;i<=n;i++)
		{
			if(sta[i]==1)
			{
				lk(i<<1,v[i]<<1);
				lk(i<<1|1,v[i]<<1|1);
			}
			if(sta[i]==2)
			{
				lk(i<<1,v[i]<<1|1);
				lk(i<<1|1,v[i]<<1);
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(!sta[i])
			{
				if(v[i])
					flag[fd(i<<1)]=1,
					flag[fd(i<<1|1)]=1;
			}
			if(fd(i<<1)==fd(i<<1|1))
			{
				flag[fd(i<<1)]=1;
				flag[fd(i<<1|1)]=1;
			}
		}
		for(int i=1;i<=n;i++)
			if(fd(i<<1)!=fd(i<<1|1))
				link(fd(i<<1),fd(i<<1|1)),
				link(fd(i<<1|1),fd(i<<1));
		for(int i=2;i<=n*2+1;i++)
		{
			if(fd(i)!=i) continue;
			if(!vis[i])
			{
				ret=0;
				bfs(i,0);
				if(ret) md(i);
			}
		}
		ans=0;
		for(int i=1;i<=n;i++)
			if(fg[fd(i<<1)]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}