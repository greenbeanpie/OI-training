#include<bits/stdc++.h>
using namespace std;
const int NUM=100005;
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c-'0');
		c=getchar();
	}
	return x*f;
}
int t,n,m,a[NUM][2],num,head[NUM],val[NUM];
int cnt,top,stk[NUM],dfn[NUM],low[NUM],co,c[NUM],cntc[NUM];
bool vis[NUM],in_stk[NUM];
struct edge
{
	int next,to,flag;
}e[NUM<<2];
void add_edge(int from,int to,int dis)
{
	e[++num].next=head[from];
	e[num].to=to,e[num].flag=dis;
	head[from]=num;
}
void dfs(int u)
{
	if(vis[u]) return;
	vis[u]=true;
	int v;
	for(int i=head[u];i;i=e[i].next)
	{
		v=e[i].to;
		val[v]=val[u]*e[i].flag;
		dfs(v);
	}
}
void tarjan(int u)
{
	int v;
	stk[++top]=u;
	in_stk[u]=true;
	dfn[u]=low[u]=++cnt;
	for(int i=head[u];i;i=e[i].next)
	{
		v=e[i].to;
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else
			if(in_stk[v])
				low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		cntc[++co]=0;
		while(stk[top]!=u)
		{
			in_stk[stk[top]]=false;
			c[stk[top]]=co;
			top--;
		}
		in_stk[stk[top]]=false;
		c[stk[top]]=co;
		top--;
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	char opt;
	int x,y,v;
	read(),t=read();
	while(t--)
	{
		n=read(),m=read();
		for(int i=1;i<=n;i++)
			a[i][0]=i,a[i][1]=0;
		for(int i=1;i<=m;i++)
		{
			cin>>opt;
			if(opt=='+'||opt=='-')
			{
				x=read(),y=read();
				if(opt=='+') a[x][0]=a[y][0],a[x][1]=a[y][1];
				else a[x][0]=a[y][0],a[x][1]=1-a[y][1];
			}
			else
			{
				x=read();
				if(opt=='U')
					a[x][0]=-1;
				else
				{
					a[x][0]=0;
					if(opt=='T') a[x][1]=1;
					else a[x][1]=0;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i][1]==1) a[i][1]=-1;
			else a[i][1]=1;
		}
		num=top=cnt=co=0;
		for(int i=1;i<=n;i++)
			head[i]=dfn[i]=low[i]=0,vis[i]=in_stk[i]=false;
		for(int i=1;i<=n;i++)
		{
			if(a[i][0]>0)
			{
				if(a[i][0]==i&&a[i][1]==-1) val[i]=0;
				else val[i]=-1000,add_edge(a[i][0],i,a[i][1]);
			}
			if(a[i][0]==-1) val[i]=0;
			if(a[i][0]==0&&a[i][1]==-1) val[i]=1;
			if(a[i][0]==0&&a[i][1]==1) val[i]=-1;
		}
		for(int i=1;i<=n;i++)
			if(!dfn[i]) tarjan(i);
		for(int i=1;i<=n;i++)
		{
			for(int j=head[i];j;j=e[j].next)
			{
				v=e[j].to;
				if(c[i]!=c[v]) continue;
				if(e[j].flag==-1) cntc[c[i]]++;
			}
		}
		for(int i=1;i<=n;i++)
			if(cntc[c[i]]%2==1) val[i]=0;
		for(int i=1;i<=n;i++)
			if(val[i]!=-1000) dfs(i);
		int ans=0;
		for(int i=1;i<=n;i++)
			if(val[i]==0) ans++;
		printf("%d\n",ans);
	}
}