#include<bits/stdc++.h>
using namespace std;

int C,T;
int n,m,ans;
int x[100010];

vector<int> son[100010];
vector<int> so[100010];
int dfn[100010],low[100010],st[100010],tim,head;
int col[100010],nu[100010],siz[100010],cnt;
bool vis[100010];

/*void tarjan(int u)
{
	int v;
	dfn[u]=low[u]=++tim;
	st[++head]=u;
	for(vector<int>::iterator it=son[u].begin();it!=son[u].end();it++)
	{
		v=*it;
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else
			if(!col[v])
				low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		col[u]=++cnt;
		if(x[u]>100000)
			nu[cnt]=x[u];
		siz[cnt]++;
		while(st[head]!=u)
		{
			col[st[head]]=cnt;
			if(x[st[head]]>100000)
				nu[cnt]=x[st[head]];
			siz[cnt]++;
			head--;
		}
		head--;
	}
}*/
int main()
{ 
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>C>>T;
	char c;
	while(T--)
	{
		ans=0;
		memset(col,0,sizeof(col));
		memset(nu,0,sizeof(nu));
		memset(siz,0,sizeof(siz));
		memset(dfn,0,sizeof(col));
		memset(low,0,sizeof(nu));
		head=0;
		cnt=0;
		x[100001]=100001;
		x[100002]=100002;
		x[100003]=100003;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			x[i]=i,son[i].clear();
		for(int i=1,a,b;i<=m;i++)
		{
			cin>>c>>a;
			if(c!='+' && c!='-')
			{
				if(c=='T')
					x[a]=100001;
				if(c=='F')
					x[a]=100002;
				if(c=='U')
					x[a]=100003;
			}
			else
			{
				cin>>b;
				if(c=='+')
				{
					x[a]=b;
					son[b].push_back(a);
				}
				if(c=='-')
				{
					x[a]=-b;
					son[b].push_back(a);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(x[i]==100003)
				ans++;
		}
		//cout<<endl;
		//for(int i=1;i<=cnt;i++)
		//	if(nu[i]==100003)
		//		ans++;
		cout<<ans<<endl;
	}
			
}
   