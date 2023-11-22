#include<bits/stdc++.h>
#define F(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
using namespace std;
const int N=5e5+5;
int tot=1,C,T,n,m,f,x,y,pre[N],vet[N],nxt[N],head[N],vis[N],col[N],ans[N];
vector<int>v;char ch;
inline void add(int u,int v)
{
	//cout<<u<<' '<<v<<endl;
	vet[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
inline void dfs(int u,int fa,int col)
{
	vis[u]=1;
	for (int i=head[u];i;i=nxt[i])
	{
		int v=vet[i];
		if (v==fa)continue;
		if (!vis[v])dfs(v,u,col^1);
	}
}
inline void dfsu(int u,int fa,int col)
{
	ans[u]=vis[u]=1;
	for (int i=head[u];i;i=nxt[i])
	{
		int v=vet[i];
		if (v==fa)continue;
		if (!vis[v])dfsu(v,u,col);
	}
}
inline void dfsc(int u,int fa,int Col)
{
	vis[u]=1;col[u]=Col;v.push_back(u);
	for (int i=head[u];i;i=nxt[i])
	{
		int v=vet[i];
		if (v==fa)continue;
		if (vis[v])
		{
			if (col[v]!=(Col^1))f=0;
		}else
			dfsc(v,u,Col^1);
	}
}
inline int trans(int x)
{
	if (x<=n)return -x;
	if (x==n+1)return n+2;
	if (x==n+2)return n+1;
	return n+3;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;while (T--)
	{
		cin>>n>>m;F(i,1,n)pre[i]=i;
		tot=1;F(i,1,2*n+3)head[i]=0,vis[i]=0,ans[i]=0,col[i]=0;
		F(i,1,m)
		{
			cin>>ch>>x;
			if (ch=='T')pre[x]=n+1;else
			if (ch=='F')pre[x]=n+2;else
			if (ch=='U')pre[x]=n+3;else
			if (ch=='+'){cin>>y;pre[x]=pre[y];}else
				{cin>>y;pre[x]=trans(pre[y]);}
		}
		F(i,1,n)
		{
			add(i,i+n);add(i+n,i);
			if (pre[i]==i)continue;
			if (pre[i]<0)add(i,-pre[i]),add(-pre[i],i);else
				add(i,n+pre[i]),add(n+pre[i],i);
		}
		F(i,1,2)dfs(2*n+i,0,i&1);
		dfsu(2*n+3,0,2);
		F(i,1,n)if (!vis[i])
		{
			f=1;v.clear();dfsc(i,0,1);
			if (f)continue;
			for (int j:v)ans[j]=1;
		}
		int cnt=0;F(i,1,n)cnt+=ans[i];
		cout<<cnt<<'\n';
	}
	return 0;
}
