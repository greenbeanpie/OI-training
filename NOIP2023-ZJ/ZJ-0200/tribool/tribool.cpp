#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m;

struct X{
	int f,v;
}x[100005];

int head[100005],cnt;
struct T{
	int next,v,w;
}a[100005];

void add(int u,int v,int w)
{
	a[++cnt]={head[u],v,w};
	head[u]=cnt;
}

int tb[100005];

void dfs(int x)
{
	for(int i=head[x];i;i=a[i].next)
	{
		tb[a[i].v]=tb[x]*a[i].w;
		dfs(a[i].v);
	}
}

int ans;

bool dfs1(int st,int x)
{
//	cerr<<"dfs1:ok st="<<st<<",x="<<x<<endl;
	for(int i=head[x];i;i=a[i].next)
	{
		if(a[i].v==st)
			if(tb[a[i].v]!=(tb[x]*a[i].w))
				return true;
		if(tb[a[i].v]==2)
		{
			tb[a[i].v]=tb[x]*a[i].w;
			if(dfs1(st,a[i].v))
				return true;
		}
	}
	return false;
}

void dfs2(int x)
{
//	cerr<<"dfs1=2:ok x="<<x<<endl;
	for(int i=head[x];i;i=a[i].next)
		if(tb[a[i].v]!=0)
		{
			tb[a[i].v]=0;
			dfs2(a[i].v);
		}
}

int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		ans=cnt=0;
		tb[n+1]=1,head[n+1]=0;
		for(int i=1;i<=n;i++)
			x[i].f=0,x[i].v=i,tb[i]=2,head[i]=0;
		char v;
		int in,jn;
//		cerr<<"ok"<<endl;
		for(int i=1;i<=m;i++)
		{
			cin>>v;
			cin>>in;
			if(v=='T')
				x[in].f=1,x[in].v=1;
			if(v=='F')
				x[in].f=1,x[in].v=-1;
			if(v=='U')
				x[in].f=1,x[in].v=0;
			if(v=='+')
			{
				cin>>jn;
				x[in].f=x[jn].f,x[in].v=x[jn].v;
			}
			if(v=='-')
			{
				cin>>jn;
				x[in].f=x[jn].f,x[in].v=-x[jn].v;
			}
		}
//		cerr<<"ok"<<endl;
		for(int i=1;i<=n;i++)
		{
			if(x[i].f==0)
			{
				if(x[i].v>0)
					add(x[i].v,i,1);
				else
					add(-x[i].v,i,-1);
			}
			else
			{
				add(n+1,i,x[i].v);
			}
		}
//		cerr<<"ok"<<endl;
		dfs(n+1);
//		cerr<<"ok"<<endl;
		for(int i=1;i<=n;i++)
		{
			if(tb[i]==2)
			{
				tb[i]=3;
				if(dfs1(i,i))
				{
					tb[i]=0;
					dfs2(i);
				}
//				cerr<<"ok "<<i<<endl;
			}
		}
//		cerr<<"ok"<<endl;
		for(int i=1;i<=n;i++)
			if(tb[i]==0)
				ans++;
		cout<<ans<<endl;
	}
	return 0;
}