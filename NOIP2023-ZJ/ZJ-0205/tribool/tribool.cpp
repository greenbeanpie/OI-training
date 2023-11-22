#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5,INF=0x3f3f3f3f;
int ans=INF,n,m,c,T;
int now[N],v[N],fa[N];
char op[N];
int x[N],y[N];
bool vis[N];
void ck()
{
	int res=0,temp;
	for(int i=1;i<=n;i++)
	{
		now[i]=v[i];
		if(v[i]==2) res++;
	}
	for(int i=1;i<=m;i++)
	{
		if(op[i]=='F')
		{
			now[x[i]]=0;
		}
		else if(op[i]=='T')
		{
			now[x[i]]=1;
		}
		else if(op[i]=='U')
			now[x[i]]=2;
		else if(op[i]=='+')
		{
			now[x[i]]=now[y[i]];
		}
		else
		{
			if(now[y[i]]==2) temp=now[y[i]];
			else temp=!now[y[i]]; 
			now[x[i]]=temp;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(now[i]!=v[i]) return;
	}
	ans=min(ans,res);
}
void dfs(int x)
{
	if(x==n+1)
	{
		ck();
		return;
	}
	for(int i=0;i<3;i++)
	{
		v[x]=i,dfs(x+1);
	}
}
int Dfs(int x)
{
	if(now[x]) return now[x];
	if(vis[x]) return now[x];
	vis[x]=1;
	if(fa[x]) now[x]=Dfs(fa[x]);
	return now[x];
}
inline void solve()
{
	ans=INF;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		cin>>op[i];
		if(op[i]=='T'||op[i]=='F'||op[i]=='U')
			scanf("%d",&x[i]);
		else scanf("%d%d",&x[i],&y[i]);
	}
	if(c<=2)
	{
		dfs(1);
	}
	else
	{
		ans=0;
		memset(now,0,sizeof(now));
		memset(fa,0,sizeof(fa));
		for(int i=1;i<=m;i++)
		{
			if(op[i]=='+') 
			{
				now[x[i]]=now[y[i]];
				fa[x[i]]=y[i];
			}
			else if(op[i]=='F')
			{
				now[x[i]]=0;
			}
			else if(op[i]=='T')
			{
				now[x[i]]=1;
			}
			else now[x[i]]=2;
		}
//		memset(vis,0,sizeof(vis));
//		for(int i=1;i<=n;i++) Dfs(i);
		for(int i=1;i<=n;i++)
		{
			if(now[i]==2)
				ans++;
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--) solve();
	return 0;
}
