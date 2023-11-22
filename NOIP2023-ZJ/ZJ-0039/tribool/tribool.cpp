#include<bits/stdc++.h>
using namespace std;

constexpr int maxn=100010;

int x[maxn],tp[maxn];
bool vis[maxn];

void dfs(int i)
{
	if(vis[i])
	{
		int u=i,v=0;
		do
		{
			if(tp[u]==4) v^=1;
			u=x[u];
		}while(u!=i);
		if(v) tp[i]=2;
		else tp[i]=0;
		return;
	}
	vis[i]=true;
	if(tp[x[i]]>2) dfs(x[i]);
	if(tp[i]==3) tp[i]=tp[x[i]];
	else if(tp[x[i]]==2) tp[i]=2;
	else tp[i]=tp[x[i]]^1;
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--)
	{
		int n,m,i,j,ans=0;
		char v;
		cin>>n>>m;
		for(i=1;i<=n;i++) x[i]=i,tp[i]=3,vis[i]=false;
		while(m--)
		{
			cin>>v>>i;
			if(v=='+')
			{
				cin>>j;
				x[i]=x[j];
				tp[i]=tp[j];
			}
			else if(v=='-')
			{
				cin>>j;
				if(tp[j]<2) tp[i]=tp[j]^1;
				else if(tp[j]==2) tp[i]=2;
				else x[i]=x[j],tp[i]=7-tp[j];
			}
			else if(v=='F')
			{
				tp[i]=0;
			}
			else if(v=='T')
			{
				tp[i]=1;
			}
			else
			{
				tp[i]=2;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(tp[i]>2) dfs(i);
			if(tp[i]==2) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
