#include<bits/stdc++.h>
using namespace std;
const int N=100009;
typedef pair<int,int> Pii;
#define FT first
#define SD second
#define PB push_back 
#define MP make_pair 
int c,t,n,m,ans;
vector<Pii> e[N];
queue<int> q;
bool vis[N],viss[N];
int vl[N];
int vll[N];
char v[4];
struct P{
	int flg;//1tong -1fan
	int val;//1T -1F 0U
	int num;
}p[N];
void dfs1(int x)
{
	for(Pii i:e[x])
	{
		if(vll[i.FT]) continue;
		if(i.SD) vll[i.FT]=-vll[x];
		else vll[i.FT]=vll[x];
		dfs1(i.FT);
	}
}
bool dfs2(int x)
{
	bool as=1;
	for(Pii i:e[x])
	{
		if(viss[i.FT])
		{
			if(i.SD==1)
			{
				if(vll[x]==vll[i.FT]) return 0;
			}
			else
			{
				if(vll[x]!=vll[i.FT]) return 0;
			}
			continue;
		}
		viss[i.FT]=1;
		as=dfs2(i.FT);
		if(!as) return 0; 
	}
	return 1;
}
int dfs3(int x)
{
	int sz=1;
	for(Pii i:e[x])
	{
		if(vis[i.FT]) continue;
		vis[i.FT]=1;
		sz+=dfs3(i.FT);
	}
	return sz;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		ans=0;
		memset(vis,0,sizeof(vis));
		memset(viss,0,sizeof(viss));
		memset(vl,0,sizeof(vl));
		memset(vll,0,sizeof(vll));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) p[i]=P{1,0,i};
		for(int i=1,x,y;i<=m;i++)
		{
			scanf("%s",v);
			if(v[0]=='T')
			{
				scanf("%d",&x);
				p[x].flg=0,p[x].val=1;
			}
			else if(v[0]=='F')
			{
				scanf("%d",&x);
				p[x].flg=0,p[x].val=-1;
			}
			else if(v[0]=='U')
			{
				scanf("%d",&x);
				p[x].flg=0,p[x].val=0;
			}
			else if(v[0]=='+')
			{
				scanf("%d%d",&x,&y);
				p[x]=p[y];
			}
			else if(v[0]=='-')
			{
				scanf("%d%d",&x,&y);
				p[x].flg=-p[y].flg;
				p[x].val=-p[y].val;
				p[x].num=p[y].num;
			}
			
		}
	
		for(int i=1;i<=n;i++)
		{
			if(p[i].flg)
			{
				e[p[i].num].PB(MP(i,p[i].flg==-1));
				e[i].PB(MP(p[i].num,p[i].flg==-1));
			}
			else 
			{
				vl[i]=p[i].val;
				if(vl[i]==0) ans++;
				vis[i]=1;
				q.push(i);
			}
		}
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(Pii i:e[u])
			{
				if(vis[i.FT]) continue;
				vis[i.FT]=1;
				if(i.SD) vl[i.FT]=-vl[u];
				else vl[i.FT]=vl[u];
				if(vl[i.FT]==0) ans++;
				q.push(i.FT);
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				vll[i]=1,dfs1(i),viss[i]=1;
				if(dfs2(i))
				{
					vis[i]=1,dfs3(i);
				}
				else vis[i]=1,ans+=dfs3(i);
			} 
		}
		printf("%d\n",ans);
	
		for(int i=1;i<=n;i++) e[i].clear();
	}
}